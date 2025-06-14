#include <iostream>

class TypeInfo {
public:
    std::string className;

    TypeInfo(const std::string& name) : className(name) {}
};

struct VTable {
    TypeInfo* typeInfo;
    void (*function1)();
    void (*function2)();
};

struct Offset {
    int callOffset;
    int topOffset;
    int baseOffset;
};

void thunkFunction(void* thisPtr, Offset offset) {
    char* adjustedPtr = reinterpret_cast<char*>(thisPtr) + offset.baseOffset;
}

class Base {
public:
    virtual void sayHello() {
        std::cout << "Hello from Base!" << std::endl;
    }
};

class Derived : public Base {
public:
    void sayHello() override {
        std::cout << "Hello from Derived!" << std::endl;
    }
};

int main() {

    Base baseObj;
    Derived derivedObj;

    VTable baseVTable = { new TypeInfo("Base"), []() { Base().sayHello(); } };
    VTable derivedVTable = { new TypeInfo("Derived"), []() { Derived().sayHello(); } };

    Base* basePtr = &baseObj;
    Base* derivedPtr = &derivedObj;

    std::cout << "Calling Base's function through vtable:" << std::endl;
    baseVTable.function1();

    std::cout << "Calling Derived's function through vtable:" << std::endl;
    derivedVTable.function1();

    std::cout << "TypeInfo for Base: " << baseVTable.typeInfo->className << std::endl;
    std::cout << "TypeInfo for Derived: " << derivedVTable.typeInfo->className << std::endl;

    return 0;
}
