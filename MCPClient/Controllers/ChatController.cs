using System.Text;
using Microsoft.AspNetCore.Mvc;
using Microsoft.Extensions.AI;
using ModelContextProtocol.Client;

namespace MCPClient.Controllers;

[ApiController]
[Route("[controller]")]
public class ChatController(
    ILogger<ChatController> logger,
    IChatClient chatClient,
    IConfiguration configuration
) : ControllerBase
{
    private readonly ILogger<ChatController> _logger = logger;
    private readonly IChatClient _chatClient = chatClient;

    private readonly IConfiguration? _configuration = configuration;

    [HttpPost(Name = "Chat")]
    public async Task<string> Chat([FromBody] string message)
    {
        // Create MCP client connecting to our MCP server
        var mcpClient = await McpClient.CreateAsync(
            new HttpClientTransport(
                new()
                {
                    Name = "SmartVault MCP Server",
                    Endpoint = new Uri(
                        _configuration?["AI:MCPServiceUri"]
                            ?? throw new InvalidOperationException(
                                "MCPServiceUri is not configured"
                            )
                    ),
                }
            )
        );

        // Get available tools from the MCP server
        var tools = await mcpClient.ListToolsAsync();
        string toolNames = "";
        foreach (var tool in tools)
        {
            toolNames += tool.Name + '\n';
        }
        Console.WriteLine(toolNames);

        // Set up the chat messages
        var messages = new List<ChatMessage>
        {
            new(ChatRole.System, "You are a helpful assistant."),
            new(ChatRole.User, message),
        };

        // Get streaming response and collect updates
        List<ChatResponseUpdate> updates = [];
        StringBuilder result = new();

        await foreach (
            var update in _chatClient.GetStreamingResponseAsync(
                messages,
                new() { Tools = [.. tools] }
            )
        )
        {
            result.Append(update);
            updates.Add(update);
        }

        // Add the assistant's responses to the message history
        messages.AddMessages(updates);
        return result.ToString();
    }
}
