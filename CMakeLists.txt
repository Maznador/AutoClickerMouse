cmake_minimum_required(VERSION 3.15)

project(AutoclickerMause)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXE_LINKER_FLAGS "-static -static-libgcc -static-libstdc++")

add_executable(AutoclickerMause src/main.cpp)

target_link_options(AutoclickerMause PRIVATE -static -static-libstdc++)