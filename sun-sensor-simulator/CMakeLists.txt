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
    math/matrix.h
    math/matrix.cpp
)

set(POLFIT
    polynomial_fit/polynomial_fit.h
    polynomial_fit/polynomial_fit.cpp
)

set(SINFIT
    sin_fit/sin_fit.h
    sin_fit/sin_fit.cpp
)
set(SOURCES 
    sun_sensor.h
    sun_sensor.cpp
    main.cpp
)

add_executable(${PROJECT_NAME} ${MATH} ${SOURCES} ${POLFIT} ${SINFIT})

target_include_directories(${PROJECT_NAME} PRIVATE ${MATPLOTLIB_CPP_DIR})
target_link_libraries(${PROJECT_NAME} PRIVATE ${Python3_LIBRARIES})

