#include "easyfind.hpp"
#include <iostream>
#include <iterator>
#include <list>

int main() {
    std::cout << "--- Test Vector ---" << std::endl;
    std::vector<int> numbers;
    numbers.push_back(10);
    numbers.push_back(20);

    std::copy(numbers.begin(), numbers.end(),
              std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    try {
        std::vector<int>::iterator res = easyfind(numbers, 10);
        std::cout << "OK: We have found number " << *res << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "ERROR: " << e.what() << std::endl;
    }

    try {
        easyfind(numbers, 5);
    } catch (const std::exception &e) {
        std::cerr << "Expected error: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test List ---" << std::endl;
    std::list<int> linked_numbers;
    linked_numbers.push_back(100);
    linked_numbers.push_back(200);

    std::copy(linked_numbers.begin(), linked_numbers.end(),
              std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    try {
        std::list<int>::iterator res = easyfind(linked_numbers, 100);
        std::cout << "OK: We have found number " << *res << std::endl;

        easyfind(linked_numbers, 300);
    } catch (const std::exception &e) {
        std::cerr << "Expected error: " << e.what() << std::endl;
    }

    return 0;
}
