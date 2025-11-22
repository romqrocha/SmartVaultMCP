using Nodsoft.MoltenObsidian.Vault;

namespace MCPServer.Services;

public interface IFileService
{
    Task<string> ReadAsync(string path);

    public string Test();
}

public class DefaultFileService(IVault vault) : IFileService
{
    private readonly IVault vault = vault;

    public Task<string> ReadAsync(string path)
    {
        FileInfo fileInfo = new(path);
        return File.ReadAllTextAsync(fileInfo.FullName);
    }

    public string Test()
    {
        return vault.Name;
    }
}
