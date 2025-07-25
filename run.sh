export DISPLAY=127.0.0.1:0
export XDG_RUNTIME_DIR=~/.cache/xdgr

g++ ./src/main.cpp -o ./build/main -lsfml-graphics -lsfml-window -lsfml-system
./build/main