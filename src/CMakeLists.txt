cmake_minimum_required(VERSION 3.0)
include_directories(${CMAKE_CURRENT_DIR})
set(SOURCE_FILES
    main.cpp
    Parking.cpp
    Monitor.cpp
)
add_executable(SmartParking ${SOURCE_FILES})
target_link_libraries(SmartParking ${SFML_LIBRARIES})