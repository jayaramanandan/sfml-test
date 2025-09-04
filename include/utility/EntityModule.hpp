#ifndef ENTITYMODULE_HPP
#define ENTITYMODULE_HPP

namespace builder {
    enum class EntityModule : uint8_t {
        NotUsed,
        Animator,
        Collision,
        Motion,
        Sprite
    };
}

#endif
