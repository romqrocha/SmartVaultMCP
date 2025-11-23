---
Class: COMP2522
---
# Docs
Include JavaDoc comments for 
- classes 
	- @author
	- @version
- all non-private methods and constructors 
	- @param
	- @return
	- @throws
# Name
- String: First
	- [x] Instance Variable ✅ 2024-09-09
	- [x] Constructor Argument ✅ 2024-09-09
	- [x] Accessor Method ✅ 2024-09-09
- String: Last
	- [x] Instance Variable ✅ 2024-09-09
	- [x] Constructor Argument ✅ 2024-09-09
	- [x] Accessor Method ✅ 2024-09-09
## Constructor
- must throw an IllegalArgumentException when its arguments are
	- [x] null ✅ 2024-09-09
	- [x] blank ✅ 2024-09-09
	- [x] contains "admin" ✅ 2024-09-09
	- [x] more than 45 characters) ✅ 2024-09-09
## Methods
- [x] getFirstName() ✅ 2024-09-09
- [x] getLastName() ✅ 2024-09-09
- [x] getInitials() ✅ 2024-09-09
	- would return T.W for tigER wooDS
- [x] getFullName() ✅ 2024-09-09
	- would return Tiger Woods for tigER wooDS
- [x] getReverseName() ✅ 2024-09-09
	- would return SDoow REgit for tigER wooDS

# Date
**NO IMPORTS**
- int: year
	- [x] Instance Variable ✅ 2024-09-09
	- [x] Constructor Argument ✅ 2024-09-09
	- [x] Accessor Method ✅ 2024-09-09
- int: month
	- [x] Instance Variable ✅ 2024-09-09
	- [x] Constructor Argument ✅ 2024-09-09
	- [x] Accessor Method ✅ 2024-09-09
- int: day
	- [x] Instance Variable ✅ 2024-09-09
	- [x] Constructor Argument ✅ 2024-09-09
	- [x] Accessor Method ✅ 2024-09-09
- [x] final static int CURRENT_YEAR ✅ 2024-09-09

## Methods
- [x] getDay() ✅ 2024-09-09
- [x] getMonth() ✅ 2024-09-09
- [x] getYear() ✅ 2024-09-09
- [x] getYyyyMmDd() ✅ 2024-09-09
	- returns dates in format like "2024-09-30"
- [x] getDayOfWeek ✅ 2024-09-09


# Person
- Name: name
	- [x] Instance Variable ✅ 2024-09-09
	- [x] Constructor Argument ✅ 2024-09-09
	- [x] Accessor Method ✅ 2024-09-09
- Date: dateBorn
	- [x] Instance Variable ✅ 2024-09-09
	- [x] Constructor Argument ✅ 2024-09-09
	- [x] Accessor Method ✅ 2024-09-09
- Date: dateDied
	- can be null
	- [x] Instance Variable ✅ 2024-09-09
	- [x] Constructor Argument ✅ 2024-09-09
	- [x] Accessor Method ✅ 2024-09-09
## Methods
- [x] getDetails() ✅ 2024-09-09
- [x] isAlive() ✅ 2024-09-09

# BankClient(Extends Person)
- String: ClientID
	- [x] **5 digits** ✅ 2024-09-09
	- [x] Instance Variable ✅ 2024-09-09
	- [x] Constructor Argument ✅ 2024-09-09
	- [x] Accessor Method ✅ 2024-09-09
- Date: signupDate
	- [x] Instance Variable ✅ 2024-09-09
	- [x] Constructor Argument ✅ 2024-09-09
	- [x] Accessor Method ✅ 2024-09-09
## Methods
- [x] getDetails() ✅ 2024-09-09

# BankAccount
- BankClient: client
	- [x] Instance Variable ✅ 2024-09-09
	- [x] Constructor Argument ✅ 2024-09-09
	- [x] Accessor Method ✅ 2024-09-09
- double: balanceUsd
	- [x] Instance Variable ✅ 2024-09-09
	- [x] Constructor Argument ✅ 2024-09-09
	- [x] Accessor Method ✅ 2024-09-09
- int: pin
	- [x] Instance Variable ✅ 2024-09-09
	- [x] Constructor Argument ✅ 2024-09-09
	- [x] Accessor Method ✅ 2024-09-09
- String: accountNumber
	- [x] **6 or 7 length** ✅ 2024-09-09
	- [x] Instance Variable ✅ 2024-09-09
	- [x] Constructor Argument ✅ 2024-09-09
	- [x] Accessor Method ✅ 2024-09-09
- Date: accountOpenedDate
	- [x] Instance Variable ✅ 2024-09-09
	- [x] Constructor Argument ✅ 2024-09-09
	- [x] Accessor Method ✅ 2024-09-09
- Date: accountClosedDate
	- [x] Instance Variable ✅ 2024-09-09
	- [x] Constructor Argument ✅ 2024-09-09
	- [x] Accessor Method ✅ 2024-09-09
## Methods
- [x] deposit() ✅ 2024-09-09
- [x] withdraw(amountUsd) ✅ 2024-09-09
- [x] withdraw(amountUsd, pinToMatch) ✅ 2024-09-09
- [x] getDetails() ✅ 2024-09-09

# Review

## Name
- Move throws to new line
- Move || and && to end of line rather than new line
- declare/initialize strippedName on own line
	- separate strippedName and toLower to different lines
- toTitleCase
	- set args to final
	- separate initialize and declare to different lines
## Date
- validateDay
	- set variables for function calls earlier