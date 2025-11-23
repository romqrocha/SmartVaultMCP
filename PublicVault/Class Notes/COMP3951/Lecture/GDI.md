---
Class: COMP3951
---
# GDI
- GDI stands for Graphic Device Interface
- an interface to work with Graphics *Objects* such as painting on windows, forms, controls, etc.
- Windows GDI+ is a **class-based** API for C/C++
# Windows Applications(C/C++ & Win32)
- Code that provides:
	- An entry point to the program (`wWinMain`)
		- Registration of the "[Windows class](https://learn.microsoft.com/en-us/windows/win32/learnwin32/your-first-windows-program#:~:text=WNDCLASS%20wc%20%3D%20%7B%20%7D%3B%0A%0A%20%20%20%20wc.lpfnWndProc%20%20%20%3D%20WindowProc%3B%0A%20%20%20%20wc.hInstance%20%20%20%20%20%3D%20hInstance%3B%0A%20%20%20%20wc.lpszClassName%20%3D%20CLASS_NAME%3B)" (`WNDCLASS`)
			- Has a class name, handler instance, and a pointer to the WindowProc callback (`WindowProc`)
		- Creation of the window (`CreateWindowEx`)
		- Displaying the window (`ShowWindow`)
		- Running the message loop
			- Messages are a way to communicate events occurred
				- Mouse move, keystroke, etc.
			- `WM` is the prefix for Windows Messages - e.g. `WM_DESTROY` is the Windows Message to Destroy the current window
	- A definition for the `WindowProc()` callback function
		- Full function header: `LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)`
		- `HWND` is a Handle for the Window
		- `UINT` is an Unsigned Int that represents the message
		- `WPARAM` and `LPARAM` are the contents of the message
		- Consists of a switch statement where each case is a possible windows message
# Drawing on device context
- A device context is a struct containing information about the drawing attributes of a device
- 4 contexts:
	1. Display(Windows)
	2. Display(Outside)
	3. Printer
	4. Metafile
# Invalidating
- Used to indicate we need to repaint something
- `InvalidateRect` provides a pointer to a rectangle that represents a portion of the windows area to be redrawn
- `InvalidateRegion` can also be used
# Namespaces/Classes/Handlers for Graphics
- Graphics is a sealed class with a private constructor
- You can get a Graphics Object from
	1. A PaintEventArgs
	2. Graphics.CreateGraphics()
	3. Create a Graphics object from any object that inherits from Image
		- Used when you want to alter an existing image
	4. Create a graphics object from a Window Handle
# Exception Handling
- Performed with try-catch-finally
- Can specify type of exception in the catch block
- Finally is useful for cleaning up resources allocated in the try block
- Control is **always** passed to the finally block
# Disposing Unmanaged Resources
- Files, Graphics Objects, and Network Connections are unmanaged, so the GC won't dispose of them for us
- We can dispose of them by:
	- calling the Dispose method or "using" statements
		- defined in `IDisposable`
	- the Finalize method
		- This is what the Garbage Collector invokes before the object is destroyed
		- Should override for a class that uses unmanaged resources to ensure you properly discard any unmanaged resources
		- Should not override this for managed resources
- Dispose has to be explicitly invoked
# Using statement
- Guarantees the object is disposed in the event of an exception
- equivalent to calling dispose in a finally block
- For Async operations, avoid "using" and call `DisposeAsync`
# Dialog Boxes
- Can be predefined or coded
- Predefined:
	- Open
	- Save File
	- Font
	- Color
	- Print
- Two types: 
	1. Modal
		- Doesn't allow the user to switch to another application in the program unless the dialog box is terminated
		- a *system* modal dialog box doesn't allow the user to switch to another window in **any** program
	2. Modeless
		- Allows the user to switch to another window
- Best practice is to code in the form that calls the dialog box and not inside
- Dialog box code should be minimal or non-existent
	- A single function for the entire box that checks all potential buttons that are in the box
```csharp
FormDialog dialog = new FormDialog();  
DialogResult result;  
result = dialog.ShowDialog();  
if (result == DialogResult.Yes)  
{  
	...........  
}  
else if (result == DialogResult.No)  
{  
	............  
}  
else if (result == DialogResult.Cancel)  
{  
return;  
}
```
