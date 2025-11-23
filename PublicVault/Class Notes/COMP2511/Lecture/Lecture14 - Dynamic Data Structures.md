---
Created: 2024-07-11T18:41
Class: COMP2511
Reviewed: false
---
- Requires **Self-Referential Structures**
    - This means all structs within the DDS need a pointer to a struct of the same time

```C
struct node {
	int data;
	struct node *nextPtr;
};
```

- nextPtr is referred to as a _link_
- When working with any dynamic structures, you always need to be considering “what might be the special case?”

## Dynamic Memory Allocation

- New in java creates a Pointer, a reference, on the stack, then creates the new object in the heap
- In C its the same, we’re creating pointers in the stack to point to our struct on the heap
    - instead of new, we use malloc
        - later we’ll learn calloc, and realloc
        - malloc and calloc allocate memory on the heap
        - realloc allows you to change the amount of memory allocated for an array

## Malloc

- malloc allocates X bytes of memory, so we can use the sizeof operator to ensure we get the right amount of memory
- When you allocate with malloc, you need a matching free in your program
- malloc return a pointer of type void
    - Because its of type void, we can assign it to a pointer variable of any type

```C
	newPtr = malloc( sizeof( struct node ) );
```

- evaluates the size of the struct node, and gets that many bytes of memory
- if no memory is available, malloc returns NULL

## Free

- _DEALLOCATES_ memory
- Takes a pointer

```C
free( newPtr );
```

- its a standard to set the pointer to NULL after you free the memory, so that way you dont accidently access data you didnt intend

# Linked Lists

- a set of linear, self-referential structs, called nodes
- each node is connected by a pointer to the next item
- last node is set to NULL
- Use over an array if you dont know how large the list of items will be
- Linked Lists are less efficient than an array, and do not support direct access/indexing
- Arrays also take up their full amount of memory as soon as they’re declared, whereas linked lists dont create new nodes until they’re needed

# Stacks

- Stacks are LAST-IN-FIRST-OUT structure(LIFO)
- Referenced via a pointer to the top element of the stack
- Unlike a linked list, we can only delete and insert at the top of the stack

# Queues

- Queues are FIRST-IN-FIRST-OUT(FIFO)
- Insert/Remove functions are called Enqueue and Dequeue
- both en- and de-queue need access to the head and tail pointers
    - special case: Adding or removing the first item in a queue

# Binary Tree

- A tree is **non-linear**
- Tree nodes contain two or more links
- Binary Trees nodes all contain two links
    - none, one, or both of which can be NULL
- **Root** node is the first node in the tree
- Each link is called a **child**
    - There is a left and right child, based on which subtree they are in
        - the left child tends to have values less than the root
        - the right child tends to have values greater than the root
    - children of a node are called siblings
    - nodes with no children are called **leaf nodes**
- Binary tree functions tend to be **recursive** when written in educational examples
    - Keep in mind this is slower and more expensive

### Traversing a Binary Tree

- Three ways to traverse

1. Pre
    - Process
    - Left Subtree
    - Right Subtree
2. In Order
    - Left
    - Process
    - Right
3. Post Order
    - Left
    - Right
    - Process

- Process just means to run some sort of functionality, ala processing, like printing the value
- This changes the order in which you get values