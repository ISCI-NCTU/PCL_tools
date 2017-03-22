cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(convertply2pcd)

find_package(PCL 1.2 REQUIRED)

include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

add_executable (ply_to_pcd convert.cpp)
target_link_libraries (ply_to_pcd ${PCL_LIBRARIES})

