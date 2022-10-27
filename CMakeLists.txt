cmake_minimum_required(VERSION 3.0.2)
project(simple_motion)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  sensor_msgs
  std_msgs
 )
# Generate actions in the 'action' folder

## Generate added messages and services with any dependencies listed here
generate_messages(
  DEPENDENCIES
  sensor_msgs
  std_msgs
)

catkin_package(
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(simple_motion src/main.cpp)
target_link_libraries(simple_motion ${catkin_LIBRARIES})



