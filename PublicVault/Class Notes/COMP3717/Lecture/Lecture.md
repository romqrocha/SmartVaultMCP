# #week/6 
## Manifests.xml
- Configs and settings. Don't fuck in here until you know
## Res
- Resources
- Images and etc.

## Logging
```
import android.util.Log
```

# Android Activities
- Building blocks of programs
- Changed from a "Multi-activity architecture" to "single activity architecture"
	- Modern apps have 1 activity - Main
- You would change "activities" when changing screens
- All main UI sits on the activity
### Lifecycle
- 6 main states
	1. `onCreate`
	2. `onStart`
	3. `onPause`
	4. `onResume`
	5. `onStop`
	6. `destroy`
- The states are there to manage resources as we move through states
- Changing from portrait to landscape causes the entire activity lifecycle to happen
#### onCreate
- When it gets created
-  The entry point to the function
- Contains setContent which sets up the initial UI
- All setup logic, like object initialization
- Only called once
#### onStart
- As soon as the activity enters the foreground
	- Literally AS SOON as the ui becomes slightly visible
- Can be called multiple times
#### onResume
- When you're actively using the app
- You're in here 99% of the time
- Something like a notification will **briefly** put you into onPause
#### onPause
- Usually a very brief state
- Either happens when you get a notification or when you're moving to onStop
#### onStop
- Not destroyed
- Memory still allocated and used
- Usually when app is minimized
#### onDestroyed
- When the app is finally closed and memory freed

### onSaveInstanceState
- used to carry the current instance data into a *bundle* so you can recreate the app from that bundle
	- A bundle is literally just a map(key:value pairs) of android data
- Used specially when changing from portrait to landscape
### ComponentActivity
- Gives us "Composable Functions"
	- Part of the Jetpack Compose library
	- Modern GUI platform for mobile
	- Declarative framework
		- React
		- Flutter
- Allows you to make the GUI entirely in Kotlin, in-editor
- You can wrap composables in composables
#### Box
- useful modifier: `Modifer.safeDrawingPadding()`
#### Text
- color
- fontSize
	- uses `20.sp`
	- `int.sp`
	- Fonts use sp
	- everything else uses dp
#### Modifier
- An argument for composables
- Does a lot.
- use `Modifer.foo()`
- these can be chained `Modifier.foo().bar().spam()`

#### Arrangements
- Useful modifiers for relative spacing
	- `Arragement.SpaceBetween`
- **ITS CSS**
- Make sure you use `Modifier.fillMaxWidth()`, `Modifer.fillMaxHeight()`, or `Modifier.fillMaxSize()`
- The alignment and arrangement change depending on column or row
	- Column: `horizontalAlignment`, `verticalArrangement`
	- Row: `verticalAlignment`, `horizontalArrangement`
### Custom Composable
- You cannot put a function with the Composable tag within a function that does **not** have the composable tag
