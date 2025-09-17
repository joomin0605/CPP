cmake_minimum_required(VERSION 3.20)

set(PROJECT_NAME WEEK01)
set(CMAKE_CXX_STANDARD 17)

project(${PROJECT_NAME})
add_executable(${PROJECT_NAME}
    # src/main_vector3.cpp
    # src/main_rational.cpp
    src/main_stl.cpp
)