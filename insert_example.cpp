#include <iostream>
#include <vector> // To use std::vector

#include "singly_linked_list.h"

/**
 * @file insert_example.cpp
 * @brief Demonstrates `insert` in singly linked list.
 * 
 * This program provides examples of using the `insert` method in singly linked list.
 *
 * @author Harikrishna Srinivasan
 * @date [Current Date]
 * @version 1.0
 */

int main()
{
    // Create a list of Sundays in January
    int jan[] = {6,20,27}; // !Note: The second Sunday (13) is missing
    singly_linked_list<int> jan_sundays = jan;
    std::cout << "jan_sundays: " << jan_sundays << std::endl; // [6, 13, 27]

    // Insert missing Sunday (13) to the list at index 1
    jan_sundays.insert(1,13);
    std::cout << "jan_sundays: " << jan_sundays << std::endl; // [6, 13, 20, 27]

    // Create a list of numbers in range(0,10) with step value of 2 (jump value)
    singly_linked_list<int> range_10 = {0,2,4,6,8};
    std::cout << "range_10: " << range_10 << std::endl; // [0, 2, 4, 6, 8]

    // Create a list that has the missing numbers of range_10 using loop
    // Reference for append usage: [append_example.cpp]
    singly_linked_list<int> missing_nums = {};
    for (int i=1; i <= 9; i+=2)
        missing_nums.append(i);
    std::cout << "missing_nums: " << missing_nums << std::endl; // [1, 3, 5, 7, 9]
    
    // Insert missing_nums values in range_10 in respective indices
    // Reference for operator[] usage: [operator_example.cpp] [index_example.cpp]
    for (int i=0; i < missing_nums.size(); i++) // missing_nums.size() is 5
        range_10.insert(missing_nums[i],missing_nums[i]); // operator [] is used to index into the list
    std::cout << "range_10: " << range_10 << std::endl; // [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

    // Create range_10_to_20 from 10 ro 20, initially
    singly_linked_list<int> range_10_to_20 = {11,12,13,14,15};

    // Prepend 10 to range_10_to_20
    // Reference for prepend usage: [prepend_example.cpp]
    range_10_to_20.prepend(10);

    // Append 16 to 20 using loop
    for (int i=16; i <= 20; i++)
        range_10_to_20.append(i);
    std::cout << "range_10_to_20: " << range_10_to_20 << std::endl; // [11, 12, 13, 14, 15, 16, 17, 18, 19, 20]

    // Create range_20 initialized to range_10
    singly_linked_list<int> range_20 = range_10;

    // Insert range_10_to_20 in range_20
    // at index -1 to insert at the end
    range_20.insert(-1,range_10_to_20); // Equivalent to, range_20.insert(10,range_10_to_20);
    std::cout << "range_20: " << range_20 << std::endl; // [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20]

    // Create range_11 initialized to range_10
    singly_linked_list<int> range_11 = range_10;

    // Insert at out of range index
    range_11.insert(100,11);
    std::cout << "range_11: " << range_11 << std::endl; // [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11]

    // Create a list of fibonacci numbers with some missing numbers
    singly_linked_list<int> fibonacci = {0,1,1,2,3,5,8,233};

    // Insert missing numbers as an initializer list at index 7
    fibonacci.insert(7,{13,21,34,55,89,144});
    std::cout << "fibonacci: " << fibonacci << std::endl; // [0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233]

    // Create an array with remaining fibonacci numbers
    int fibo_remaining[] = {377,610,987};

    // Insert remaining fibonacci numbers at index -1 (or 14)
    fibonacci.insert(-1,fibo_remaining);
    std::cout << "fibonacci: " << fibonacci << std::endl; // [0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987]

    // Create a list of prime numbers
    singly_linked_list<int> prime_numbers;

    // Create std::vector with prime numbers
    // Reference for std::vector usage: https://en.cppreference.com/w/cpp/container/vector/
    std::vector<int> primes = {2,3,5,7,11,13,17,19,23,29,31,37};

    // Insert primes at index 0 (can be any index)
    prime_numbers.insert(0,primes);
    std::cout << "prime_numbers: " << prime_numbers << std::endl; // [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37]

    return 0;
}
