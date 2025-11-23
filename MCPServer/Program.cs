using MCPServer.Services;

var AllowMyOrigins = "_allowMyOrigins";

var builder = WebApplication.CreateBuilder(args);

builder.Services.AddMcpServer().WithHttpTransport().WithToolsFromAssembly();

builder.Services.AddMoltenObsidianInMemoryVault("TestVault");

builder.Services.AddCors(options =>
{
    options.AddPolicy(
        name: AllowMyOrigins,
        policy =>
        {
            policy.WithOrigins("https://smartvaultmcp.romqrocha.ca", "http://localhost:2110");
        }
    );
});

builder.Services.AddTransient<IFileService, DefaultFileService>();

var app = builder.Build();

app.UseCors(AllowMyOrigins);

app.MapMcp();

app.Run();
