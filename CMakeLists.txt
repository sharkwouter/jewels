cmake_minimum_required(VERSION 3.0)

project(jewels)

file(GLOB_RECURSE SRC src/*.c)

add_executable(${CMAKE_PROJECT_NAME} ${SRC})

find_package(PkgConfig REQUIRED)
pkg_search_module(SDL2 REQUIRED sdl2)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${SDL2_INCLUDE_DIRS}
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    ${SDL2_LIBRARIES}
)