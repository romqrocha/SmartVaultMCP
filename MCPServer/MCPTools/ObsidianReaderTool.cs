using System.ComponentModel;
using MCPServer.Services;
using ModelContextProtocol.Server;
using Nodsoft.MoltenObsidian.Vault;

namespace MCPServer.MCPTools;

[McpServerToolType]
public class ObsidianReaderTool(IVaultService vaultService)
{
    /// <summary>
    /// Provides file operations to this MCP server
    /// </summary>
    private readonly IVaultService vaultService = vaultService;

    [McpServerTool, Description("Get the name of the vault used by this MCP server")]
    public string GetVaultName()
    {
        return vaultService.GetVaultName();
    }

    [McpServerTool, Description("Read the frontmatter metadata for the note at the given path")]
    public string ReadNoteFrontmatter(
        [Description("The path to the note that needs to be read.")] string filePath
    )
    {
        Task<string> readTask = vaultService.GetNoteFrontmatterAsync(filePath);

        string fileContents = readTask.GetAwaiter().GetResult();

        return fileContents;
    }

    [McpServerTool, Description("Read the file/note at the given path")]
    public string ReadNoteContents(
        [Description("The path to the file that needs to be read.")] string filePath
    )
    {
        Task<string> readTask = vaultService.GetNoteContentAsync(filePath);

        string fileContents = readTask.GetAwaiter().GetResult();

        return fileContents;
    }

    [McpServerTool, Description("List all files in this vault")]
    public string ListAllVaultFiles()
    {
        IReadOnlyDictionary<string, IVaultFile> files = vaultService.GetAllFiles();

        return DefaultVaultService.ListVaultFiles(files);
    }

    [
        McpServerTool,
        Description(
            "List all notes in this vault, excluding files that aren't notes (don't have a .md extension)"
        )
    ]
    public string ListAllVaultNotes()
    {
        IReadOnlyDictionary<string, IVaultNote> notes = vaultService.GetAllNotes();

        return DefaultVaultService.ListVaultFiles(notes);
    }
}
