#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <sstream>
#include <stdexcept>

template <typename T> typename T::iterator easyfind(T &haystack, int needle) {
    typename T::iterator it =
        std::find(haystack.begin(), haystack.end(), needle);
    if (it == haystack.end()) {
        std::stringstream ss;
        ss << "Element " << needle << " not found";
        throw std::runtime_error(ss.str());
    }
    return it;
}

#endif
