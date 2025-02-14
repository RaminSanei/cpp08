#ifndef EASY_FIND_TPP
# define EASY_FIND_TPP

#include <iostream>
#include <algorithm>
#include <list>
#include <vector>

template <typename T>
typename T::iterator easyfind(T &container, int value) {
    typename T::iterator iterator = std::find(container.begin(), container.end(), value);
    
    if (iterator != container.end()) {
        return iterator;
    } else {
        std::string error_message = "Value not found in container";
        throw std::runtime_error(error_message);
    }
}

#endif