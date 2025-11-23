# Icons
- Lots of default icons in `Icons.Default`
```kotlin
Icon(  
    Icons.Default.Close,  
    contentDescription = null  
)
```
- You can make an icon into a button with the `IconButton`
```kotlin
IconButton(  
    onClick = {  
        removeCardCallback(cartoon)  
})  
{  
    Icon(  
        Icons.Default.Close,  
        contentDescription = null  
    )  
}
```
# Adding dependencies
- Gradle Scripts > build.gradle.kts (Module :app)
- Scroll to dependencies block
# Navigation
- use `androidx.navigation.compose.rememberNavController`
	- Remembers what's on the backstack
		- Literally a stack that gets popped when you push the back button
	- Provides structure when navigating between composables
	- Adds transitions
- 5 big terms:
	1. Navigation Controller
	2. Navigation Host
	3. Navigation Graph
	4. Destinations
	5. Routes
## Navigation Controller
- Allows us to navigate from one destination to another
- "Manages App Navigation within the Nav Host"
## Nav Host
```kotlin
NavHost(navController = navController, startDestination = "home") { }
```
- A container that allows us to swap in/out destinations.
## Routes
- Every destination has a corresponding route(its ID, which is a string)
- Inside the `composable` you put the UI you want
```kotlin
NavHost(navController = navController, startDestination = "home") {  
    composable("home")
    {
	    Home()
    }  
}
```
# Scaffold
- Provides the basic layout structure for your screen
- required arg of padding value
	- used in top level composable
```kotlin
Scaffold(  
    bottomBar = {  
        MyBottomNav(navController)  
    }  
) { padding ->  
    NavHost(  
        navController = navController,  
        startDestination = "home",  
        modifier = Modifier.padding(padding)  
    ) { 
    ...
    }
}
```
 