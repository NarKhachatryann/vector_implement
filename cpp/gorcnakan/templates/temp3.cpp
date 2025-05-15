#include <iostream>

void print_Reverse() {}

template <typename First, typename... Args>
void print_Reverse(First first, Args... args) {
    print_Reverse(args...);
    std::cout << first << " ";
    std::cout << std::endl;
}

int main() {
    print_Reverse(1, 2.5, "Hello", 'A');
    return 0;
}