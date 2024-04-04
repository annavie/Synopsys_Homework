#include <iostream>
#include <string>

using namespace std;

struct TypeInfo {
  string class_name;
  string base_name;
};

const TypeInfo Base_type = {"Base", ""};
const TypeInfo Derived_type = {"Derived", "Base"};
struct Base {
  virtual const TypeInfo* get_type_info() const { return vptr->type_info; }
  virtual void vf(Base* ptr) { /* pure virtual */ }
  BaseVTbl* vptr;
};

struct Derived : public Base {
  int derivedData;
  void vf(Derived* ptr) override { foo_derived(ptr); }
};
struct BaseVTbl {
  const TypeInfo* type_info;
  void (*vf)(Base*);
};

struct DerivedVTbl : public BaseVTbl {
  void (*vf)(Derived*);
};

extern const BaseVTbl basevtbl = {&Base_type, &foo_base};
extern const DerivedVTbl derivedvtbl = {&Derived_type, &foo_derived};



bool is_type_compatible(const TypeInfo* srcType, const TypeInfo* destType) {
  return srcType->base_name == destType->class_name;
}

void* DynamicCast(void* ptr, const TypeInfo* destType) {
  Base* basePtr = static_cast<Base*>(ptr);
  if (!basePtr) {
    return nullptr;
  }

  if (is_type_compatible(basePtr->get_type_info(), destType)) {
    return ptr;
  } else {
    return nullptr;
  }
}

int main() {
  Derived derivedObj;
  derivedObj.derivedData = 52;
  derivedObj.vptr = const_cast<DerivedVTbl*>(&derivedvtbl); // C++ requires const_cast

  Base* basePtr = dynamic_cast<Base*>(&derivedObj);

  if (basePtr) {
    Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);
    if (derivedPtr) {
      cout << "Downcast successful. Derived data: " << derivedPtr->derivedData << endl;
    } else {
      cout << "Failed to downcast to Derived" << endl;
    }
  } else {
    cout << "Downcast failed." << endl;
  }
}
