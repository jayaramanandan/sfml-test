#ifndef IS_LISTENER_HPP
#define IS_LISTENER_HPP

#include <type_traits>

namespace builder {
    template <typename T, typename = void>
    struct is_listener : std::false_type {};

    template <typename T>
    struct is_listener<T, std::void_t<typename T::is_listener_tag>> : std::true_type {};

    template <typename T>
    inline constexpr bool is_listener_v = is_listener<T>::value;
}

#endif
