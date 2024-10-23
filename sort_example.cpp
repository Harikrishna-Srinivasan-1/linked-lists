#include <iostream>

#include "singly_linked_list.hpp"

/**
 * @file sort_example.cpp
 * @brief Demonstrates usage of singly_linked_list sort method.
 *
 * This program provides examples of sorting singly linked lists with various data types,
 * including integers and custom classes. It showcases the use of the sort method to 
 * perform merge sort on the list.
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
        // Default Constructor
        my_class() = default;

        // Parametrized Costructor
        my_class(int var)
        {
            this->my_var = var;
        }

        // Compulsory to define operator=, operator<, operator==, etc... to compare
        bool operator<(const my_class &obj)
        {
            return this->my_var < obj.my_var;
        }

        bool operator>(const my_class &obj)
        {
            return this->my_var > obj.my_var;
        }

        bool operator<=(const my_class &obj)
        {
            return this->my_var <= obj.my_var;
        }

        bool operator>=(const my_class &obj)
        {
            return this->my_var >= obj.my_var;
        }

        bool operator==(const my_class &obj)
        {
            return this->my_var == obj.my_var;
        }

        bool operator!=(const my_class &obj)
        {
            return this->my_var != obj.my_var;
        }

        // To display (print) the output using << (extraction) operator
        friend std::ostream &operator<<(std::ostream &out, const my_class &obj); // Decalre as friend to access private my_var of other object
};

std::ostream &operator<<(std::ostream &out, const my_class &obj)
{
    out << obj.my_var;

    return out;
}

int main()
{
    // Example 1: Sorting a list of integers
    singly_linked_list<int> list1 = {42, 23, 74, 11, 65, 58};
    std::cout << "list1: " << list1 << std::endl; // [42, 23, 74, 11, 65, 58]

    // Sorts in non-decreasing order
    list1.sort();
    std::cout << "list1: " << list1 << std::endl; // list1: [11, 23, 42, 58, 65, 74]

    // Sorting a list of my_class objects
    singly_linked_list<my_class> my_class_list = {my_class(5), my_class(1), my_class(4), my_class(3), my_class(2)};
    std::cout << "my_class_list: " << my_class_list << std::endl; // my_class_list: [5, 1, 4, 3, 2]

    my_class_list.sort();
    std::cout << "my_class_list: " << my_class_list << std::endl; // my_class_list: [1, 2, 3, 4, 5]
}
