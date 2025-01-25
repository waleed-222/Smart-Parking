cmake_minimum_required(VERSION 3.0)
project(SmartParking)

find_package(PkgConfig REQUIRED)
pkg_check_modules(SFML REQUIRED sfml-all)
message(STATUS "SFML_INCLUDE_DIRS: ${SFML_LIBRARIES}")
add_subdirectory(src)