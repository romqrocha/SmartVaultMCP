---
Created: 2024-02-22T11:42
Class: Comp1510
Reviewed: false
tags:
  - Java
---
- Code is not considered done until it has been tested
- Test units first, then integrate with other units
    - A unit in java is a **CLASS**
- Testing is used to find problems, debugging is used to find causes
- To test, write a test driver class using a testing framework, e.g. JUnit, TestNG.

```JavaScript
import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;
```

  

- From low to high
    - Unit Test - usually done by individual developers
    - Integration test
    - System Test
    - Acceptance Test - Show a client your system is useable. DO NOT WANT TO FIND BUGS HERE
- Higher level are primarily ‘functional’, and focus on end-to-end interactions and issues.
- Tests are formal procedures, and should have defined inputs and required outputs
    - You should be able to repeat the same test and get the same results
- They are all designed, documented, reviewed, and debugged.
    - Errors could occur in a test format as easily as in the system being tested, so you need to test your test.

## Unit Testing

- Every line of code needs to be tested
- Every possible branch in logic needs to be tested
    - We need to test all possible True and False for Ifs, and Whiles that skip or run, every iteration of conditionals, and every mix of them.
- Units externally observable behavior should be tested.
    - Is the Output correct for all Inputs?
    - Does it handle error cases correctly?
        - e.g. what if I pass a null reference?
        - what if I pass a negative/zero to a function that is intended to handle positive ints?

### Frameworks

- Tests should be independent of each other, so we don’t have cascading failures.
- Should detect and report errors on a test-by-test basis

## Test Class

- Public with zero-argument constructor
- Each test method runs on a new instance, so we cant share instance variables across methods

## Test functions

- need the @test annotation
- are public
- no arguments
- return void
- Uses assert methods from org.junit.jupiter.Assertations class
    - usually named assert_class_**comparison**(arg1, arg2, “error message”);
- If you have common setup steps, you can put it into an initialization method annotated with @BeforeEach
- Common cleanup steps can be put in a cleanup code with @AfterEach
- Also has @BeforeAll and @AfterAll that run before and after ALL tests, rather than each test.

## Test Runners

- Allow us to customize how tests are run