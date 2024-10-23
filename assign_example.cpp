#include <iostream>
#include <vector>

#include "singly_linked_list.h"

/**
 * @file initialize_example.cpp
 * @brief Demonstrates usage of equal to operator.
 * 
 * This program provides examples of initializing singly linked lists with various data types,
 * including integers, characters, and custom classes. It showcases the use of move and assignment operators.
 * 
 * @author Harikrishna Srinivasan
 * @date [Current Date]
 * @version 1.0
 */

int main() 
{
    // Default Constructor: Initializes with default values
    singly_linked_list<int> list1;
    std::cout << "list1: " << list1 << std::endl; // list1: [] - Empty list

    // Constructor from an initializer list
    singly_linked_list<int> list2 = {21, 45, 37, 64, 72};
    singly_linked_list<char> char_list1 = {'a', 'r', 'r', 'a', 'y'};

    std::cout << "list2: " << list2 << std::endl; // list2: [21, 45, 37, 64, 72]
    std::cout << "char_list1: " << char_list1 << std::endl; // char_list1: [a, r, r, a, y]
    
    // Copy Constructor
    singly_linked_list<char> char_list2(char_list1);
    std::cout << "char_list2: " << char_list2 << std::endl; // char_list2: [a, r, r, a, y]

    // Copy Constructor with initializer list
    singly_linked_list<int> list3{list2};
    std::cout << "list3: " << list3 << std::endl; // list3: [21, 45, 37, 64, 72]

    // Create a string array and initialize singly linked list
    std::string str_array[] = {"One", "Two", "Three"};
    singly_linked_list<std::string> str_arr_list = str_array;
    std::cout << "str_arr_list: " << str_arr_list << std::endl; // str_arr_list: [One, Two, Three]

    // Move constructor
    singly_linked_list<int> list4 = std::move(list2);
    std::cout << "list4: " << list4 << std::endl; // list4: [21, 45, 37, 64, 72]
    std::cout << "list2: " << list2 << std::endl; // list2: [] - Empty list

    // Move assignment
    singly_linked_list<int> list5 = std::move(list4);
    std::cout << "list5: " << list5 << std::endl; // list5: [21, 45, 37, 64, 72]
    std::cout << "list4: " << list4 << std::endl; // list4: [] - Empty list after moving

    return 0;
}
