---
Class: COMP2522
Created: '[[2024 11 14]]'
tags: 
Reviewed: false
---
- Primary class must extend Application
- Must override start(Stage primaryStage)
```java
public class MyApp extends Application
{
	@Override
	public void start(final Stage primaryStage)
	{
		...
	}
}
```

-  Main is used only to call the app class start() method. Make sure you pass args
```java
public static void main(final String[] args)
{
	Application.launch(args); // or 'launch(args)'
}
```
- Application is the parent
	- Stage is inside Application
		- Scene is inside Stage
- Scenes are added to Stages by calling .setScene()
- A scene requires a layout, which is all the containers(Vbox, Hbox, button, fields) within the scene, the width, and the height.
- addAll can be used to add multiple stages to a scene in one instruction
```java
public class MyApp extends Application
{
	@Override
	public void start(final Stage primaryStage)
	{
		int width = 300;
		int height = 200;
		Vbox root = new VBox();
		Button btn = new Button("Click me!");
		Label label = new Label("Hello, JavaFX!");
		root.getChildre.addAll(label, btn);

		Scene scene = new Scene(root, width, height)
		primaryStage.setScene(scene);
		primaryStage.setTitle("Window title!");

		primaryStage.show();
	}
}
```
## Controls
- Button is used to trigger actions via lambdas
- Label is used to display text information
- TextField is used to allow users to input a single line of text
	- You can get the text in the text field with .getText();
```java
	Label greeting = new Label("Enter your name:");  
	TextField textField = new TextField();  
	Button button = new Button("Click Me");  
	button.setOnAction(e -> greeting.setText("Hello, " + textField.getText() + "!"));
```

## Application Thread
- JavaFX has a main thread for all UI updates
- All code that updates the UI runs on this thread.
- If you need to sagely run tasks off the UI thread, you can use Task and Service
	- Task is used for one-time operations
	- Service is used for all tasks that need to run multiple times or be restarted.
- They have methods setOnSucceeded, setOnFailed, setOnCancelled
	- These let you specify actions to take when those things occur.
```
import javafx.concurrent;
...
	Task<V> // V is the return type of the computation
	
```
