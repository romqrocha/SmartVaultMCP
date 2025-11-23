# Composables
Main composables:
- Box
	- Useful for main composable to cover the full screen: `Box(modifier=Modifier.safeDrawingPadding())`
- Row
- Column
## Card
- Like a box with extra stuff
- Has its own colors
- Also has a column built-in
# Composable Lifecycle
- When Jetpack Compose executes a composable, its enters the *Composition*
![[Kotlin_Composition.png]]
- Two ways to enter the *Composition*:
	1. The first time you run the Composable through *Initial Composition*
	2. When the **state** read by your Composable changes, it goes through **recomposition**
- Need to wrap values that might change and effect the UI in `mutableStateOf`
	`private var num = mutableStateOf(0)`
	- Our Composable know to recompose when a mutable state changes
	- You can put the mutable states within the composable that uses them, but you need to wrap it in remember
	```kotlin
	@Composable  
	fun Counter(){  
	    val num = remember {  
	        mutableIntStateOf(0)  
	    }
		...
		Text("${num.intValue}")
	}
	```
	- We can also use Delegates instead of having to use the dot operator
	```kotlin
	@Composable  
	fun Counter(){  
	    var num by remember {  
	        mutableIntStateOf(0)  
	    }  
	    Column(  
	        horizontalAlignment = Alignment.CenterHorizontally)  
	    {  
	        Text("$num")  
	        Button(onClick={  
	            num++  
	        }) {  
	            Text("Count")  
	        }  
	    }
	}
	```
	- Meant to be used with **primitives** and **immutable objects**, not collections.
		- You won't recompose when adding/removing from a collection
		- use `MutableStateListOf` when working with collections
		- Lists have a `foo.toMutableStateList()`
# Images
- Images go in the res/drawable folder
- a Painter lets us draw a resource from the resources folder to the screen
- `painterResource()`
	- Access resources with `R` class(R for Resources!)
	- You can then use dot notation to get the folder and files you want`painterResources(R.drawable.spongebob)
# Spacer
- Literally just adds space
`Spacer(modifier=Modifier.width(100.dp))`

# Resources
## Values
### Strings.xml
- All your strings in one localized place.
- Can access with `stringResource(R.string.foo)`
- Can also access Arrays from within Strings with `stringArrayResource(R.array.bar)`

# LazyColumn
- Effectively turn a column into a list
- Enables scrolling
- each element needs to be wrapped in an `item{}`
- Can also use `items{}` if you're working with an array
# LazyRow
- Same as lazy row