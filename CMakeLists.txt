cmake_minimum_required(VERSION 3.28)
project(Tetris)

set(CMAKE_CXX_STANDARD 20)
include(FetchContent)

FetchContent_declare(
        sfml
        GIT_REPOSITORY https://github.com/SFML/SFML
        GIT_TAG 2.6.1
)
FetchContent_MakeAvailable(sfml)

add_executable(Tetris main.cpp pieces.cpp board.cpp game.cpp IO.cpp)
target_link_libraries(Tetris sfml-system sfml-window sfml-graphics)
