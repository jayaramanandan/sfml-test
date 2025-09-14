#ifndef ENTITYSTORE_HPP
#define ENTITYSTORE_HPP

#include "Entities/Listener/Listener.hpp"
#include "Entities/Animator/Animator.hpp"

namespace builder {
    // Listener class related

    template <typename T, typename = void>
    struct is_listener : std::false_type {};

    template <typename T>
    struct is_listener<T, std::void_t<typename T::is_listener_tag>> : std::true_type {};

    template <typename T>
    inline constexpr bool is_listener_v = is_listener<T>::value;

    //storage class related

    template <class U>
    using PointerArray = std::vector<U*>;

    template <class ST>
    struct ListenerIndexes {
        PointerArray<ST> clickListeners;
        std::vector<PointerArray<ST>> hoverListeners;
    };

    template <class ST>
    class EntityStore {
        private:
            PointerArray<ST> entities;
            PointerArray<ST> animationEntities;

        public:
            ListenerIndexes<ST> listenerEntities;

            PointerArray<ST>& getEntities();

            template <class ET, std::size_t... I>
            void iterateListeners(ET* entity, std::index_sequence<I...>);

            template <class ET, typename LT>
            void addListenerEntity(ET* entity);

            template <class ET>
            void addEntity(ET* entity);
    };
}

#include "EntityStore.tpp"

#endif
