cmake_minimum_required(VERSION 3.5)

project(sun-sensor-simulator CXX)

set(MATH
    math/matlib.h
    math/matlib.cpp
    )
set(SOURCES 
    particle.h
    particle.cpp
    light_source.h
    light_source.cpp
    plane.h
    plane.cpp
    black_body.h
    black_body.cpp
    )

add_executable(${PROJECT_NAME} ${MATH} ${SOURCES})
