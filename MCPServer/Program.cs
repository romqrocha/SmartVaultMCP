using MCPServer.Services;

var builder = WebApplication.CreateBuilder(args);

builder.Services.AddMcpServer().WithHttpTransport().WithToolsFromAssembly();

builder.Services.AddMoltenObsidianInMemoryVault("TestVault");

builder.Services.AddTransient<IFileService, DefaultFileService>();

var app = builder.Build();

app.MapMcp();

app.Run();
