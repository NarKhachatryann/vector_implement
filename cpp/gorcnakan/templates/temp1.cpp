#include <iostream>

template <typename T, typename... Args>
T maxArgs(T first, Args... args) {
    return ((first = std::max(first, args)), ...);
}

int main() {
    std::cout << maxArgs(1, 2, 3, 4, 5) << std::endl;
    return 0;
}