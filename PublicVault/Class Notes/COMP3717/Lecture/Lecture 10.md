# Coroutine
-  A concurrency [[Design Pattern]]
- A small thread
	- But also not a thread
- Several coroutines can all run asynchronously on the same thread
- The core is done with functions with the `suspend` keyword: `suspend fun mySusFunc()`
- When it hits a timeout, the state of the coroutine is saved and the main thread continues
- You can force a suspend with `delay()`
- You can also nest coroutines
- Can cancel coroutines by using `.cancel()`
## Coroutine Builders
- `runBlocking`
	- Special coroutine builder; is blocking
	- Creates scope and context internally
	- Think of it as `thread.sleep` in java
	- Context: Deployed on the current thread
	- Scope: Created automatically
- launch
	- non-blocking
	- Needs a scope and context
	- Inherits from the parent context if wrapped in a runblocking
# Coroutine Context
- How is the coroutine deployed
# Coroutine Scope
-  What is the lifetime of the thread?
- You can make scope with `coroutineScope{}` or `CoroutineScope(Dispatchers.IO).launch`
- `coroutineScope` is blocking; all coroutines inside need to complete before its continued
# Job
- Type of [[Coroutine]]
- Non-blocking
-  Assigning a coroutine to a variable
```kotlin
val job = launch{...}
```
- You can wait for a job to finish by using `.join()`
	- Literally "Join this thread to the jobs thread"
- Returns a `Deferred`
- The body isn't suppose to return anything
# Async
- Like job, but allows a return value
- Non-blocking

# Flow
```kotlin
val flow = flowOf(1, 2, 3, 4)
```
- Like a collection, but lazy
- Initialization doesn't happen until iteration
- Iteration is [[Asynchronous]]
- sequences are synchronous versions of flows
- Have "collectors", which consumes the elements of the flow
	- Like streams from Java, but you can have multiple collectors
	- You can also run other suspend functions within the collect
```kotlin
flow.collect{
	println("printing element in flow: $it")
	delay(500L)
}
```
- Usually you create with the flow function
- This is called a Cold Flow
	- The flow only emits when a collection happens
> [!cite] A Cold Flow is dependent on its collector
```kotlin
val flow = flow{
	emit(1)
	emit(2)
	delay(500L)
	emitAll(flowOf(3, 4))
}
```
- Emissions in a cold flow are not shared
```kotlin
runBlocking {
	flow.collect{
		println("printing element in flow: $it")
	}
	flow.collect{
		println("printing element in flow: $it")
	}
}
```
- A Hot Flow is not dependent on its collections
	- They emit regardless of collection points
	- All collections share emissions
	- Two types: `sharedFlow` and `stateFlow`
	- Also supports "Debouncing"
		- When emissions stop for a certain amount of time, collection begins