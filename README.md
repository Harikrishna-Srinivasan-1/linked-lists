---

# Linked List Library

Welcome to the **Linked List Library**! This repository provides a generic implementation of singly linked lists in C++ with additional features for exception handling. This library supports a wide range of operations, making it easy to integrate into your projects.

## Features

- **Singly Linked List Implementation**: Provides a flexible, dynamic linked list with various operations.
- **Exception Handling**: Custom exception classes for better error reporting.
- **Generic and Template-Based**: Supports any data type using C++ templates.

## Table of Contents

- [Installation](#installation)
- [Usage](#usage)
- [API Reference](#api-reference)
- [Examples](#examples)
- [Contributing](#contributing)
- [License](#license)
- [Contact](#contact)

## Installation

To use this library, simply include the header files in your project and ensure you have a C++11 (or later) compliant compiler.

1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/linked-list-library.git
   ```
2. Include the necessary header files in your project:
   ```cpp
   #include "linkedlist.h"
   #include "exception.h"
   ```

## Usage

Below is a brief overview of how to use the library. For more detailed information, please refer to the [API Reference](#api-reference).

### Creating and Using a Linked List

To create and use a singly linked list, you need to include the `singly_linked_list` header and create an instance of the `singly_linked_list` class.

```cpp
#include "singly_linked_list.h"

int main() {
    singly_linked_list<int> list;

    // Add elements
    list.append(1);
    list.append(2);
    list.prepend(0);

    // Insert elements
    list.insert(1, 5);

    // Remove an element
    list.remove(2);

    // Get size of the list
    size_t size = list.size();

    // Find elements
    int index = list.find(5);

    // Print list
    list.show();
    
    return 0;
}
```

### Handling Exceptions

To handle exceptions, include the `exception.h` header and use the provided exception classes:

```cpp
#include "exception.h"

try {
    // Some code that may throw an exception
    throw INDEX_ERROR("Index out of bounds");
} catch (const IndexError &e) {
    std::cerr << e.what() << std::endl;
}
```

## API Reference

### Linked List API

- **Constructor and Destructor**
  - `linkedlist()`: Default constructor.
  - `virtual ~linkedlist() = default;`: Virtual destructor.

- **Member Functions**
  - `virtual void prepend(const A &value) = 0;`: Add a value to the beginning.
  - `virtual void append(const A &value) = 0;`: Add a value to the end.
  - `virtual void insert(const int64_t &index, const A &value) = 0;`: Insert a value at a specific index.
  - `virtual void remove(const A &value) = 0;`: Remove all occurrences of a value.
  - `virtual size_t size() const;`: Get the number of elements.
  - `virtual void clear() = 0;`: Clear the list.
  - `virtual A &operator[](const int64_t &index) = 0;`: Access element by index.

### Exception Handling API

- **Exception Class**
  - `Exception(const std::string &msg, const char *file, int line, const char *func);`: Base class for custom exceptions.
  - `const char* what() const noexcept override;`: Returns detailed error message.

- **Derived Classes**
  - `IndexError`: Exception for index-related errors.
  - `ValueError`: Exception for value-related errors.
  - `TypeError`: Exception for type-related errors.

### `singly_linked_list<A>`

The `singly_linked_list` class extends the `linkedlist` class to provide a singly linked list implementation with various methods for manipulation and access.

#### Constructor

- **`singly_linked_list()`**
  
  Initializes an empty singly linked list.

- **`singly_linked_list(const linkedlist<A> &obj)`**
  
  Constructs a `singly_linked_list` by copying from another `linkedlist` object.

- **`singly_linked_list(const std::initializer_list<A> &obj)`**
  
  Constructs a `singly_linked_list` from an initializer list.

- **`template <size_t N> singly_linked_list(const A (&array)[N])`**
  
  Constructs a `singly_linked_list` from a C-style array.

- **`singly_linked_list(const std::vector<A> &values)`**
  
  Constructs a `singly_linked_list` from a `std::vector`.

- **`singly_linked_list(singly_linked_list<A> &&obj) noexcept`**
  
  Move constructor for transferring ownership of another `singly_linked_list`.

#### Assignment Operators

- **`singly_linked_list<A> &operator=(const singly_linked_list<A> &obj)`**
  
  Copy assignment operator.

- **`singly_linked_list<A> &operator=(singly_linked_list<A> &&obj) noexcept`**
  
  Move assignment operator.

#### Public Methods

- **`void prepend(const A &value) override`**
  
  Adds `value` to the beginning of the list.

- **`void append(const A &value) override`**
  
  Adds `value` to the end of the list.

- **`void insert(const int64_t &index, const A &value) override`**
  
  Inserts `value` at the specified `index`.

- **`void insert(const int64_t &index, const linkedlist<A> &obj) override`**
  
  Inserts elements from another `linkedlist` at the specified `index`.

- **`void insert(const int64_t &index, const std::initializer_list<A> &values) override`**
  
  Inserts elements from an initializer list at the specified `index`.

- **`template <size_t N> void insert(const int64_t &index, const A (&array)[N])`**
  
  Inserts elements from a C-style array at the specified `index`.

- **`void insert(const int64_t &index, const std::vector<A> &values) override`**
  
  Inserts elements from a `std::vector` at the specified `index`.

- **`void insert_in_order(const A &value) override`**
  
  Inserts `value` into the list in sorted order.

- **`void insert_in_order(const int64_t &index, const linkedlist<A> &obj) override`**
  
  Inserts elements from another `linkedlist` in sorted order at the specified `index`.

- **`void insert_in_order(const int64_t &index, const std::initializer_list<A> &values) override`**
  
  Inserts elements from an initializer list in sorted order at the specified `index`.

- **`template <size_t N> void insert_in_order(const int64_t &index, const A (&array)[N])`**
  
  Inserts elements from a C-style array in sorted order at the specified `index`.

- **`void insert_in_order(const int64_t &index, const std::vector<A> &values) override`**
  
  Inserts elements from a `std::vector` in sorted order at the specified `index`.

- **`void extend(const linkedlist<A> &obj) override`**
  
  Appends elements from another `linkedlist` to the end of this list.

- **`void extend(const std::initializer_list<A> &values) override`**
  
  Appends elements from an initializer list to the end of this list.

- **`template <size_t N> void extend(const A (&array)[N])`**
  
  Appends elements from a C-style array to the end of this list.

- **`void extend(const std::vector<A> &values) override`**
  
  Appends elements from a `std::vector` to the end of this list.

- **`void remove(const A &value) override`**
  
  Removes the first occurrence of `value` from the list.

- **`A pop(const int64_t &index) override`**
  
  Removes and returns the element at the specified `index`.

- **`A pop() override`**
  
  Removes and returns the last element of the list.

- **`size_t size() const`**
  
  Returns the number of elements in the list.

- **`int64_t find(const A &value) const override`**
  
  Finds the index of the first occurrence of `value`. Returns `NOT_FOUND` if not found.

- **`A find_min() const override`**
  
  Returns the minimum value in the list.

- **`A find_max() const override`**
  
  Returns the maximum value in the list.

- **`size_t count(const A &value) const override`**
  
  Returns the number of occurrences of `value` in the list.

- **`void reverse() override`**
  
  Reverses the order of elements in the list.

- **`void sort() override`**
  
  Sorts the list in ascending order.

- **`singly_linked_list<A> &copy(const linkedlist<A> &obj)`**
  
  Copies elements from another `linkedlist` into this list.

- **`A &operator[](const int64_t &index) override`**
  
  Provides access to the element at the specified `index`.

- **`singly_linked_list<A> operator+(const linkedlist<A> &obj)`**
  
  Concatenates this list with another `linkedlist` and returns the result.

- **`singly_linked_list<A> operator*(const size_t &times)`**
  
  Repeats the list `times` times and returns the result.

- **`bool operator>(const linkedlist<A> &obj) const override`**
  
  Compares this list to another `linkedlist` for greater-than.

- **`bool operator<(const linkedlist<A> &obj) const override`**
  
  Compares this list to another `linkedlist` for less-than.

- **`bool operator>=(const linkedlist<A> &obj) const override`**
  
  Compares this list to another `linkedlist` for greater-than-or-equal.

- **`bool operator<=(const linkedlist<A> &obj) const override`**
  
  Compares this list to another `linkedlist` for less-than-or-equal.

- **`bool operator==(const linkedlist<A> &obj) const override`**
  
  Compares this list to another `linkedlist` for equality.

- **`bool operator!=(const linkedlist<A> &obj) const override`**
  
  Compares this list to another `linkedlist` for inequality.

- **`void show()`**
  
  Prints the elements of the list to the standard output.

- **`void clear() override`**
  
  Removes all elements from the list.

#### Friend Functions

- **`template <typename B> singly_linked_list<B> operator*(const size_t &times, const singly_linked_list<B> &obj)`**
  
  Repeats a `singly_linked_list` `times` and returns the result.

- **`template <typename B> std::ostream &operator<<(std::ostream &out, singly_linked_list<B> &obj)`**
  
  Outputs the list elements to the given `std::ostream`.

#### Destructor

- **`~singly_linked_list()`**
  
  Cleans up resources used by the `singly_linked_list`.


## Examples

You can find example usage and test cases in the `examples` directory of this repository. They cover various use cases and demonstrate how to use the linked list and exception handling features effectively.

## Contributing

We welcome contributions to improve the library. To contribute:

1. Fork the repository.
2. Create a new branch for your feature or bug fix.
3. Submit a pull request with a clear description of your changes.

Please refer to the [CONTRIBUTING.md](CONTRIBUTING.md) for detailed guidelines.

## License

This project is licensed under the [MIT License](LICENSE). See the [LICENSE](LICENSE) file for details.

## Contact

For any questions or feedback, feel free to reach out:

- **Author**: Harikrishna Srinivasan
- **Email**: harikrishnasri3@gmail.com
- **GitHub**: [Harikrishna-Srinivasan-1](https://github.com/Harikrishna-Srinivasan-1)

---

This README provides an overview of your linked list library, including installation, usage, API reference, and contribution guidelines.
