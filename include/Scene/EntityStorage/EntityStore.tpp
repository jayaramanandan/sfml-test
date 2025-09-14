#ifndef ENTITYSTORE_TPP
#define ENTITYSTORE_TPP


#include "EntityStore.hpp"

#include <type_traits>
#include <iostream>
#include "Entities/Listener/listeners/ClickListener.hpp"
#include "Entities/Listener/listeners/HoverListener.hpp"

namespace builder {
    template<class ST>
    template<class ET, std::size_t... I>
    void EntityStore<ST>::iterateListeners(ET* entity, std::index_sequence<I...>) {
        using listeners_tuple = typename ET::listeners;
        (this->addListenerEntity<ET, std::tuple_element_t<I, listeners_tuple>>(entity), ...);
    }

    template<class ST>
    template<class ET, typename LT>
    void EntityStore<ST>::addListenerEntity(ET* entity) {
        if constexpr (std::is_same_v<LT, ClickListener>) {
            this->listenerEntities.clickListeners.push_back(entity);
        } else if constexpr (std::is_same_v<LT, HoverListener>) {
            this->listenerEntities.hoverListeners.push_back(entity);
        }
    }

    template <class ST>
    template <class ET>
    void EntityStore<ST>::addEntity(ET* entity) {
        static_assert(std::is_base_of_v<ST, ET>, "The added entity type 'ET' is not derived from storage type 'ST'");

        if constexpr (is_listener_v<ET>) {
            using listeners_tuple = typename ET::listeners;
            this->iterateListeners(entity, std::make_index_sequence<std::tuple_size_v<listeners_tuple>>{});
        }

        if constexpr (std::is_base_of_v<Animator, ET>) this->animationEntities.push_back(entity);

        entities.push_back(entity);
    }

    template<class T>
    PointerArray<T>& EntityStore<T>::getEntities() {
        return this->entities;
    }

}

#endif
