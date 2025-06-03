cmake_minimum_required(VERSION 3.15)
project(HeaderOnly LANGUAGES CXX)

include(CTest)

find_package(GeometricToolsEngine CONFIG REQUIRED)

add_library(SimpleGeometry DistanceUnitAlignedBoxes.h DistanceUnitAlignedBoxes.cpp)
target_link_libraries(SimpleGeometry PRIVATE GeometricToolsEngine::Mathematics)

# Create unit test target

find_package(GTest CONFIG REQUIRED)

include(GoogleTest)

add_executable(TestSimpleGeometry TestDistanceUnitAlignedBoxes.cpp)
target_link_libraries(TestSimpleGeometry PRIVATE SimpleGeometry GTest::gtest_main)

gtest_discover_tests(TestSimpleGeometry)
