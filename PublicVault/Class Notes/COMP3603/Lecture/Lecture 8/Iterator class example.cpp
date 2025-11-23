// This program is an example of creating an Iterator class
//    for a very basic/simple container class.
// Note that the Iterator class is nested inside of the
//    container class.
// The Iterator class is required in order for the client code
//    in main() to use the range based for loop.

//Author: Bob Langelaan
//Date:   July 7rd, 2024

#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T, size_t Size = 20>
class SimpleContainer {
private:
    T data[Size];
    std::size_t count;

public:
    SimpleContainer() 
        : count(0) {}

    // Add elements to the container
    void add(const T& value) {
        if (count < Size) {
            data[count++] = value;
        }
        else {
            throw std::out_of_range("Container is full");
        }
    }

    // Define the iterator class
    class Iterator {
    private:
        T* ptr;  // This pointer will point to an element in
                 //     data array.
                 // NOTE: My solution for the Deque class requires 
                 //       2 additional data members

    public:
        // Ctor for Iterator class
        // NOTE: My ctor for the Iterator class I created for the 
        //       Deque class required 2 additional parameters
        Iterator(T* ptr) 
            : ptr(ptr) {}

        // Overload the indirection operator for the Iterator class
        // This operator is used by the range based for loop
        T& operator*() {
            return *ptr;
        }

        // Overload the pre-increment operator for the Iterator class
        // This operator is used by the range based for loop
        Iterator& operator++() {
            ++ptr;
            return *this;
        }

        // Overload the != operator for the Iterator class
        // This operator is used by the range based for loop
        bool operator!=(const Iterator& other) const {
            return ptr != other.ptr;
        }
    };

    // Methods to get iterators for the beginning and end of the container
    // These methods are also required by the range based for loop
    // Note that these are methods of the container class and therefore have
    //    access to the data members of the container class object which 
    //    is invoked with the method.
    Iterator begin() {
        return Iterator(data); // You need to pass to the Iterator ctor any 
                               //  information about the container class object
                               //  that could be required by the methods of the
                               //  iterator class.
    }

    Iterator end() {
        return Iterator(data + count); // You need to pass to the Iterator ctor any 
                               //  information about the container class object
                               //  that could be required by the methods of the
                               //  iterator class.
    }
};

int main() {
    SimpleContainer<int> container; // create a container object

    container.add(1);
    container.add(2);
    container.add(3);

    // Using range-based for loop with the container
    for (auto& value : container) {
        cout << value << " ";
    }
    cout << endl;

    return 0;
}
