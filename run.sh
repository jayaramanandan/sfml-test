export DISPLAY=127.0.0.1:0
export XDG_RUNTIME_DIR=~/.cache/xdgr

cd src/modules/source
g++ ../../main.cpp Game.cpp Sprite.cpp -o ../../../build/main -lsfml-graphics -lsfml-window -lsfml-system
../../../build/main