#include "Span.hpp"

Span::Span() : _n(0), _vec(0) {}

Span::Span(unsigned int n) : _n(n), _vec(0) {}

Span::Span(Span const &src) {
    *this = src;
}

Span::~Span() {}

Span &Span::operator=(Span const &src) {
    if (this != &src) {
        _n = src._n;
        _vec = src._vec;
    }
    return *this;
}

void Span::addNumber(int n) {
    if (_vec.size() < _n)
        _vec.push_back(n);
    else
        throw Span::TooManyNumbersException();
}

const char * Span::NoSpanException::what() const throw() {
    const char *msg = "No span to find";
    return msg;
}


int Span::shortestSpan() {
    if (_vec.size() < 2)
        throw Span::NoSpanException();
    std::vector<int> tmp = _vec;
    std::sort(tmp.begin(), tmp.end());
    int min = tmp[1] - tmp[0];
 //   std::cout << "Shortest span: " << tmp[1] - tmp[0] << std::endl;
    for (size_t i = 1; i < tmp.size(); i++) {
        if (tmp[i] - tmp[i - 1] < min)
            min = tmp[i] - tmp[i - 1];
    }
    return min;
}

int Span::longestSpan() {
    if (_vec.size() < 2)
        throw Span::NoSpanException();
    std::vector<int> tmp = _vec;
    std::sort(tmp.begin(), tmp.end());
    return tmp[tmp.size() - 1] - tmp[0];
}

const char * Span::TooManyNumbersException::what() const throw() {
    const char * msg = "Too many numbers";
    return msg;
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    if (_vec.size() + std::distance(begin, end) > _n)
        throw Span::TooManyNumbersException();
    _vec.insert(_vec.end(), begin, end);
}

const std::vector<int>& Span::getVec() const {
    return _vec;
}

std::ostream &operator<<(std::ostream &o,  Span &span) {
    for (size_t i = 0; i < span.getVec().size(); i++) {
        o << span.getVec()[i];
        if (i < span.getVec().size() - 1)
            o << " ";
    }
    return o;
}