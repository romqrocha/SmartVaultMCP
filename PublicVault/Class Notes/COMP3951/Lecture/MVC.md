---
aliases:
  - Model-View-Controller
---
- Software architecture and pattern used in software engineering
- Deals with [[Separation of Concerns]]
![[Working-of-MVC-1024x686.png]]
# View
> [!cite] The visual representation of the controller
- The visual stuff
	- buttons
	- text forms
	- keyboard
	- mouse
# Controller
> [!cite] The Controller delegates requests to the appropriate handler and is responsible for input to the Model
- Like an Event Manager
- Handles passing, validating, and converting data from the view to the model and vice-versa
# Model
- The Business Logic
	- Validation
- The Data and the functionality of the data
- In the case of invalid input, informs the [[Controller]] an error occurred and to try again