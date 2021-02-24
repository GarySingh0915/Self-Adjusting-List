//Name: Gurnaman Singh
//Date: 2/15/2021
//Assignment: HW3 Self Adjusting List
//This program is used for performing sort operations that specifically finds a given element and inserts it at the front using Move-To-Front Method
#include <iostream>
#include <vector>

#include "self_adjusting_array.h"
int main()
{
    nwacc::self_adjusting_array<int> list(1U);
    std::cout << "Size 0, Cap 3, all nil values" << std::endl;
    std::cout << list << std::endl;

    list.push_front(1);
    std::cout << "Size 1, Cap 3, -5 nil nil " << std::endl;
    std::cout << list << std::endl;

    list.push_front(2);
    list.push_front(3);
    list.emplace_front(4);
    list.push_front(5);
    list.push_front(6);
    list.push_front(7);
    list.push_front(8);
    list.push_front(9);
    list.push_front(10);
    list.pop_front();
    std::cout << list << std::endl;

    std::cout << "Find Operation on Number 2" << std::endl;
    list.find(2);
    std::cout << list << std::endl;
    std::cout << "Find Operation on Number 3" << std::endl;
    list.find(3);
    std::cout << list << std::endl;

    // Using various data types to verify that class templates is functioning as it should be when defined.
    nwacc::self_adjusting_array<char> char_list(1U);
    std::cout << "THIS IS GOING TO BE A NEW CHAR LIST CLASS TEMPLATE" << std::endl;
    std::cout << "Size 0, Cap 3, all nil values" << std::endl;
    std::cout << char_list << std::endl;

    char_list.push_front('A');
    std::cout << char_list << std::endl;

    char_list.push_front('B');  
    char_list.emplace_front('C');
    char_list.push_front('D');
    std::cout << char_list << std::endl;

    std::cout << "Find Operation on Char C" << std::endl;
    char_list.find('C');
    std::cout << char_list << std::endl;
    std::cout << "Find Operation on Char B" << std::endl;
    char_list.find('B');
    std::cout << char_list << std::endl;
    char_list.pop_front();
    std::cout << char_list << std::endl;

    // The most basic version of the loop which print out every array list element 
    std::cout << "For - Expect to see 3 2 9 8 7 6 5 4 1" << std::endl;
    for (auto index = 0U; index < list.size(); index++) {
        std::cout << list[index] << " ";
    }

    std::cout << std::endl;

    // Using iterator functinality to access list through dereference iterator to access value, due to it being a pointer
    std::cout << "For WITH iterators - Expect to see 3 2 9 8 7 6 5 4 1" << std::endl;
    for (auto iterator = list.begin(); iterator != list.end(); iterator++) {
        std::cout << *iterator << " "; 
    }

    std::cout << std::endl;

    // Very similar to for loop. Only difference is format in this for-each loop.
    std::cout << "For each - Expect to see 3 2 9 8 7 6 5 4 1" << std::endl;
    for (const auto& value : list) {
        std::cout << value << " ";
    }

    std::cout << std::endl;

    list.emplace_front(45);
    std::cout << "size 10, cap 13, 45 3 2 9 8 7 6 5 4 1 nil nil nil" << std::endl;
    std::cout << list << std::endl;

    auto value = list.front();
    std::cout << "List Stays Exactly The Same. => Expect a value of 45 " << std::endl;
    std::cout << value << std::endl;
    std::cout << list << std::endl;

    list.pop_front();
    std::cout << "size 9, cap 13, 3 2 9 8 7 6 5 4 1 nil nil nil nil" << std::endl;
    std::cout << list << std::endl;

    // Calling move constructor and verifying it is working correctly
    nwacc::self_adjusting_array<char> moved_list(std::move(char_list));
    std::cout << moved_list << std::endl;

    // Calling copy assignment operator and verifying it is working correctly
    nwacc::self_adjusting_array<int> assignment_copy_list;
    assignment_copy_list = list;
    std::cout << "Validating that both the lists should be same" << std::endl;
    std::cout << "Old List : " << std::endl;
    std::cout << list << std::endl;
    std::cout << "New List Copy  : " << std::endl;
    std::cout << assignment_copy_list << std::endl;
    
    assignment_copy_list.push_front(30);
    std::cout << "New List Size 10, Cap 13, 30 3 2 9 8 7 6 5 4 1 nil " << std::endl;
    std::cout << assignment_copy_list << std::endl;
    std::cout << "Old List (Same) " << std::endl;
    std::cout << list << std::endl;

    // Calling copy constructor and verifying it is working correctly
    nwacc::self_adjusting_array<int> copy_oforiginal(list);
    std::cout << "Validating that both the lists should be same" << std::endl;
    std::cout << "Old List : " << std::endl;
    std::cout << list << std::endl;
    std::cout << "New List Copy  : " << std::endl;
    std::cout << copy_oforiginal << std::endl;

    copy_oforiginal.push_front(100);
    std::cout << "New List Size 10, Cap 13, 100 3 2 9 8 7 6 5 4 1 nil " << std::endl;
    std::cout << copy_oforiginal << std::endl;
    std::cout << "Old List (SAME)" << std::endl;
    std::cout << list << std::endl;
    
    return 0;
}