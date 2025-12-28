#include "Span.hpp"
#include <algorithm>

// Orthodox Canonical Form
Span::Span(void) { _maxSize = 0; }
Span::Span(Span const &other)
    : _maxSize(other._maxSize), _numbers(other._numbers) {}
Span &Span::operator=(Span const &other) {
    if (this != &other) {
        _maxSize = other._maxSize;
        _numbers = other._numbers;
    }
    return *this;
}
Span::~Span(void) {}

Span::Span(unsigned int N) : _maxSize(N) {}

void Span::addNumber(int number) {
    if (_numbers.size() < _maxSize) {
        _numbers.push_back(number);
    } else {
        throw Span::SpanFullException();
    }
}

int Span::longestSpan() const {
    if (_numbers.size() < 2)
        throw Span::NoSpanException();
    std::vector<int>::const_iterator minIt =
        std::min_element(_numbers.begin(), _numbers.end());
    std::vector<int>::const_iterator maxIt =
        std::max_element(_numbers.begin(), _numbers.end());

    return (*maxIt - *minIt);
}

int Span::shortestSpan() const {
    if (_numbers.size() < 2)
        throw Span::NoSpanException();
    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());
    int min = sorted[1] - sorted[0];
    for (size_t i = 1; i < sorted.size() - 1; i++) {
        if (sorted[i + 1] - sorted[i] < min) {
            min = sorted[i + 1] - sorted[i];
        }
    }
    return min;
}

const char *Span::SpanFullException::what() const throw() {
    return "Span is full. You can't add more numbers.";
}

const char *Span::NoSpanException::what() const throw() {
    return "No span is found.";
}
