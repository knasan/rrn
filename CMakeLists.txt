cmake_minimum_required(VERSION 2.8)

project(rrn)

set(Boost_DEBUG ON)
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost COMPONENTS program_options)

set(CMAKE_CXX_FLAGS "-Wall -std=c++17 -lboost_program_options -lboost_filesystem -lboost_system")
set(SOURCES main.cpp rrn.cpp rrn.hpp)
add_executable(${PROJECT_NAME} ${SOURCES})
