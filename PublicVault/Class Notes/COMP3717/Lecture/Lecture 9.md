# Architecture
- UI State holder is typically a class
- UI Logic: How things are being displayed to the user
## Business Logic State holder
- Contains business logic and states
> [!quote] Business logic: Rules and requirements for data before it is processed by the data layer
- Checks for use-cases of data types and validates accordingly
# Layers
- Two basic types:
	1. UI
		- UI Elements(Composables)
		- State Holders(UI and Business)
	2. Data
		- Data Sources
			- DataStore
				- Small Jetpack library for storing small and simple databases, like a settings or preference 
		- Repositories
## Data Layer
- Contains:
	- Data Sources:
		- Files
		- Databases
	- Repository:
		- A class that provides the logic to communicate with the data source
	- Data Models:
		- The types and way you store data, like a class
# Room
- A SQLite database
- Data entities represent tables in your database
- Each instance represents a row
![[DB_TableExample.png]]

# Singletons in Kotlin
- Literally just `object` rather than `class`