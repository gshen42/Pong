cmake_minimum_required(VERSION 3.25)

project(Pong LANGUAGES CXX)

find_package(SDL2 REQUIRED)

add_executable(pong
               src/Main.cpp
               src/Game.h
               src/Game.cpp
               src/InputHandler.h
               src/InputHandler.cpp
               src/GameObject.h
               src/GameObject.cpp
               src/Player.h
               src/Player.cpp
               src/Ball.h
               src/Ball.cpp
               src/AI.h
               src/AI.cpp
               )
target_compile_features(pong PUBLIC cxx_std_17)
target_include_directories(pong PUBLIC "${SDL2_INCLUDE_DIRS}")
target_link_libraries(pong PUBLIC ${SDL2_LIBRARIES})

