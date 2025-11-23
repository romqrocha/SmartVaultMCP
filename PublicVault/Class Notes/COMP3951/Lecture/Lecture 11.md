# Web Development Technologies
- Client-side Technology
	- HTML
	- DHTML
	- XHTML
	- HTML5
	- CSS
	- JS
		- jQuery
		- React
		- Angular
- Server-side Technology
	- [[ASP]](Active Server Pages)
	- [[JSP]](Java Server Pages)
	- [[PHP]](Hypertext Preprocessor)

# ASP
- Server-Side web programming
- popular in late 90's/early 2000's
- Made of static HTML interleaved with [[JS]]
- ASP objects provide services
	- Request
	- Response
	- Server
	- Application
	- Session
- Commonly used [[ADO]](ActiveX Data Objects) to interact with databases
- Manages threads and database connections
- Still used in government organizations
- Limited to Windows hosting
## Pros


# ASP.NET
- The next generation of [[ASP]]
- Still limited to Windows Hosting
- Built on [[.Net Framework]] and [[Internet Information Server|IIS]]
- Uses [[MVC]](Model View Controller)
- Migration from ASP to ASP.NET to ASP.NET Core is not easy
- Two styles to create pages
	- Controls and code in `.aspx` file
		- Like writing raw HTML
	- Controls in `.aspx` file, code in code-behind page
		- Code-behind allows the code to be in a separate file from the design
## Features
- Simple programming model
- Multi-browser support
- XML config
- Can be compiled
- Event-driven
- Separation of code and UI
- [[ASP]] and [[ASPX]] side by side
- Cookieless sessions
## Web Forms
- Programmable web pages
- Drag and dop development
- Server-side controls
## Web Services
- Executing functions on a server
	- Think of it as a parallel to [[DLL]]s, where you load functions from somewhere else
## Model
- Parses and compiles a page into an object that extends `Page`
- new object processes incoming request to the server
- Web controls render HTML to the stream
## Postbacks
- Technique for handling form data in Web Forms
	- Think of it as a callback function
- The form application is a process
- Each user gets a thread
- With ASP, the state of the controls is maintained between postbacks
## Server-side Controls
- Multiple sources
	- Built-in
	- 3rd party
	- User-defined
- Range in complexity
	- Button
	- Text
	- Calendar
	- Datagrid
	- Rotator
	- Validation
- Can be populated with [[Data Binding]]
- Two types:
	- Client-side
	- Server-side
	- Dictates where the code is executed
## Server Control Properties
- Tag attribute tells you what control you're using
`<asp:button> // This will create a button`
- Important property is `runat`, which dictates where the control code is executed
- can be set programmatically, too
```
<asp:button id="buttonText">
buttonText.Text = "foo"
```
- State is maintained in a hidden HTML field, `__VIEWSTATE`
- Can be disabled per-control `EnableViewState="fase"`

# ASP.NET Core
- Has [[MVC]] built in
- Combines ASP.NET MVC and ASP.NET Web API into a single model
- 