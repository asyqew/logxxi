# CMakeLists.txt — Build configuration for Logxxi (header-only C++ logger framework)
# This file is used to compile examples and tests.
# The library itself is header-only, so no separate library target is built.

# Minimum required CMake version (modern C++ features support)
cmake_minimum_required(VERSION 3.14)

# Project name, version, and language
project(Logxxi
    VERSION 0.1.0
    DESCRIPTION "A header-only C++ logger"
    HOMEPAGE_URL "https://github.com/asyqew/logxxi"
    LANGUAGES CXX
)

# Set C++ standard: C++17 (widely supported and sufficient for most use cases)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF) # Use only standard C++, not compiler extensions

# Enable warnings for better code quality (recommended for development)
if(MSVC)
    add_compile_options(/W4 /permissive-)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

add_library(logxxi INTERFACE)
target_include_directories(logxxi
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)
target_compile_features(logxxi INTERFACE cxx_std_17)

include(GNUInstallDirs)
install(
    TARGETS logxxi
    EXPORT logxxiTargets
)
install(
    DIRECTORY include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)
install(
    EXPORT logxxiTargets
    FILE logxxiConfig.cmake
    NAMESPACE logxxi::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/logxxi
)

# --- Examples ---
# Build example applications to demonstrate how to use Logxxi

add_executable(example_hello examples/01_hello.cpp)
target_link_libraries(example_hello PRIVATE logxxi)

add_executable(example_advanced examples/02_advanced.cpp)
target_link_libraries(example_advanced PRIVATE logxxi)
