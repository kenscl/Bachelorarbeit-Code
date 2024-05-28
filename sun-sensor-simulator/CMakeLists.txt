cmake_minimum_required(VERSION 3.5)

project(sun-sensor-simulator CXX)
add_compile_options(-Wall)
set(CMAKE_CXX_STANDARD 11)

# Add GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

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

set(MATPLOTLIB_CPP_DIR "matplotlib-cpp/")

find_package(Python3 COMPONENTS Development NumPy REQUIRED)

include_directories(${MATPLOTLIB_CPP_DIR})
include_directories(${Python3_INCLUDE_DIRS} ${Python3_NumPy_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} ${MATH} ${SOURCES} ${POLFIT} ${SINFIT})
target_include_directories(${PROJECT_NAME} PRIVATE ${MATPLOTLIB_CPP_DIR})
target_link_libraries(${PROJECT_NAME} PRIVATE ${Python3_LIBRARIES})

# Test executable without matplotlib-cpp and Python3
enable_testing()

add_executable(all_tests test/test_matrix.cpp ${MATH} ${POLFIT} ${SINFIT})
target_link_libraries(all_tests gtest gtest_main)

add_test(NAME MatrixTest COMMAND all_tests)
