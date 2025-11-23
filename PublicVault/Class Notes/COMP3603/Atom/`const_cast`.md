## `const_cast`

`const_cast` can be used to remove or add `const` to a variable; no other C++ cast is capable of removing it (not even `reinterpret_cast`). It is important to note that modifying a formerly `const` value is only undefined if the original variable is `const`; if you use it to take the `const` off a reference to something that wasn't declared with `const`, it is safe. This can be useful when overloading member functions based on `const`, for instance. It can also be used to add `const` to an object, such as to call a member function overload.

`const_cast` also works similarly on `volatile`, though that's less common.