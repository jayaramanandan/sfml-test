#ifndef DICTIONARY_HPP
#define DICTIONARY_HPP

#include <string>
#include <unordered_map>

namespace builder {
    template <typename T>
    using Dictionary = std::unordered_map<std::string, T>;
}

#endif
