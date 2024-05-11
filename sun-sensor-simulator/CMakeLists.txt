cmake_minimum_required(VERSION 3.5)

project(sun-sensor-simulator CXX)
add_compile_options(-Wall)
add_compile_options(-g)
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
    sun_sensor.h
    sun_sensor.cpp
    )

add_executable(${PROJECT_NAME} ${MATH} ${SOURCES})
