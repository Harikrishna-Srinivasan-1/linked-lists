#include <iostream>
#include <vector> // To use std::vector

#include "singly_linked_list.hpp"

// Pending ...

/**
 * @file operator_example.cpp
 * @brief Demonstrates usage of various operators for singly_linked_list.
 *
 * This program provides examples of using comparison operators and 
 * the subscript operator on singly linked lists, including 
 * negative indexing and modifying elements.
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
    // Initialize the singly linked lists
    singly_linked_list<int> list1 = {1,2,3,4,5};
    singly_linked_list<int> list2 = {1,2,3,4,5};
    singly_linked_list<int> list3 = {1,2,3,4,6};

    // Comparison operators
    std::cout << std::boolalpha; // To print booleans as true/false not as 1/0
    std::cout << "list1 == list2: " << (list1 == list2) << std::endl; // list1 == list2: true
    std::cout << "list1 != list3: " << (list1 != list3) << std::endl; // list1 != list2: true
    std::cout << "list1 < list3: " << (list1 < list3) << std::endl; // list1 < list2: true
    std::cout << "list1 > list3: " << (list1 > list3) << std::endl; // list1 > list2: false
    std::cout << "list1 <= list2: " << (list1 <= list2) << std::endl; // list1 <= list2: true
    std::cout << "list1 >= list3: " << (list1 >= list3) << std::endl; // list1 >= list2: false

    // Using subscript operator
    std::cout << "list1[2]: " << list1[2] << std::endl; // list1[2]: 3

    // Modifying list1 through subscript operator - []
    list1[2] = 5; // Change the value at index 2 to 5
    std::cout << "list1: " << list1 << std::endl; // list1: [1, 2, 5, 4, 5]

    // Using subscript operator with negative indexing
    std::cout << "list1[-1]: " << list1[-1] << std::endl; // list1[-1]: 5 (last element)
    std::cout << "list1[-2]: " << list1[-2] << std::endl; // list1[-2]: 4 (second last element)

    // Both list1 and list2 now refer to the same object
    list2 = list1; 
    std::cout << "list2: " << list2 << std::endl; // list2: [1, 2, 5, 4, 5]
    
    // Change value at index 1 to 10
    list1[1] = 10; 
    std::cout << "list1: " << list1 << std::endl; // list1: [1, 10, 5, 4, 5]
    std::cout << "list2: " << list2 << std::endl; // list2: [1, 10, 5, 4, 5]

    // Demonstrate IndexError
    try 
    {
        std::cout << "Attempting to access out of bounds: " << list1[10] << std::endl; // Will throw an IndexError
    } 
    
    catch (const IndexError &error) 
    {
        std::cout << error.what() << std::endl; // IndexError: List index out of range in file `singly_linked_list.tpp` at line: ### in function operator[]
    }

    // Concatenate lists containing same data type elements
    list3 = list1 + list2;
    std::cout << "list3: " << list3 << std::endl; // list3: []
}
