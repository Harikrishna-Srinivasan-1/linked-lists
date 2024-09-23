#include <iostream>
#include <vector> // To use std::vector 

#include "singly_linked_list.h"

/**
 * @file extend_example.cpp
 * @brief Demonstrates `extend` in singly linked list.
 * 
 * This program provides examples of using the `extend` method in singly linked list.
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
    // Create two lists, with one being initialized
    singly_linked_list<int> list1, list2 = {21,45,37,64,72};

    // Extend list1 with list2
    list1.extend(list2);
    std::cout << "list1: " << list1 << std::endl // list1: [21, 45, 37, 64, 72]
              << "list2: " << list2 << std::endl; // list2: [21, 45, 37, 64, 72]

    // Create two char lists
    singly_linked_list<char> char_list1 = {'a','r','r','a','y'}, char_list2 = {'l','i','s','t'};
    
    // Extend char_list1 with char_list2
    char_list1.extend(char_list2);
    std::cout << "char_list1: " << char_list1 << std::endl; // char_list1: [a, r, r, a, y, l, i, s, t]

    // Extend list2 with initializer_list
    list2.extend({108,256,77,121,11});
    std::cout << "list2: " << list2 << std::endl; // list2: [21, 45, 37, 64, 72, 108, 256, 77, 121, 11]

    // Create a string array
    std::string str_array[] = {"One","Two","Three"};

    // Create a std::string list
    singly_linked_list<std::string> str_arr_list; // Initially Empty

    // Extend with std::string array
    str_arr_list.extend(str_array);
    std::cout << "str_arr_list: " << str_arr_list << std::endl; // str_arr_list: [One, Two, Three]

    // Create a std::vector of my_class objects
    std::vector<my_class> my_class_vector = {my_class(0),my_class(1)};
    my_class_vector.push_back(my_class(2));

    // Create a list of std::vector of my_class objects
    singly_linked_list<my_class> my_class_list = {my_class(-2),my_class(-1)};

    // Extend my_class_list with std::vector of my_class objects
    my_class_list.extend(my_class_vector);
    std::cout << "my_class_list: " << my_class_list << std::endl; // my_class_list: [-2, -1, 0, 1, 2]
}
