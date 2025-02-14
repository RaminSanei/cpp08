#include "easyfind.hpp"

int main() {
    try {
        std::vector<int> vec = {1, 2, 3, 4, 5};
        auto it1 = easyfind(vec, 3);
        std::cout << "Found value: " << *it1 << std::endl;  
        std::list<int> lst = {10, 20, 30, 40};
        auto it2 = easyfind(lst, 30);
        std::cout << "Found value: " << *it2 << std::endl;  
        auto it3 = easyfind(vec, 6);  
        std::cout << "Found value: " << *it3 << std::endl;
    } catch (const std::runtime_error &e) {
        std::cout << e.what() << std::endl;
    }
    
    return 0;
}