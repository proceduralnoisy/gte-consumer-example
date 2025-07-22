# NOTE: This is a simple, barebones CMakeLists.txt file that may not represent best practices for more complex projects.

cmake_minimum_required(VERSION 3.15)
project(HeaderOnly LANGUAGES CXX)

# Setup unit testing

include(CTest)

find_package(GTest CONFIG REQUIRED)

# Create library target

find_package(GeometricToolsEngine CONFIG REQUIRED)

add_library(SimpleGeometry src/DistanceUnitAlignedBoxes.h src/DistanceUnitAlignedBoxes.cpp)
# Note: PRIVATE dependency does not propagate the GeometricToolsEngine dependency to downstream targets (i.e. the unit test target below)
target_link_libraries(SimpleGeometry PRIVATE GeometricToolsEngine::Mathematics)

# Create unit test target

add_executable(TestSimpleGeometry src/TestDistanceUnitAlignedBoxes.cpp)
target_link_libraries(TestSimpleGeometry PRIVATE SimpleGeometry GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(TestSimpleGeometry)
