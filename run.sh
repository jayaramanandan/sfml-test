export DISPLAY=127.0.0.1:0
export XDG_RUNTIME_DIR=~/.cache/xdgr

cd src/modules
g++ ../main.cpp Motion/Motion.cpp Animator/Animator.cpp Sprite/Sprite.cpp Game/Game.cpp ../Player.cpp -o ../../build/main -lsfml-graphics -lsfml-window -lsfml-system
../../build/main