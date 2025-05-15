#include <iostream>
#include <type_traits>

template <typename T>
std::enable_if_t<std::is_abstract_v<T>, void>
describeType() {
    std::cout << "This is an abstract type." << std::endl;
}

template <typename T>
std::enable_if_t<std::is_polymorphic_v<T> && !std::is_abstract_v<T>, void>
describeType() {
    std::cout << "This is a polymorphic type." << std::endl;
}

template <typename T>
std::enable_if_t<!std::is_abstract_v<T> && !std::is_polymorphic_v<T>, void>
describeType() {
    std::cout << "This is a non-polymorphic, non-abstract type." << std::endl;
}

class abstractBase {
public:
    virtual void foo() = 0;
};

class polimorphicBase {
public:
    virtual void foo() {}
};

class neutral {};

int main() {
    describeType<abstractBase>();
    describeType<polimorphicBase>();
    describeType<neutral>();
    return 0;
}