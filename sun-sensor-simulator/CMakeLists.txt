cmake_minimum_required(VERSION 3.5)

project(sun-sensor-simulator CXX)
add_compile_options(-Wall)
set(CMAKE_CXX_STANDARD 11)

set(MATPLOTLIB_CPP_DIR "matplotlib-cpp/")

find_package(Python3 COMPONENTS Development NumPy REQUIRED)

include_directories(${MATPLOTLIB_CPP_DIR})
include_directories(${Python3_INCLUDE_DIRS} ${Python3_NumPy_INCLUDE_DIRS})

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
    misc.h
    main.cpp
)

add_executable(${PROJECT_NAME} ${MATH} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE ${MATPLOTLIB_CPP_DIR})
target_link_libraries(${PROJECT_NAME} PRIVATE ${Python3_LIBRARIES})

