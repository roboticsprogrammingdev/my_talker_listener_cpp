cmake_minimum_required(VERSION 3.0.2)
project(my_talker_listener_cpp)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
)

catkin_package()

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(cpp_talker src/talker.cpp)
add_executable(cpp_listener src/listener.cpp)

target_link_libraries(cpp_talker ${catkin_LIBRARIES})
target_link_libraries(cpp_listener ${catkin_LIBRARIES})

set_target_properties(cpp_talker
    PROPERTIES OUTPUT_NAME talker
    PREFIX ""
)
set_target_properties(cpp_listener
    PROPERTIES OUTPUT_NAME listener
    PREFIX ""
)

install(TARGETS cpp_talker
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
install(TARGETS cpp_listener
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
install(FILES
  launch/talker_listener.launch
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/launch
)
