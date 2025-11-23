## `bit_cast` - C++20

`std::bit_cast` copies the bits and bytes of the source object (its representation) directly into a new object of the target type. It's a standards-compliant way to do type punning. If you find yourself writing `*reinterpret_cast<SomeType*>(&x)`, you probably should use `std::bit_cast<SomeType>(x)` instead.

`std::bit_cast` is declared in `<bit>`. The objects must be the same size and be trivially copyable. If you can't yet use C++20, use `memcpy` to copy the source value into a variable of the desired type.