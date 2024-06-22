#include <iostream>
#include <string>

class Person {
public:
    Person() {
        std::cout << "Person constructor called" << std::endl;
    }

    virtual ~Person() {
        std::cout << "Person destructor called" << std::endl;
    }

    // Other members...
private:
    std::string name;
    std::string address;
};

class Student: public Person {
public:
    Student() {
        std::cout << "Student constructor called" << std::endl;
    }

    virtual ~Student() {
        std::cout << "Student destructor called" << std::endl;
    }

    // Other members...
private:
    std::string schoolName;
    std::string schoolAddress;
};

bool validateStudent(Student s) {
    // Validation logic goes here...
    return true; // For demonstration purpose
}

int main() {
    Student plato;
    std::cout << "a"<<std::endl;
    bool platoIsOK = validateStudent(plato);
    std::cout << "Is Plato validated? " << (platoIsOK ? "Yes" : "No") << std::endl;
    return 0;
}
