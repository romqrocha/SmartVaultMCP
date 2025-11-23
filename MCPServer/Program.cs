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
            policy
                .WithOrigins("http://smartvaultmcp.romqrocha.ca", "http://localhost:2110")
                .SetIsOriginAllowedToAllowWildcardSubdomains();
        }
    );
});

builder.Services.AddTransient<IFileService, DefaultFileService>();

var app = builder.Build();

app.UseCors(AllowMyOrigins);

app.MapMcp();

app.Run();
