#ifndef INITIALISABLE_HPP
#define INITIALISABLE_HPP

namespace builder {
    struct Initialisable {
        virtual ~Initialisable() = default;

        virtual void init() {};
    };
}

#endif
