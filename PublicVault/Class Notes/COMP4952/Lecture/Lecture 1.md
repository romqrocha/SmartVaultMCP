3 types of .net webapps
- Razor
- MVC
- Blazor
# Razor
- uses a webserver, like node, called Kestrel
- can make with a template using `dotnet new razor -o [projectName]`
- can run projects using `dotnet run`
- In the View you have C# code blocks, called Islands
- Has a live edit viewer, like nodemon
	`dotnet watch`
- Can move data between code(`cshtmlcs`) sections and front-end(`cshtml`) using a `ViewData` object. This uses the View-Model system 
- You can nest pages by adding them to folders; e.g. `./Temperature/C2F.cshtml`
- Send data from the model to the view using a `[BindProperty]` tag on attributes in the back, and an `asp-for=[propertyName]`
- Push data from the view to the model with `ViewData["VarName"] = foo`. 
	- You can then access the data in the model with `@ViewData["VarName"]`
# Azure
- Resource Group is a collection of items related to a project
# GitIgnore
`dotnet new gitignore`
- Add appsettings.Development.json


- ? Where did he get the github actions template from?
# MVC 
- `--use-local-db` lets you build your own db; uses a sqlite server by default
- `dotnet new mvc --auth individual --use-local-db -o AspCoreMVC`
- 3 components
	- Controller
	- Model
		- All the raw data
	- View (basically the HMTL page)
		- Uses the Model to fill in the variables
- Controller receives request and figures out what to do
- Gives the data to a model, which is rendered by a view, which is sent back as a response
- Each controller has a method, which represents the pages under it
	- e.g. if you have `localhost/home/index`, the `HomeController.Index()` method is being called
	- `home` is the controller, `Index()` is called the Action Item
	- You can see the logic for generating URL paths in the `Program.cs` file, under `app.MapControllerRoute()` method
	- For every Action Method, there must be a view in the View folder
`[Authorize]` is used to require a logged in user
`[AllowAnonymous]` allows for exclusions to `[Authorize]`
