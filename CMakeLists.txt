cmake_minimum_required(VERSION 3.15)

project(AutoclickerMause)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(AutoclickerMause main.cpp)

target_link_options(AutoclickerMause PRIVATE -static -static-libstdc++)