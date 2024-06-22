#ifndef MY_STRING_H
#define MY_STRING_H

#include <iostream>
#include <cstring>
#include <stdexcept>

class my_string {
public:
    my_string();
    my_string(const char* data);
    my_string(const my_string& other);

    ~my_string();

    my_string& operator=(const my_string& rhs);

    my_string& operator+=(const my_string& rhs);
    my_string& append(const my_string& rhs);

    char& operator[](int index);
    char at(int index) const;

    void push_back(char ch);
    void clear();
    int size() const;
    bool empty() const;
    void print() const;

private:
    union {
        struct {
            char* ptr;
            int size;
        } str;
        char onstack[16]; 
    } string;
};

#endif // MY_STRING_H
