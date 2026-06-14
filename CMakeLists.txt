cmake_minimum_required(VERSION 3.14)
project(SafetyCriticalGraphics)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 14)

# Find OpenGL and GLFW local window packages
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

# Include GoogleTest via automated download fetchers
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        703bd9caab50b139428cea1aaff9974ebee5742e # release-1.10.0
)
FetchContent_MakeAvailable(googletest)

# 1. Build the Main Interactive Window Application
add_executable(safety_app src/main.c src/safety_display.c)
target_link_libraries(safety_app glfw OpenGL::GL)

# 2. Build the Automated Unit Test Runner
add_executable(run_unit_tests tests/test_display.cpp src/safety_display.c)
target_link_libraries(run_unit_tests gtest_main glfw OpenGL::GL)
