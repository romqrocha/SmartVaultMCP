// Bob Langelaan
// Date: Jan 23, 2022

How references might be implemented under the hood

I titled this post "How references might be implemented under the hood" because the C++ standard does not state how it must be implemented so therefore C++ compiler writers may implement references how they see fit.  But I will describe below one method by which at least some compilers implement references, which is as a const pointer.

If the compiler implements references as a const pointers, the compiler will automatically insert the \* (the dereference) operator in front of the const pointer when it is referenced. And anywhere a reference is initialized, the & (address of operator) is inserted in front of the object being assigned to the reference.

This means, for example, if we have the following code:

int i;
int & iRef = i;
iRef = 10;

the compiler would translate this code into:

int i;
int \* const  iRef = &i; // note that a const pointer, just as a reference, must be initialized when it is defined
                               // note that '&' is inserted in front of 'i' by the compiler
\*iRef = 10; // the compiler automatically inserts \* in front of iRef when it is referenced

This also explains why when we use the address operator on a reference it returns the address of the object it is referencing.  If you recall, the \* (the dereference) operator and the & (address of) operator are inverses of each other. So this means that if we have:

int i;
int \* iPtr = &i;
cout << iPtr << \*&iPtr << &\*iPtr; // will output the same address 3 times since \*& and &\* cancel each other out

Therefore, if we return to the iRef example above, when we do:

cout << &iRef; // output the address of iRef

The compiler translates this to:

cout << &\*iRef; // actually outputs the address stored in iRef

and since &\* cancel each other out, the result is we output the contents of iRef, which is the address of i.

Another example: If we have the following code:

int & func(int & jRef)
{
    return jRef;
}

int main()
{
   int i;
   int & iRef = func(i);

   ...

the compiler would translate this into:

int \* const func(int \* const jRef)
{
    return &\*jRef;
}

int main()
{
   int i;
   int \* const iRef = &\*func(&i);
   ...

Some explanation is required for the above example.  Note that that 3 different "int \* const" values are created.  The 3 are:

1) the "int \* const" parameter called jRef created upon entry to func()
2) the "int \* const" returned by func()
3) the "int \* const" called iRef created in main()

In all 3 cases, the object assigned to the newly created const pointer is converted to a pointer through a & (address of) operator being automatically inserted in front of each of the objects being assigned to the const pointer.  In the first two of the cases listed above, the '&' cannot be shown in the actual assignment (it is an implicit assignment), so therefore I am showing the '&' in front of the value that will be assigned to the const pointer.  Note that in two of the cases (2nd and 3rd in list above) we end up with the two operators '&' and '\*' side by side, which we know will effectively cause them to cancel each other out.

If we remove the cancelled out operators (which an optimizing compiler would likely also do), we then have:

int \* const func(int \* const jRef)
{
    return jRef;
}

int main()
{
   int i;
   int \* const iRef = func(&i);
   ...

I hope this post is clear and helps you to better understand the differences and similarities between references and pointers.