cmake_minimum_required(VERSION 3.14.0)
project(of_cpp_example)

add_definitions(-D_GLIBCXX_USE_CXX11_ABI=0)

find_package(oneflow)

add_executable(of_cpp_example main.cpp)

target_link_libraries(
  of_cpp_example
  PUBLIC
    OneFlow::liboneflow
)
