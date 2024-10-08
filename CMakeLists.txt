
# Init

cmake_minimum_required(VERSION 3.12)
project(video-server)
set(CMAKE_CXX_STANDARD 20)

# Src && Include

set(includes_dir ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(sources_dir ${CMAKE_CURRENT_SOURCE_DIR}/src)

file(GLOB_RECURSE project_includes CONFIGURE_DEPENDS "${includes_dir}/*.h" "${includes_dir}/*.hpp")
file(GLOB_RECURSE project_sources CONFIGURE_DEPENDS "${sources_dir}/*.c" "${sources_dir}/*.cpp")
add_executable(CMAKE_PROJECT_NAME ${project_includes} ${project_sources})

# Libraries

find_package(fmt CONFIG REQUIRED)
target_link_libraries(CMAKE_PROJECT_NAME PRIVATE fmt::fmt)

find_package(Boost REQUIRED COMPONENTS asio)
target_link_libraries(CMAKE_PROJECT_NAME PRIVATE Boost::asio)
