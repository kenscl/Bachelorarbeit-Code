project(sun-sensor-simulator)
cmake_minimum_required(VERSION 3.20)
add_subdirectory(rodos)
add_rodos_executable(sim light_source.h)
