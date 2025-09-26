#ifndef MODULES_HPP
#define MODULES_HPP

namespace builder {
    template <typename... Args>
    struct Modules : Args... {};
}

#endif
