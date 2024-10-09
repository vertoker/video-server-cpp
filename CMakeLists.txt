
#=====
# Init
#=====

cmake_minimum_required(VERSION 3.12)
project(video-server)
set(CMAKE_CXX_STANDARD 20)

#===============
# Src && Include
#===============

# Set variables for short
set(includes_dir ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(sources_dir ${CMAKE_CURRENT_SOURCE_DIR}/src)

# Recurse collect every file in include/ and src/ folders
file(GLOB_RECURSE project_includes CONFIGURE_DEPENDS "${includes_dir}/*.h" "${includes_dir}/*.hpp")
file(GLOB_RECURSE project_sources CONFIGURE_DEPENDS "${sources_dir}/*.c" "${sources_dir}/*.cpp")

# add include/ folder as root for all header files
include_directories(${includes_dir})

# finally add all founded include/ and src/ files into compiler as a program
add_executable(CMAKE_PROJECT_NAME ${project_includes} ${project_sources})

#=====================
# Libraries (packages)
#=====================

find_package(fmt CONFIG REQUIRED)
target_link_libraries(CMAKE_PROJECT_NAME PRIVATE fmt::fmt)

find_package(Boost REQUIRED COMPONENTS asio)
target_link_libraries(CMAKE_PROJECT_NAME PRIVATE Boost::asio)
