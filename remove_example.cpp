#include <iostream>
#include <vector>

#include "singly_linked_list.hpp"

/**
 * @file remove_example.cpp
 * @brief Implements the remove function for a singly linked list.
 *
 * This method removes the first occurrence of a specified value from the singly linked list.
 * If the value is not found, an exception is thrown.
 *
 * @author Harikrishna Srinivasan
 * @date [Current Date]
 * @version 1.0
 */

// Create a custom class
class my_class
{
    private:
        int my_var;
    public:
        my_class() = default;

        my_class(int var): my_var(var) {}

        // Compulsory to define operator=, operator<, operator>, etc... to compare
        // Reference for const-keyword usage refer https://en.cppreference.com/w/cpp/keyword/const
        bool operator==(const my_class &obj) const
        {
            return this->my_var == obj.my_var;
        }

        bool operator>(const my_class &obj) const 
        {
            return this->my_var > obj.my_var;
        }

        // To display the output using << (extraction) operator
        friend std::ostream &operator<<(std::ostream &out, const my_class &obj) // !Note: friend functions can also be defined inside the class
        {
            out << obj.my_var;

            return out;
        }
};

int main()
{
    // Initialize the singly linked list
    singly_linked_list<int> list1 = {1,2,3,4,5};

    // Removes element 3
    list1.remove(3);
    std::cout << "list1: " << list1 << std::endl; // list1: [1, 2, 4, 5]

    // Remove element 5
    list1.remove(5);
    std::cout << "list1: " << list1 << std::endl; // list1: [1, 2, 4]

    // Demonstrate ValueError
    try
    {
        // Removing value not in list
        list1.remove(100); // Will throw a ValueError
    }
        
    catch(const ValueError &error)
    {
        std::cerr << error.what() << std::endl; // ValueError: Removing `x`, non-element in the List in file `singly_linked_list.tpp` at line: ### in function remove
    }
    
    // Both list1 and list2 now refer to the same object
    list1 = {1,2,5,4,5};
    singly_linked_list<int> list2 = list1;
    list1.remove(4);
    std::cout << "list1: " << list1 << std::endl // list1: [1, 2, 5, 5]
              << "list2: " << list2 << std::endl; // list2: [1, 2, 5, 5]

    return 0;
}
