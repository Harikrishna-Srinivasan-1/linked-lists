#include <fstream> // For files
#include <iostream>

#include "singly_linked_list.hpp"

int main()
{
    singly_linked_list<int> list1 = {1,2,3,4,5}, list2 = {77,88,99,110};

    // Display using show() method
    std::cout << "list1: "; //list1: 
    list1.show(); // [1, 2, 3, 4, 5]
    std::cout << std::endl;

    std::cout << "list2: "; // list2: 
    list2.show(); // [77, 88, 99, 110]
    std::cout << std::endl;

    singly_linked_list<char> char_list = "array"; // Initialized with array constructor - has null character at end

    // To remove '\0' character from the end
    char_list.pop();

    // Display using << (extraction) oerator
    std::cout << "char_list: " << char_list << std::endl; // char_list: [a, r, r, a, y]

    // Reference for using std::ofstream refer https://en.cppreference.com/w/cpp/header/fstream
    std::ofstream out_file("show_example.txt");
    if (out_file.is_open())
    {
        std::cout << "Open file: show_example.txt" << std::endl;
        out_file << "list1: " << list1 << std::endl; // list1: [1, 2, 3, 4, 5] - inside show_example.txt
        out_file.close();
    }

    else
        std::cerr << "Unable to open file for writing." << std::endl;
}