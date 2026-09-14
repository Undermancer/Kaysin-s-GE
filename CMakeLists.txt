cmake_minimum_required(VERSION 3.10)

project(KaysinsGE)

find_package(fmt CONFIG REQUIRED)
find_package(SDL3 CONFIG REQUIRED)

add_executable(KaysinsGE main.cpp)

target_link_libraries(KaysinsGE PRIVATE fmt::fmt SDL3::SDL3)