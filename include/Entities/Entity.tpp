#ifndef ENTITY_TPP
#define ENTITY_TPP

#include "Entity.hpp"

namespace builder {
    template<ValidType T>
    EntityModule Entity<T>::getModule() {
        return EntityModule::NotUsed;
    }
}

#endif