#include "Span.hpp"

int main() {
    try {
        Span sp = Span(5);

        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;  
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;   

        // Try to add one more number (should throw exception)
        sp.addNumber(8);

    } catch (const std::exception &e) {
        std::cout  << e.what() << std::endl;
    }

    try {
        Span sp2 = Span(10);
        std::vector<int> nums = {5, 1, 8, 9, 3};
        sp2.addNumbers(nums.begin(), nums.end());

        std::cout << "Shortest Span: " << sp2.shortestSpan() << std::endl;  
        std::cout << "Longest Span: " << sp2.longestSpan() << std::endl;   

    } catch (const std::exception &e) {
        std::cout <<  e.what() << std::endl;
    }

    return 0;
}