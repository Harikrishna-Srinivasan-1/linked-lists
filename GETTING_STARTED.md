
---
### Getting Started

**Getting Started with `singly_linked_list`**

Welcome to the `singly_linked_list` project! Follow these steps to get started with using and contributing to this project.

**Prerequisites**

- C++11 or later
- A compatible compiler (e.g., GCC, Clang, MSVC)

**Installation**

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
To compile and run C++ code using different compilers, you'll use different commands specific to each compiler. Below are the commands for some popular compilers:

### **1. GNU Compiler Collection (g++)**

For GNU g++, which is commonly used on Unix-like systems:

```bash
g++ -std=c++11 -Wall -Wextra -o your_program main.cpp
./your_program
```

- **`-std=c++11`**: Specifies the C++ standard version.
- **`-Wall -Wextra`**: Enables most compiler warnings.
- **`-o your_program`**: Specifies the output executable name.
- **`./your_program`**: Runs the compiled executable.

### **2. Clang**

For Clang, which is another popular compiler:

```bash
clang++ -std=c++11 -Wall -Wextra -o your_program main.cpp
./your_program
```

- **`clang++`**: The Clang compiler command.
- **Other flags**: Similar to g++ for standard, warnings, and output file.

### **3. Microsoft Visual C++ (MSVC)**

For MSVC, typically used on Windows. You’ll use `cl.exe`, which is the command-line compiler. You usually need to run these commands from the "Developer Command Prompt for Visual Studio":

```cmd
cl /EHsc /std:c++11 /W4 main.cpp
your_program.exe
```

- **`/EHsc`**: Enables standard exception handling.
- **`/std:c++11`**: Specifies the C++ standard version (available in newer versions of MSVC).
- **`/W4`**: Enables most warnings.
- **`your_program.exe`**: The name of the executable.

### **4. Intel C++ Compiler (icc)**

For Intel’s compiler, the command looks like this:

```bash
icc -std=c++11 -Wall -o your_program main.cpp
./your_program
```

- **`icc`**: The Intel C++ compiler command.
- **`-std=c++11`**: Specifies the C++ standard version.
- **`-Wall`**: Enables warnings.
- **`./your_program`**: Runs the compiled executable.

### **5. MinGW**

For MinGW on Windows, which uses a GCC-based toolchain:

```bash
g++ -std=c++11 -Wall -Wextra -o your_program.exe main.cpp
your_program.exe
```

- **`.exe`**: The extension for executables on Windows.

### **6. Open Watcom**

For Open Watcom compiler:

```bash
wcl -std=c++11 -o your_program.exe main.cpp
your_program.exe
```

- **`wcl`**: The Open Watcom compiler command.

Make sure to replace `main.cpp` with the path to your source file and `your_program` with the desired name of your executable.

5. **Run Tests (Optional)**

   To ensure everything is working correctly, you can run the provided [examples](#Examples). 

   ```bash
   ./your_program
   ```

**Usage 1**

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

**Usage 2**

```cpp
#include "singly_linked_list.h"
#include <iostream>

int main() {
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

**Usage 3**

```cpp
#include "singly_linked_list.h"
#include <iostream>

int main() {
    singly_linked_list<int> list;
    list.extend({4, 5, 6});
    list.insert(1, {7, 8});

    std::cout << "Extended and inserted list: " << list << std::endl;

    list.sort();
    std::cout << "Sorted list: " << list << std::endl;

    return 0;
}
```
---
