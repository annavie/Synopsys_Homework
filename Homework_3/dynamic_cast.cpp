#include <iostream>
#include <typeinfo>

class Base {
public:
    virtual void print() {
        std::cout << "Base class" << std::endl;
    }
};

class Derived : public Base {
public:
    void print() override {
        std::cout << "Derived class" << std::endl;
    }
};
class Derived2 : public Base {
public:
    void print() override {
        std::cout << "Derived2 class" << std::endl;
    }
};
class Derived3 : public Base {
public:
    void print() override {
        std::cout << "Derived3 class" << std::endl;
    }
};

template <typename D, typename Bp>
D* dynCast(Bp ptr) {
    if (typeid(D) == typeid(*ptr)) {
        return static_cast<D*>(ptr);
    }
    return nullptr;
}
void testMyDyn(Base* ptr) {
   Derived* dptr = dynCast<Derived>(ptr);
   if (dptr) {
    dptr->print();
     return;
   }
   Derived2* dptr2 = dynCast<Derived2>(ptr);
   if (dptr2) {
     dptr2->print();
     return;
   }
   Derived3* dptr3 = dynCast<Derived3>(ptr);
   if (dptr3) {
     dptr3->print();
     return;
   }
   std::cout << "not a derived type" << std::endl;
}

int main() {
   Base* ptr1 = new Derived();
   Base* ptr2 = new Derived2();
   Base* ptr3 = new Derived3();
   testMyDyn(ptr1);
   testMyDyn(ptr2);
   testMyDyn(ptr3);
   testMyDyn(new Base());

    return 0;
}