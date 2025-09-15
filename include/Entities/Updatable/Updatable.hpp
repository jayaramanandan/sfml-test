#ifndef UPDATABLE_HPP
#define UPDATABLE_HPP

namespace builder {
    struct Updatable {
        virtual ~Updatable() = default;

        virtual void update() {};
    };
}

#endif
