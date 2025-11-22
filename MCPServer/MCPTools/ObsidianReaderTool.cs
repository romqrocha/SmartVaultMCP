using System.ComponentModel;
using MCPServer.Services;
using ModelContextProtocol.Server;
using Nodsoft.MoltenObsidian.Vault;

namespace MCPServer.MCPTools;

[McpServerToolType]
public class ObsidianReaderTool(IFileService fileService, IVault vault)
{
    /// <summary>
    /// Provides file operations to this MCP server
    /// </summary>
    private readonly IFileService fileService = fileService;

    private readonly IVault vault = vault;

    [McpServerTool, Description("Read the file at the given file path")]
    public string ReadFile(
        [Description("The path to the file that needs to be read.")] string filePath
    )
    {
        Task<string> readTask = fileService.ReadAsync(filePath);

        string fileContents = readTask.GetAwaiter().GetResult();

        return fileContents;
    }

    [McpServerTool, Description("Test this MCP tool")]
    public string Test()
    {
        return fileService.Test();
    }
}
