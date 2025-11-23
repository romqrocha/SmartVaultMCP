using System.Runtime.CompilerServices;
using System.Text;
using Nodsoft.MoltenObsidian;
using Nodsoft.MoltenObsidian.Vault;

namespace MCPServer.Services;

public interface IVaultService
{
    public string GetVaultName();

    public IReadOnlyDictionary<string, IVaultNote> GetAllNotes();

    public IReadOnlyDictionary<string, IVaultFile> GetAllFiles();

    public Task<string> GetNoteFrontmatterAsync(string notePath);

    public Task<string> GetNoteContentAsync(string notePath);
}

public class DefaultVaultService(IVault vault) : IVaultService
{
    private readonly IVault vault = vault;

    public IReadOnlyDictionary<string, IVaultFile> GetAllFiles()
    {
        return vault.Files;
    }

    public IReadOnlyDictionary<string, IVaultNote> GetAllNotes()
    {
        return vault.Notes;
    }

    public string GetVaultName()
    {
        return vault.Name;
    }

    public async Task<string> GetNoteFrontmatterAsync(string notePath)
    {
        ValueTask<Stream>? streamTask = vault.GetFile(notePath)?.OpenReadAsync();

        if (streamTask is null)
        {
            return $"Error: no file found at the given path {notePath}";
        }

        Stream stream = await streamTask.Value;
        StreamReader streamReader = new(stream);
        string streamContents = await streamReader.ReadToEndAsync();

        var fancyMarkdown = new ObsidianText(streamContents);

        Dictionary<string, object> frontmatter = fancyMarkdown.Frontmatter;
        return DictionaryToString(frontmatter);
    }

    public async Task<string> GetNoteContentAsync(string notePath)
    {
        ValueTask<Stream>? streamTask = vault.GetFile(notePath)?.OpenReadAsync();

        if (streamTask is null)
        {
            return $"Error: no file found at the given path {notePath}";
        }

        Stream stream = await streamTask.Value;
        StreamReader streamReader = new(stream);
        string streamContents = await streamReader.ReadToEndAsync();

        var fancyMarkdown = new ObsidianText(streamContents);
        return fancyMarkdown.Text;
    }

    /// <summary>
    /// helper method for converting a dictionary to a readable string.
    /// </summary>
    /// <typeparam name="TValue">The dictionary's TValue type.</typeparam>
    /// <param name="dict">The dictionary to be converted.</param>
    /// <returns>A human readable string.</returns>
    public static string DictionaryToString<TValue>(Dictionary<string, TValue> dict)
    {
        var result = new StringBuilder("{ ");
        foreach (var kvp in dict)
        {
            result.Append($"{kvp.Key} -> {kvp.Value}, ");
        }
        if (dict.Count > 0)
        {
            result.Length -= 2;
        }
        result.Append(" }");
        return result.ToString();
    }

    public static string ListVaultFiles(IReadOnlyDictionary<string, IVaultFile> dict)
    {
        var result = new StringBuilder();
        foreach (var kvp in dict)
        {
            result.Append($"File: {kvp.Value.Name} -> Vault Path: {kvp.Key}\n");
        }
        return result.ToString();
    }

    public static string ListVaultFiles(IReadOnlyDictionary<string, IVaultNote> dict)
    {
        var result = new StringBuilder();
        foreach (var kvp in dict)
        {
            result.Append($"Note name: {kvp.Value.NoteName} -> Vault path: {kvp.Key}\n");
        }
        return result.ToString();
    }
}
