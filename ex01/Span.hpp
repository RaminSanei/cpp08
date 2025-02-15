#ifndef SPAN_HPP
# define SPAN_HPP

#include <list>
#include <vector>
#include <iostream>

class Span {
    private:
        unsigned int _n;
        std::vector<int> _vec;
    public:
        Span();
        Span(unsigned int n);
        Span(const Span &src);
        ~Span();
        Span &operator=(const Span &rhs);
        void addNumber(int n);
        void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        int shortestSpan();
        int longestSpan();
        const std::vector<int>& getVec() const;
        class NoSpanException : public std::exception {
            public:
                virtual const char *what() const throw();
        };
        class TooManyNumbersException : public std::exception {
            public:
                virtual const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &o,  Span &span);

#endif