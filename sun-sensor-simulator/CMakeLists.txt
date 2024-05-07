cmake_minimum_required(VERSION 3.2)

project(sun-sensor-simulator CXX)

set(SOURCES 
    black_body.h
    black_body.cpp
    matlib.h
    matlib.cpp
    light_source.h
    light_source.cpp
    )

add_executable(${PROJECT_NAME} ${SOURCES})
