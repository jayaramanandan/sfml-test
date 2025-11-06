#ifndef STARTBUTTON_HPP
#define STARTBUTTON_HPP

#include "UI/Button.hpp"

class StartButton : public builder::Button {
    public:
        StartButton();

        void init() override;
        void onClick() override;
};

#endif
