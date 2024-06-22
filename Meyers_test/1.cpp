#include<iostream>
#include<string>
#include<vector>
void f1(const std::string& funcNAme){
    std::cout << funcNAme;
}
class A{
public:
    A(const A& rhs) : name(rhs.name) {
        f1("copy ctor");
    }
    A& operator=(const A& rhs){

        f1("operator=");
        name = rhs.name;
        return *this;
    }
private:
    std::string name;

};
int main() {

}
