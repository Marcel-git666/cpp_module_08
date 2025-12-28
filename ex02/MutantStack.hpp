#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
template <typename T> class MutantStack : public std::stack<T> {
  private:
  public:
    // Orthodox Canonical Form
    MutantStack() : std::stack<T>() {}
    MutantStack(MutantStack const &other) : std::stack<T>(other) {}
    MutantStack &operator=(MutantStack const &other) {
        if (this != &other) {
            std::stack<T>::operator=(other);
        }
        return *this;
    }
    ~MutantStack() {}

    // Other methods
    typedef typename std::stack<T>::container_type::iterator iterator;
    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }
};

#endif
