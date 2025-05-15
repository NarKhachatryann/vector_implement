#include <iostream>
#include <type_traits>

template <typename T, typename = std::enable_if_t<std::is_integral_v<T> || std::is_floating_point_v<T>>>
class wrapper {
    private:
        T val;
    public:
        wrapper(T v) : val(std::is_floating_point_v<T> ? v * 1000 : v) {}

        void print() const {
            std::cout << "Value: " << val << std::endl;
        }
};

int main() {
    wrapper v(10);
    wrapper v2(11.02);
    v.print();
    v2.print();
}