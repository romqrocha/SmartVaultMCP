- 3 Main umbrellas of AI:
	- Supervised
	- Unsupervised
	- Reinforcement
# Supervised
- regression uses Data Over Time; finds and predicts trends that change over time
# Swagger
- UI to document how to use APIs
# Token Authentication
- 
# Serverless Functions
- Lambda in AWS
- Azure Functions in Microsoft
- All serverless functions need a trigger
	- Could be an endpoint, or a request, or a timer
- If we want to work in Node, we can get a sandbox with `npm i -g azure-functions-core-tools@4 --unsafe-perm true`
	- We can test if it worked by calling `func --version` in a terminal window
# Blazor
- Single page applications for web developers who don't like JavaScript
- Its literally Microsoft implementing WASM
- WASM can't talk directly to a database, it needs an API in the middle
- Route to page is at the top of the `.razor` file within the `@page` annotation
- `.razor` files are components, so you can add them into other pages by using an HTML annotaiton; eg `<Counter/>`
- You can add C# imports at the top of the page with `@inject`
# Docker
- You can see volumes with `docker volume ls`
- You can see networks with `docker network ls`
- `-rm` tells docker to remove the container as soon as it stops
- `-p [hostPort]:[containerPort]` to allow external access to your container
- You can see all running containers with `docker ps`
- You can run bash inside a container with `docker exec -it [container ID]`
	- Get back out with `exit`
- To see logs use `docker logs [container id]`
- You can copy files from the host machine to the container using `docker cp [filePath] [containerId]:[containerPath]`
## Volumes
- A way to save data between the container and the host machine
- can be mapped with the `-v` flag: e.g. `-v d:\foo:/usr/share/bar` maps the files in `/usr/share/bar` to the files in `d:\foo`
## Image
- What gets pushed to a Registry
- A blueprint for a Container
## Containers
- Akin to a Virtual Machine, but without a Guest OS inside.
	- It just piggy-backs off the Host operating system
	- Instead of a Hypervisor, it uses a Container Engine, but there are basically parallels
## Docker Compose
- Blueprint for each of the services you need to run at once
- Runs all containers as a VLAN, so they can communicate without needing additional ports
	- this allows for minimal ports to be exposed
- Each service is under the `services` header
	- image is the image from dockerhub
	- restart how you want to restart
	- ports are `hostPort:virtualPort`; e.g. `8080:80` means port 8080 on your PC maps to port 80 in the container
	- environment is where you put environment variables for the container
	- volumes is where you map local paths to container paths
		- e.g. `db:/var/lib/mysql` says I want to map the volume, `db`, to the folder in the container `/var/lib/mysql`
- volumes, at a global level are where you can specify the name for the volumes
- you can start a docker instance with compose using `docker compose up`, stop it with `control+c`, and revert the changes with `docker compose down`
	- Note that down doesn't remove the volume
	- You can remove the volume with `docker volume rm [volume ID]`
# Large Language Model (LLM)
- AI Models trained on massive datasets
- Usually specialized to work on natural language tasks
- A model converts a word or a string into a "Vector" datatype
	- A Vector in this case is effectively an array of floats representing the weights of various attributes
- LLMs can be used to take natural language and pass the desired output onto other models, such as Image Generation
- A base LLM will just predict the next token(word) that's expected
- An LLM can have a "temperature" value that tells it how 'creative' or 'personable' it can be; ranges from 0 to 1
- 3 aspects to a prompts
	- System prompt: 
		- Grounds the LLM. 
		- Limits the output
		- "You are a prof at a university of medical science"
	- //TODO: Ask wtf the other 2 aspects are. This is interesting!
# Prompt Engineering
>[!quote] The process of designing and optimizing prompts to deliver consistent and quality output for a given application, objective, and model.
> Build your models for **Consistency** first and foremost!
> Next aim for quality; it's not good if it lies.
- 2 steps
	- design initial prompt for a given model and objective
	- Iteratively refine the prompt to improve quality
- LLMs are [[stochastic]]; you can get a different result every time you use it.
- They can hallucinate; they may produce output that doesn't make sense or is not true.
- They have diverse capabilities
	- Different models are good at different things.
	- The latest model might not be the best, and some models may be cheaper or more efficient.
# C# With AI
- 'Low-Level' Libraries:
	- `dotnet add package OpenAI`
	- `dotnet add package Azure.AI.OpenAI`
- 'High Level' libraries
	- `dotnet add package Microsoft.SemanticKernel`
## Semantic Kernel
- The idea of Semantic Kernel is that it acts as an API between your code and various AI models
- For example, lets you build agents that can call your existing code
- Works for C#, Python, Java
- Uses:
	- Plugins
	- Context Variables
	- Connectors(Memory and Models)
	- Planners(AI Orchestrator)
![[Pasted image 20251028104731.png]]
# Small Language Model (SLM)
- Compact versions of LLM
- Design to be run locally
- Ranges from a few million to ~10 billion parameters
- Designed for efficiency
- Generally more focused on doing 1 thing really well rather than being general purpose.
- Made smaller by:
	- Knowledge Distillation: Sometimes trained on an LLM; a "student-teacher" relationship
	- Pruning: Remove redundant/low-impact parameters
	- Quantization: Reduce numerical precision, saves memory and compute.
	- Architecture changes
- Benefits:
	- Efficiency: Lower latency, energy use
	- Privacy: Data stays on the device
- Examples:
	- Llama3.2
	- Qwen2.5
	- Phi-3.5
# SignalR
- Microsoft implementation of HTML5 WebSockets
	- Abstracts over transports
	- Uses events instead of Task/Async
	- Handles connection management
	- Broadcast to all/target group/target client
- `Hub` is the base class; a high-level pipeline that enable
	- Browser calls a C# method
	- Server calls a JavaScript method
- Negotiates the appropriate transport method based off the server.
- Allows for server-to-client RPC rather than client-to-server RPC
	- You can target:
		- all(yourself included!) (`Clients.All.SomeFunc()`)
		- Yourself (`Clients.Caller.SomeFunc()`)
		- Other connected clients(`Clients.Others.SomeFunc()`)
		- Specific users (`Clients.Users("Foo").SomeFunc()`)
# Dotnet Aspire
- Like Docker Compose - it synchronizes starting up multiple dotnet projects
- `.AppHost` is the startup point; load dependencies and etc.
	- Any app that wants to be orchestrated needs to be referenced in `AppHost`
- `.ServiceDefaults` is for health checks, telemetry, etc.
	- Any app that wants to have telemetry needs to reference `ServiceDefaults`