
---
## Style Guide

### 1. **Coding Standards**

#### General Guidelines
- Follow consistent naming conventions and indentation styles.
- Write clear and concise code that is easy to understand and maintain.
- Use meaningful names for variables, functions, and classes.

#### C++ Specific Guidelines
- **Indentation:** Use 4 tabs for indentation. Do not use spaces.
- **Braces:** Place braces on the next line for functions and control structures.
  ```cpp
  // Correct
  void example()
  {
      if (condition) {
          // code
      }
  }

  // Incorrect
  void example() {
      if (condition)
      {
          // code
      }
  }
  ```
- **Line Length:** Keep lines under 80 characters where possible.
- **Comments:** Use comments to explain why code is doing something, not what it is doing. Avoid redundant comments.
  ```cpp
  // Good comment: Explains why the next line is needed
  // Initialize the list with default values to avoid uninitialized variables
  singly_linked_list<int> list;
  ```

### 2. **Documentation**

#### Doxygen Comments
- Use Doxygen comments to document public APIs, classes, and functions.
  ```cpp
  /**
   * @class singly_linked_list
   * @brief A class for singly linked list implementation.
   * 
   * Provides methods to manipulate linked list elements and perform common operations.
   */
  template <typename A>
  class singly_linked_list: public linkedlist<A>
  {
      // ...
  };
  ```

#### Function Documentation
- Document each function with its purpose, parameters, return values, and any exceptions it may throw.
  ```cpp
  /**
   * @brief Appends a value to the end of the list.
   * @param value The value to append.
   */
  void append(const A &value) override;
  ```

### 3. **Commit Messages**

- Write clear and descriptive commit messages.
- Follow the format:
  ```
  <type>(<scope>): <short summary>
  
  <optional body>
  ```
  Examples:
  ```
  feat(list): add method to reverse the list
  
  Adds a new method to reverse the order of elements in the list.
  ```

  ```
  fix(merge): handle edge cases in merge function
  
  Fixes issues with merging when lists are empty or contain a single element.
  ```

### 4. **Testing**

- Write unit tests for new features and bug fixes.
- Ensure all tests pass before submitting a pull request.
- Follow a consistent naming convention for test cases.

---
