# Tasks
> [!note] A coroutine wrapped in an object
- Run 1 thread and have concurrency
- Avoid complexity of race conditions and deadlocks
# Coroutines
- Generators generate values; Coroutines generate AND consume values
- instead of next to continue to coroutine call, use `send(val)`
- Effectively, can pause execution and take new values mid-execution.
- Useful for:
	- Exceptions
	- Event loops
	- Multitasking
	- Etc.
# AsyncIO
- Python packaged for writing Asynchronous I/O Bound code
- Usually a task we need to wait on, such as
	- Web requests
	- Database queries
	- File handling
- uses the `await` and `async` keywords
- `await` is used to wait on blocking calls and functions
```python
result = await asyncio.gather(db_call(), db_call())
```
- `async` tells python a block of code can run asynchronously, and may have blocking calls in it
- functions tagged with async are not actually functions, they're coroutines.
	- You need to await them.
- `asyncio.run()` allows you run a coroutines outside of an async block
- `asyncio.gather()` allows you to run multiple coroutines
# Event Loop
- Manages our coroutines to handle the different tasks
- starts every time we call `asyncio.run()`
- When the request is completed, the OS notifies the event loop
- The event loop then triggers a callback