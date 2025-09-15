#ifndef ENTITYDETAILS_HPP
#define ENTITYDETAILS_HPP

#include <vector>
#include "Entities/Initialisable/Initialisable.hpp"
#include "Entities/Updatable/Updatable.hpp"

namespace builder {
    template <typename T>
    struct EntityDetails {
        T* entity_ptr = nullptr;
    };

    struct InitiationPhaseEntityDetails : EntityDetails<Initialisable> {
        bool animationModule = false;
    };

    template <class ST>
    struct EventPhaseEntityDetails : EntityDetails<ST> {
        bool clickListenerModule = false;
    };

    struct UpdatePhaseEntityDetails : EntityDetails<Updatable> {
        bool hoverListenerModule = false;
    };

    // Used to store entities that need to be iterated during initialisation phase
    template <class ST>
    using InitiationArray = std::vector<InitiationPhaseEntityDetails>;

    // Used to store entities that need to be iterated during event poll phase
    template <class ST>
    using EventArray = std::vector<EventPhaseEntityDetails<ST>>;

    // Used to store entities that need to be iterated during update and draw phase
    template <class ST>
    using UpdateArray = std::vector<UpdatePhaseEntityDetails>;
}

#endif
