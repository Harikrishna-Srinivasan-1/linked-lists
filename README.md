
---
# Linked List Library

Welcome to the **Linked List Library**! This repository provides a robust and flexible implementation of singly linked lists in C++ with additional features for exception handling. This library supports a wide range of operations and is designed to be easily integrated into your projects.

## Features

- **Singly Linked List Implementation**: A dynamic, flexible linked list supporting various operations.
- **Exception Handling**: Custom exception classes for robust error reporting.
- **Generic and Template-Based**: Supports any data type using C++ templates.

## Table of Contents

- [Getting Started](#getting-started)
- [Installation](#installation)
- [Usage](#usage)
- [API Reference](#api-reference)
- [Examples](#examples)
- [Contributing](#contributing)
- [License](#license)
- [Code of Conduct](#code-of-conduct)
- [Contact](#contact)
- [Architecture Overview](ARCHITECTURE_OVERVIEW.md)
- [Style Guide](STYLE_GUIDE.md)
- [Dependencies](DEPENDENCIES.md)

## Getting Started

**Getting Started with `singly_linked_list`**

Welcome to the `singly_linked_list` project! Follow these steps to get started with using and contributing to this project.

### Prerequisites

- C++11 or later
- A compatible compiler (e.g., G++, Clang, MSVC)

### Installation

1. **Clone the Repository**

   First, clone the repository using `git clone`:

   ```bash
   git clone https://github.com/Harikrishna-Srinivasan/Linked-Lists.git
   ```

   This command will create a directory named `Linked-Lists` containing the repository's files.

2. **Navigate to the Repository Directory**

   Change to the directory where the repository was cloned:

   ```bash
   cd Linked-Lists
   ```

3. **Check Out the Specific Branch**

   After navigating into the repository directory, you can check out the `Data-Structures` branch:

   ```bash
   git checkout Data-Structures
   ```

   This command switches your working directory to the `Data-Structures` branch.

### Example Workflow

Here’s the complete set of commands:

```bash
# Clone the repository
git clone https://github.com/Harikrishna-Srinivasan/Linked-Lists.git

# Navigate into the cloned repository
cd Linked-Lists

# Check out the 'Data-Structures' branch
git checkout Data-Structures
```

### Additional Tips

- **Verify Branch Existence**: If you're not sure whether the `Data-Structures` branch exists, you can list all branches using:
  
  ```bash
  git branch -a
  ```

  This command shows all local and remote branches. Look for `remotes/origin/Data-Structures` in the output.

- **Fetch All Branches**: If the branch isn’t showing up, make sure you’ve fetched all branches from the remote:

  ```bash
  git fetch --all
  ```

- **List Branches**: To see a list of all branches, including remote branches, you can use:

  ```bash
  git branch -r
  ```

4. **Compile**

   To compile and run C++ code using different compilers, use the commands specific to each compiler:

   **GNU Compiler Collection (g++)**

   ```bash
   g++ -std=c++11 -Wall -Wextra -o your_program main.cpp
   ./your_program
   ```

   **Clang**

   ```bash
   clang++ -std=c++11 -Wall -Wextra -o your_program main.cpp
   ./your_program
   ```

   **Microsoft Visual C++ (MSVC)**

   ```cmd
   cl /EHsc /std:c++11 /W4 main.cpp
   your_program.exe
   ```

   **Intel C++ Compiler (icc)**

   ```bash
   icc -std=c++11 -Wall -o your_program main.cpp
   ./your_program
   ```

   **MinGW**

   ```bash
   g++ -std=c++11 -Wall -Wextra -o your_program.exe main.cpp
   your_program.exe
   ```

   **Open Watcom**

   ```bash
   wcl -std=c++11 -o your_program.exe main.cpp
   your_program.exe
   ```

5. **Run Tests (Optional)**

   To ensure everything is working correctly, you can run the provided [examples](#examples).

   ```bash
   ./your_program
   ```

## Usage

To use the `singly_linked_list`, include the header file in your project:

```cpp
#include "singly_linked_list.h"
```

Create and manipulate instances of `singly_linked_list`:

```cpp
singly_linked_list<int> list;
list.append(10);
list.prepend(5);
```

### Examples

**Usage 1**

```cpp
#include <iostream>

#include "singly_linked_list.h"

int main()
{
    singly_linked_list<int> list;
    list.append(1);
    list.append(2);
    list.append(3);

    std::cout << "List contents: " << list << std::endl;

    list.remove(2);
    std::cout << "After removing 2: " << list << std::endl;

    return 0;
}
```

**Usage 2**

```cpp
#include <iostream>

#include "singly_linked_list.h"

int main()
{
    singly_linked_list<int> list;
    list.extend({4, 5, 6});
    list.insert(1, {7, 8});

    std::cout << "Extended and inserted list: " << list << std::endl;

    list.sort();
    std::cout << "Sorted list: " << list << std::endl;

    return 0;
}

```
## API Reference

### Linked List API

#### Constructor and Destructor
- **`linkedlist()`**  
  Default constructor that initializes an empty linked list.
- **`virtual ~linkedlist() = default;`**  
  Virtual destructor for proper cleanup in derived classes.

#### Member Functions
- **`virtual void prepend(const A &value) = 0;`**  
  Adds `value` to the beginning of the list.
- **`virtual void append(const A &value) = 0;`**  
  Adds `value` to the end of the list.
- **`virtual void insert(const int64_t &index, const A &value) = 0;`**  
  Inserts `value` at the specified `index`. If `index` is out of bounds, an `IndexError` is thrown.
- **`virtual void remove(const A &value) = 0;`**  
  Removes all occurrences of `value` from the list.
- **`virtual size_t size() const;`**  
  Returns the number of elements in the list.
- **`virtual void clear() = 0;`**  
  Removes all elements from the list.
- **`virtual A &operator[](const int64_t &index) = 0;`**  
  Provides access to the element at `index`. If `index` is out of bounds, an `IndexError` is thrown.

### Exception Handling API

#### Exception Class
- **`Exception(const std::string &msg, const char *file, int line, const char *func);`**  
  Base class for custom exceptions. Stores an error message, file name, line number, and function name where the exception occurred.
- **`const char* what() const noexcept override;`**  
  Returns a detailed error message including the file, line, and function.

#### Derived Classes
- **`IndexError`**  
  Exception thrown for index-related errors, such as accessing an out-of-bounds index.
- **`ValueError`**  
  Exception thrown for value-related errors, such as trying to remove a value that does not exist in the list.
- **`TypeError`**  
  Exception thrown for type-related errors, such as performing an operation on incompatible types.

### Singly Linked List API

The `singly_linked_list` class extends `linkedlist` to provide a concrete implementation of a singly linked list with various methods for list manipulation and access.

#### Constructors
- **`singly_linked_list()`**  
  Initializes an empty singly linked list.
- **`singly_linked_list(const linkedlist<A> &obj)`**  
  Copy constructor that initializes the list with elements from another `linkedlist` object.
- **`singly_linked_list(const std::initializer_list<A> &obj)`**  
  Initializes the list with elements from an initializer list.
- **`template <size_t N> singly_linked_list(const A (&array)[N])`**  
  Initializes the list with elements from a C-style array.
- **`singly_linked_list(const std::vector<A> &values)`**  
  Initializes the list with elements from a `std::vector`.
- **`singly_linked_list(singly_linked_list<A> &&obj) noexcept`**  
  Move constructor that transfers ownership of resources from another `singly_linked_list`.

#### Assignment Operators
- **`singly_linked_list<A> &operator=(const singly_linked_list<A> &obj)`**  
  Copy assignment operator. Copies elements from another `singly_linked_list`.
- **`singly_linked_list<A> &operator=(singly_linked_list<A> &&obj) noexcept`**  
  Move assignment operator. Transfers ownership of elements from another `singly_linked_list`.

#### Public Methods
- **`void prepend(const A &value) override`**  
  Adds `value` to the beginning of the list.
- **`void append(const A &value) override`**  
  Adds `value` to the end of the list.
- **`void insert(const int64_t &index, const A &value) override`**  
  Inserts `value` at the specified `index`. Throws `IndexError` if the index is out of bounds.
- **`void insert(const int64_t &index, const linkedlist<A> &obj) override`**  
  Inserts elements from another `linkedlist` at the specified `index`.
- **`void insert(const int64_t &index, const std::initializer_list<A> &values) override`**  
  Inserts elements from an initializer list at the specified `index`.
- **`template <size_t N> void insert(const int64_t &index, const A (&array)[N])`**  
  Inserts elements from a C-style array at the specified `index`.
- **`void insert_in_order(const A &value) override`**  
  Inserts `value` in sorted order.
- **`void extend(const linkedlist<A> &obj) override`**  
  Appends elements from another `linkedlist` to the end of the list.
- **`void extend(const std::initializer_list<A> &values) override`**  
  Appends elements from an initializer list to the end of the list.
- **`template <size_t N> void extend(const A (&array)[N])`**  
  Appends elements from a C-style array to the end of the list.
- **`void extend(const std::vector<A> &values) override`**  
  Appends elements from a `std::vector` to the end of the list.
- **`void remove(const A &value) override`**  
  Removes all occurrences of `value` from the list.
- **`A pop(const int64_t &index) override`**  
  Removes and returns the element at `index`. Throws `IndexError` if the index is out of bounds.
- **`A pop() override`**  
  Removes and returns the last element in the list.
- **`size_t size() const`**  
  Returns the number of elements in the list.
- **`int64_t find(const A &value) const override`**  
  Returns the index of the first occurrence of `value`. Returns -1 if not found.
- **`A find_min() const override`**  
  Returns the smallest element in the list. Throws `ValueError` if the list is empty.
- **`A find_max() const override`**  
  Returns the largest element in the list. Throws `ValueError` if the list is empty.
- **`size_t count(const A &value) const override`**  
  Returns the number of occurrences of `value` in the list.
- **`void reverse() override`**  
  Reverses the order of elements in the list.
- **`void sort() override`**  
  Sorts the list in ascending order.
- **`singly_linked_list<A> &copy(const linkedlist<A> &obj)`**  
  Copies elements from another `linkedlist` into this list.
- **`A &operator[](const int64_t &index) override`**  
  Provides access to the element at `index`. Throws `IndexError` if the index is out of bounds.
- **`singly_linked_list<A> operator+(const linkedlist<A> &obj)`**  
  Concatenates this list with another `linkedlist` and returns the result.
- **`singly_linked_list<A> operator*(const size_t &times)`**  
  Repeats the list `times` and returns the result.
- **`bool operator>(const linkedlist<A> &obj) const override`**  
  Returns `true` if this list is lexicographically greater than `obj`.
- **`bool operator<(const linkedlist<A> &obj) const override`**  
  Returns `true` if this list is lexicographically less than `obj`.
- **`bool operator>=(const linkedlist<A> &obj) const override`**  
  Returns `true` if this list is lexicographically greater than or equal to `obj`.
- **`bool operator<=(const linkedlist<A> &obj) const override`**  
  Returns `true` if this list is lexicographically less than or equal to `obj`.
- **`bool operator==(const linkedlist<A> &obj) const override`**  
  Returns `true` if this list is equal to `obj`.
- **`bool operator!=(const linkedlist<A> &obj) const override`**  
  Returns `true` if this list is not equal to `obj`.
- **`void show()`**  
  Prints the elements of the list to the standard output.
- **`void clear() override`**  
  Removes all elements from the list.

#### Friend Functions
- **`template <typename B> singly_linked_list<B> operator*(const size_t &times, const singly_linked_list<B> &obj)`**  
  Repeats the list `times` and returns the result.
- **`template <typename B> std::ostream &operator<<(std::ostream &out, singly_linked_list<B> &obj)`**  
  Outputs the elements of the list to the specified output stream.

#### Destructor
- **`~singly_linked_list()`**  
  Destructor that cleans up resources used by the `singly_linked_list`.

### Private Methods (Static)
- **`static typename linkedlist<A>::node *mergesort(typename linkedlist<A>::node *head)`**  
  Performs

 merge sort on the list starting at `head`.
- **`static typename linkedlist<A>::node *merge(typename linkedlist<A>::node *left, typename linkedlist<A>::node *right)`**  
  Merges two sorted lists, `left` and `right`.
- **`static typename linkedlist<A>::node *reverse_link(typename linkedlist<A>::node *head)`**  
  Reverses the links in the list starting at `head`.

### Usage Examples
Here's a simple example demonstrating how to use the `singly_linked_list` class:

```cpp
singly_linked_list<int> list;
list.append(10);
list.prepend(5);
list.insert(1, 7);
list.show();  // Outputs: 5 7 10
list.sort();
list.show();  // Outputs: 5 7 10
list.reverse();
list.show();  // Outputs: 10 7 5
```

## Contributing

We welcome contributions to improve the library. To contribute:

1. Fork the repository.
2. Create a new branch for your feature or bug fix.
3. Submit a pull request with a clear description of your changes.

Please refer to the [Contributing Guidelines](contributing.md) for detailed instructions.

## License

This project is licensed under the [MIT License](LICENSE). See the [LICENSE](LICENSE) file for details.

## Code of Conduct

Please adhere to our [Code of Conduct](CODE_OF_CONDUCT.md) when contributing to this project.

## Contact

For any questions or feedback, feel free to reach out:

- **Author**: Harikrishna Srinivasan
- **Email**: harikrishnasri3@gmail.com
- **GitHub**: [Harikrishna-Srinivasan-1](https://github.com/Harikrishna-Srinivasan-1)

## Additional Resources

- [Architecture Overview](ARCHITECTURE_OVERVIEW.md)
- [Style Guide](STYLE_GUIDE.md)
- [Dependencies](DEPENDENCIES.md)
- [Getting Started](GETTING_STARTED.md)

---

### Notes:
- Ensure that all the linked files (e.g., `ARCHITECTURE_OVERVIEW.md`, `STYLE_GUIDE.md`, etc.) exist in your repository.
- Make sure the paths to your header (`.h`) and implementation (`.tpp`) files are accurate if they need to be linked directly. You might also want to include specific usage examples if these files contain detailed implementations.
