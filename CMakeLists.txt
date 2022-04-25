cmake_minimum_required(VERSION 3.21)
project(MenuSDL)

set(CMAKE_CXX_STANDARD 14)

set(SDL2_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include/SDL2)
set(SDL2_LIB_DIR ${CMAKE_SOURCE_DIR}/lib/SDL2)
include_directories(${SDL2_INCLUDE_DIR})
link_directories(${SDL2_LIB_DIR})

file(GLOB_RECURSE SOURCES
        src/main.cpp
        src/Color/Color.h
        src/RenderWindow/RenderWindow.cpp src/RenderWindow/RenderWindow.h
        src/Button/Button.cpp src/Button/Button.h
        src/Text/Text.cpp src/Text/Text.h
)

add_executable(MenuSDL ${SOURCES} src/Menu/Menu.cpp src/Menu/Menu.h)
target_link_libraries(${PROJECT_NAME} mingw32 SDL2main SDL2 SDL2_image)