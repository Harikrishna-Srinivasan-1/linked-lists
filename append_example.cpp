#include <iostream>

#include "singly_linked_list.h"

/**
 * @file append_example.cpp
 * @brief Demonstrates the usage of the `append` method in a singly linked list.
 * 
 * This program provides examples of appending values to a singly linked list.
 * It highlights how new elements can be added to the end of the list for both 
 * strings and integers.
 *
 * @sa insert_example.cpp for inserting at specific positions in the list.
 * @sa extend_example.cpp for appending multiple elements using `extend`.
 * 
 * @author Harikrishna Srinivasan
 * @date [Current Date]
 * @version 1.0
 */

int main()
{
    // Create a list of favorite fruits using initializer list
    singly_linked_list<std::string> favorite_fruit_list = {"Banana","Apple","Orange","Mango"};
    std::cout << "favorite_fruit_list: " << favorite_fruit_list << std::endl; // ["Banana", "Apple", "Orange", "Mango"]

    // append "Water Melon" to the list, new favorite
    favorite_fruit_list.append("Water Melon");
    std::cout << "favorite_fruit_list: " << favorite_fruit_list << std::endl; // ["Banana", "Apple", "Orange", "Mango", "Water Melon"]

    // Create a list of known programming languages
    singly_linked_list<std::string> known_programming_lang = {"Python","C","C++"};
    std::cout << "known_programming_lang: " << known_programming_lang << std::endl; // ["Python", "C", "C++"]

    // append "Python" to the list
    known_programming_lang.append("Java");
    std::cout << "known_programming_lang: " << known_programming_lang << std::endl; // ["Python", "C", "C++", "Java"]

    // Create a list of Sundays in January
    int jan[] = {6,13,20}; // !Note: The last Sunday (27) is missing
    singly_linked_list<int> jan_sundays = jan;
    std::cout << "jan_sundays: " << jan_sundays << std::endl; // [6, 13, 20]

    // append the missing Sunday (27) to the list
    jan_sundays.append(27);
    std::cout << "jan_sundays: " << jan_sundays << std::endl; // [6, 13, 20, 27]

    // !Note: Only values can be appended
    // Arrays, or singly_linked_list, or std::initializer_list or std::vector can not be appended
    // obj.insert(0,<value|singly_linked_list|std::initializer_list|array|std::vector>)
    // Or, obj.extend(<value|singly_linked_list|std::initializer_list|array|std::vector>) can be used, instead

    return 0;
}
