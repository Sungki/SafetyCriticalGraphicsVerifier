cmake_minimum_required(VERSION 3.14)
project(SafetyCriticalGraphics)

# Ensure modern compiler compliance
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 14)

# 1. Locate System OpenGL (Pre-installed on GitHub Runners)
find_package(OpenGL REQUIRED)

# 2. Automated Safe Dependency Fetching (Using Immutable Git Tags)
include(FetchContent)

# Fetch GoogleTest safely using target tags
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com
  GIT_TAG        v1.15.2   # Stable production release
  GIT_SHALLOW    ON        # Optimized download speed
)

# Fetch GLFW safely using target tags
FetchContent_Declare(
  glfw
  GIT_REPOSITORY https://github.com
  GIT_TAG        3.3.8     # Proven stable window framework
  GIT_SHALLOW    ON
)

# Disable unnecessary downstream targets to speed up your GitHub CI pipeline
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

# Download and make packages available to targets below
FetchContent_MakeAvailable(googletest glfw)

# 3. Target Definition: Main Application Window
add_executable(safety_app src/main.c src/safety_display.c)
target_link_libraries(safety_app glfw OpenGL::GL)

# 4. Target Definition: Automated GoogleTest Verification Runner
add_executable(run_unit_tests tests/test_display.cpp src/safety_display.c)
target_link_libraries(run_unit_tests gtest_main glfw OpenGL::GL)
