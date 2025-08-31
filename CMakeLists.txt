cmake_minimum_required(VERSION 3.31)
project(SfmlWrapperApp VERSION 1.0)
include(FetchContent)
set(BUILD_SHARED_LIBS OFF)
FetchContent_Declare(
        SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.1
)
FetchContent_MakeAvailable(SFML)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)
set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)

add_library(
        SfmlWrapper STATIC
        test/Player.cpp
        lib/Entities/Animator.cpp
        lib/Game.cpp
        lib/Entities/Sprite.cpp
        lib/utility/maths.cpp
        test/BowlGame.cpp
        lib/UI/Button.cpp
        lib/GameManager.cpp
        include/Scene.cpp
        include/Scene.hpp
)

target_include_directories(
        SfmlWrapper
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_executable(
        SfmlWrapperApp
        src/main.cpp
)

# Copy assets directory to build directory
add_custom_target(copy_assets ALL
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/assets
        ${CMAKE_CURRENT_BINARY_DIR}/assets
)

add_dependencies(SfmlWrapperApp copy_assets)

target_link_libraries(
        SfmlWrapper
        PUBLIC sfml-graphics
)

target_link_libraries(
        SfmlWrapperApp
        PRIVATE SfmlWrapper
)