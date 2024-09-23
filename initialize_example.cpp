#include <iostream>
#include <vector> // To use std::vector 

#include "singly_linked_list.h"

/**
 * @file initialize_example.cpp
 * @brief Demonstrates usage of singly_linked_list constructors.
 * 
 * This program provides examples of initializing singly linked lists with various data types,
 * including integers, characters, and custom classes. It showcases the use of default constructors,
 * copy constructors, initializer lists, arrays, vectors, and move constructors.
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

        // Compulsory to define operator=, operator<, operator>, etc... to compare
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
    // Default Constructor: Initializes with default values
    singly_linked_list<int> list1;
    // Print the list1 object
    std::cout << "list1: " << list1 << std::endl; // list1: [] - Empty list

    // Constructor from an initializer list
    singly_linked_list<int> list2 = {21,45,37,64,72};
    singly_linked_list<char> char_list1 = {'a','r','r','a','y'};

    // Or, singly_linked_list<int> list3({21,45,37,64,72});
    // Or, singly_linked_list<int> list4 {21,45,37,64,72};

    // Similarly, singly_linked_list<char> char_list2({'a','r','r','a','y'});
    // Or, singly_linked_list<char> char_list3 {'a','r','r','a','y'};

    std::cout << "list2: " << list2 << std::endl; // list2: [21, 45, 37, 64, 72]
    std::cout << "char_list1: " << char_list1 << std::endl; // char_list1: [a, r, r, a, y]
    
    // Copy Constructor: Pass the object
    singly_linked_list<char> char_list2(char_list1);
    std::cout << "char_list2: " << char_list2 << std::endl; // char_list2: [a, r, r, a, y] - same as char_list1

    // Copy Constructor: Using braces "{}"
    singly_linked_list<int> list3{list2};
    std::cout << "list3: " << list3 << std::endl; // list3: [21, 45, 37, 64, 72] - same as list2

    // Create a string array
    std::string str_array[] = {"One","Two","Three"};

    // Constructor from static std::string array - similar to initializer_list
    singly_linked_list<std::string> str_arr_list = str_array; // !Note: Class can be used as template (e.g., std::string)
    std::cout << "str_arr_list: " << str_arr_list << std::endl; // str_arr_list: [One, Two, Three]

    // !Note: Constructor from dynamic array is not currently supported

    // Create a std::vector of my_class objects
    // Reference for std::vector usage: https://en.cppreference.com/w/cpp/container/vector/
    std::vector<my_class> my_class_vector = {my_class(1),my_class(2),my_class(3)};
    my_class_vector.push_back(my_class(4));

    // Constructor from std::vector with custom class (user-defined) template - similar to initializer_list
    singly_linked_list<my_class> my_class_list = my_class_vector;
    std::cout << "my_class_list: " << my_class_list << std::endl; // my_class_list: [1, 2, 3, 4]

    // Move constructor from list2 to list4, and make list2 as Empty list
    singly_linked_list<int> list4 = std::move(list2); // Both list2 and list4, now refer the same list (like alias)
    std::cout << "list4: " << list4 << std::endl // list4: [21, 45, 37, 64, 72]
              << "list2: " << list2 << std::endl; // list2: [] - Empty list
    
    // Move constructor invoked (called) using static_cast<Destination_Type>(expression_to_be_converted)
    // Reference for static_cast<T>(expr) usage: https://en.cppreference.com/w/cpp/language/static_cast/
    singly_linked_list<int> list5 = static_cast<singly_linked_list<int> &&>(list4);
    std::cout << "list5: " << list5 << std::endl // list5: [21, 45, 37, 64, 72]
              << "list4: " << list4 << std::endl; // list4: [] - Empty list after moving to list5
}
