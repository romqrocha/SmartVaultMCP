# Functors
- By overloading the () operator, you can make class objects callable, which lets you make first-class citizens
# Lambda
- A bit of a messy syntax is C++
```C++
[](type args){//lambda body}
```
# Multithreading
- Multithreaded functions have return type `ThreadData`
- Start thread with ```
```C++
async(launch::async, asyncFunctionHere, argForAsyncFunction)
//returns a 'future' object
```
- don't forget to store the return in a variable
- use the `future.get()` member  to wait for the thread to complete
```C++
auto futureResult1 = async( launch::async, startFibonacci, 48 );

auto futureResult2 = async( launch::async, startFibonacci, 47 );
// wait for results from each thread
ThreadData result1 = futureResult1.get();
ThreadData result2 = futureResult2.get();
```
