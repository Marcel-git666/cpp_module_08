#include "Span.hpp"
#include <cstdlib> // Pro rand
#include <ctime>   // Pro srand
#include <iostream>
#include <list>
#include <vector>

int main() {
    Span sp(15000);
    std::cout << "\n--- Test with Vector ---" << std::endl;
    std::vector<int> numbers;
    srand(time(NULL));
    for (int i = 0; i < 10000; i++) {
        numbers.push_back(rand());
    }

    try {
        sp.addNumber(numbers.begin(), numbers.end());
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << '\n';
    }

    try {
        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << '\n';
    }

    Span sp2(3);
    std::list<int> listNumbers;
    listNumbers.push_back(1);
    listNumbers.push_back(100);
    listNumbers.push_back(50);
    std::cout << "\n--- Exceptions Test with List ---" << std::endl;
    try {
        std::cout << "Shortest Span: " << sp2.shortestSpan() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << '\n';
    }
    try {
        std::cout << "Longest Span: " << sp2.longestSpan() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << '\n';
    }

    sp2.addNumber(listNumbers.begin(), listNumbers.end());
    std::cout << "\n--- Test with List ---" << std::endl;
    std::cout << "Shortest (List): " << sp2.shortestSpan() << std::endl;
    try {
        sp2.addNumber(222);
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << '\n';
    }
    return 0;
}
