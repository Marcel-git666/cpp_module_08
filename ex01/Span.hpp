#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
class Span {
  private:
    unsigned int _maxSize;
    std::vector<int> _numbers;

  public:
    // Orthodox Canonical Form
    Span(void);
    Span(Span const &other);
    Span &operator=(Span const &other);
    ~Span(void);

    // Other methods
    Span(unsigned int N);
    void addNumber(int number);
    template <typename Iterator> void addNumber(Iterator begin, Iterator end) {
        unsigned int dist = std::distance(begin, end);
        if (_numbers.size() + dist > _maxSize) {
            throw Span::SpanFullException();
        }
        _numbers.insert(_numbers.end(), begin, end);
    }
    int longestSpan() const;
    int shortestSpan() const;

    // Exceptions
    class SpanFullException : public std::exception {
        const char *what() const throw();
    };

    class NoSpanException : public std::exception {
        const char *what() const throw();
    };
};

#endif
