cmake_minimum_required(VERSION 3.10)

project(KaysinsGE)

find_package(fmt CONFIG REQUIRED)
find_package(SDL3 CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)

add_executable(KaysinsGE main.cpp)
set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT KaysinsGE)

add_library(glad STATIC external/glad/src/glad.c)
target_include_directories(glad PUBLIC external/glad/include)

target_link_libraries(KaysinsGE PRIVATE fmt::fmt SDL3::SDL3 glad imgui::imgui)