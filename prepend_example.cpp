#include <iostream>

#include "singly_linked_list.h"

/**
 * @file prepend_example.cpp
 * @brief Demonstrates the usage of the `prepend` method in a singly linked list.
 * 
 * This program provides examples of using the `prepend` method to add elements 
 * to the beginning of a singly linked list. It includes examples with strings 
 * and integers to showcase the versatility of the `prepend` method.
 * 
 * @sa insert_example.cpp for examples of other list insertion methods.
 * 
 * @author Harikrishna Srinivasan
 * @date [Current Date]
 * @version 1.0
 */

int main()
{
    // Create a list of favorite fruits using initializer list
    singly_linked_list<std::string> favorite_fruit_list = {"Apple","Orange","Mango","Water Melon"};
    std::cout << "favorite_fruit_list: " << favorite_fruit_list << std::endl; // ["Apple", "Orange", "Mango", "Water Melon"]

    // Prepend "Banana" to the list, top favorite
    favorite_fruit_list.prepend("Banana");
    std::cout << "favorite_fruit_list: " << favorite_fruit_list << std::endl; // ["Banana", "Apple", "Orange", "Mango", "Water Melon"]

    // Create a list of known programming languages
    singly_linked_list<std::string> known_programming_lang = {"C","C++","Java"};
    std::cout << "known_programming_lang: " << known_programming_lang << std::endl; // ["C", "C++", "Java"]

    // Prepend "Python" to the list
    known_programming_lang.prepend("Python");
    std::cout << "known_programming_lang: " << known_programming_lang << std::endl; // ["Python", "C", "C++", "Java"]

    // Create a list of Sundays in January
    int jan[] = {13,20,27}; // !Note: The first Sunday (6) is missing
    singly_linked_list<int> jan_sundays = jan;
    std::cout << "jan_sundays: " << jan_sundays << std::endl; // [13, 20, 27]

    // Prepend the missing Sunday (6) to the list
    jan_sundays.prepend(6);
    std::cout << "jan_sundays: " << jan_sundays << std::endl; // [6, 13, 20, 27]

    return 0;
}
