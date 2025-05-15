#include <iostream>
#include <type_traits>

template <typename T>
std::enable_if_t<std::is_polymorphic_v<T>, T*> cloneObject(T* obj) {
    return obj ? new T(*obj) : nullptr;
}

struct base {
    virtual void print() {
        std::cout << "Base class print" << std::endl;
    }
};

struct derived : public base {
    void print() override {
        std::cout << "Derived class print" << std::endl;
    }
};

int main() {
    derived obj;
    base* clonedObj = cloneObject(&obj);

    if (clonedObj) {
        std::cout << "Cloned object created." << std::endl;
    } else {
        std::cout << "No object to clone." << std::endl;
    }
    
    if (clonedObj) {
        clonedObj->print();
        delete clonedObj;
    }
    
    return 0;
}