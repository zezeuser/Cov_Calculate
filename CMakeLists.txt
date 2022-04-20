cmake_minimum_required(VERSION 3.1)
project(cov_demo)

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake_module)
set(CMAKE_BUILD_TYPE Release)
find_package(catkin REQUIRED
  COMPONENTS
)
find_package(Eigen3 REQUIRED)

include_directories(
    include
    ${catkin_INCLUDE_DIRS}
    ${EIGEN3_INCLUDE_DIRS}
)
add_executable(cov_demo
    cov_demo.cpp
)
target_link_libraries(cov_demo 
    ${catkin_LIBRARIES}
    ${EIGEN3_INCLUDE_DIRS}
    )

