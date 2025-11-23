---
Class: "[[COMP3717]]"
Created: "[[2025 01 08]]"
tags:
  - lecture
  - week/1
Reviewed: false
---
# Kotlin
- declare functions with `fun name(){}`
- declare immutable variables with `val`
  ```kotlin
  val msg: String = "Good morning!"
```
- declare mutable variables with var
  ```kotlin
  var foo: String = "Please dont change me!"
	```
- constants need to be known at compile time, so they need to be global.
	- Must also be val
	- Cannot be inside a function
  ```kotlin
  const val FOO = 0
  fun main(){
	  
  }
	```
- Place variables in strings with var
  ```kotlin
  val msg: String = "hello"
  val name: String = "Corey"
  println("$msg $name")
	```
- Access kotlin standard library with kotlin.(lib)
  ```kotlin
  kotlin.math.sqrt()
	```
- Unit is equivalent to "Void" in Java. It means "Returns nothing"