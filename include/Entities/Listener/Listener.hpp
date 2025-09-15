#ifndef LISTENER_HPP
#define LISTENER_HPP

#include <tuple>

namespace builder {
    template <typename... Args>
    struct Listener {
        using is_listener_tag = void;  // marker
        using listeners = std::tuple<Args...>;

        static void onClick() {};
        static void onHover() {};
    };
}

#endif
