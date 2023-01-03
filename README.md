# Pong

## How to build

This project uses [CMake](https://cmake.org)(>= 3.25) to build, and requires a relatively modern C++ compiler (at least supports C++ 11).
The project also depends on [SDL2](https://www.libsdl.org), make sure it's presented on your system and CMake can find it.

### Build commands

```
git clone https://github.com/gshen42/Pong
cd Pong
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
make
```
If built successfully, an executable `pong` would be present in the `build` directory.

## How to Play

- Move your mouse to control the racket.
- Quit the game by pressing `q`.
