#ifndef ENTITYSTORE_HPP
#define ENTITYSTORE_HPP

#include "EntityDetails.hpp"
#include "Entities/Animator/Animator.hpp"

namespace builder {
    template <class ST>
    class EntityStore {
        private:
            InitiationArray<ST> initiationEntities;
            EventArray<ST> eventEntities;
            UpdateArray<ST> updateEntities;

        public:
            [[nodiscard]] InitiationArray<ST>& getInitiationEntities();

            [[nodiscard]] EventArray<ST>& getEventEntities();

            [[nodiscard]] UpdateArray<ST>& getUpdateEntities();

            template <class ET, std::size_t... I>
            void iterateListeners(ET* entity, std::index_sequence<I...>);

            template <typename ET, typename LT>
            void addListenerEntity(ET* entity);

            template <class ET>
            void addEntity(ET* entity);
    };
}

#include "EntityStore.tpp"

#endif
