using MCPServer.Services;

var builder = WebApplication.CreateBuilder(args);

builder.Services.AddMcpServer().WithHttpTransport().WithToolsFromAssembly();

var vault = builder.Configuration["VaultDirectory"];
builder.Services.AddMoltenObsidianFileSystemVault(
    new DirectoryInfo(
        vault ?? throw new NullReferenceException("VaultDirectory is null in configuration")
    )
);

builder.Services.AddTransient<IVaultService, DefaultVaultService>();

var app = builder.Build();

app.MapMcp();

app.Run();
