#include "string.h"
#include <ostream>
#include<iostream>
int main() {
    // Create an empty my_string
    my_string str1;
    std::cout << "str1: ";
    str1.print();

    // Create a my_string from a C-string
    my_string str2("Hello");
    std::cout << "str2: ";
    str2.print();

    // Copy constructor
    my_string str3(str2);
    std::cout << "str3 (copy of str2): ";
    str3.print();

    // Assignment operator
    my_string str4 = "World";
    std::cout << "str4: ";
    str4.print();
    str4 = str2;
    std::cout << "str4 (after assignment from str2): ";
    str4.print();

    // Concatenation using operator+=
    str2 += str4;
    std::cout << "str2 (after concatenation with str4): ";
    str2.print();

    // Concatenation using append()
    str3.append(str4);
    std::cout << "str3 (after append with str4): ";
    str3.print();

    std::cout << "str3[0]: " << str3[0] << std::endl;

    try {
        std::cout << "str3.at(1): " << str3.at(1) << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << e.what() << std::endl;
    }

    str3.push_back('!');
    std::cout << "str3 (after push_back): ";
    str3.print();

    str3.clear();
    std::cout << "str3 (after clear): ";
    str3.print();
    
    std::cout << "str3 size: " << str3.size() << std::endl;
    std::cout << "str3 empty: " << (str3.empty() ? "true" : "false") << std::endl;

    return 0;
}
