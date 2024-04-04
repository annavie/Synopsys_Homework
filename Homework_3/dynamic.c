#include <stdio.h>
#include <string.h> 

void foo_base(struct Base* ptr)
{
  printf("base");
}


void foo_derived(struct Derived* ptr)
{
  printf("derived");
}

struct TypeInfo {
    const char* class_name;
    const char* base_name;
};

static const struct TypeInfo Base_type = {"Base", NULL };
static const struct TypeInfo Derived_type = {"Derived", "Base"};

struct BaseVTbl {
    const struct TypeInfo *const type_info;
    void (*vf)(struct Base*);
};

struct DerivedVTbl {
    const struct TypeInfo *const type_info;
    void (*vf)(struct Derived*);
};

extern  const struct BaseVTbl basevtbl = {&Base_type, &foo_base};
extern  const struct DerivedVTbl derivedvtbl = {&Derived_type, &foo_derived};

struct Base {
    struct BaseVTbl* vptr; 
};

struct Derived {
    struct Base base;
    int derivedData;
};

int is_type_compatible(const struct TypeInfo* srcType, const struct TypeInfo* destType) {
    return (strcmp(srcType->base_name, destType->class_name) == 0);
}

void* DynamicCast(void* ptr, const struct TypeInfo* destType) {
    struct TypeInfo ***basePtr = (struct TypeInfo ***)ptr;
    if (**basePtr == NULL) {
        return NULL;
    }

    if (is_type_compatible(&(***basePtr), destType)) { 
        return ptr;
    } else {
        return NULL;
    }
}

int main() {
    struct Derived derivedObj;
    derivedObj.base.vptr = (struct BaseVTbl*)&derivedvtbl;
    derivedObj.derivedData = 52;

    struct Base* basePtr = (struct Base*)DynamicCast(&derivedObj, &Base_type);

    if (basePtr != NULL) {
        struct Derived* derivedPtr = (struct Derived*)basePtr;
        printf("Downcast successful. Derived data: %d\n", derivedPtr->derivedData);
    } else {
        printf("Downcast failed.\n");
    }
}