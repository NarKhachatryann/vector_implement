#include <iostream>
#include <string>
#include <algorithm>

template <typename ... Args>
void printArgs(Args... args) {
    ((std::cout << args << ", "), ...) << std::endl;
}

template <typename ...T>
auto printUpper(T ...arg) {
    auto upper = [] (std::string s) {
        std::transform(s.begin(), s.end(), s.begin(), ::toupper);
        return s;
    };

    ((std::cout << upper(arg) << " "), ...) << std::endl;
}

int main() {
    printUpper("Hello", "World", "C++", "Templates");
    return 0;
}