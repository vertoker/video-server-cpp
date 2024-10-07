
cmake_minimum_required(VERSION 3.12)
project(video-server)
set(CMAKE_CXX_STANDARD 20)

add_executable(CMAKE_PROJECT_NAME "src/main.cpp")

# Libraries

find_package(fmt CONFIG REQUIRED)
target_link_libraries(CMAKE_PROJECT_NAME PRIVATE fmt::fmt)

find_package(Boost REQUIRED COMPONENTS asio)
target_link_libraries(CMAKE_PROJECT_NAME PRIVATE Boost::asio)
