cmake_minimum_required(VERSION 2.8)

Project(openlitespeed)
INCLUDE( ${PROJECT_SOURCE_DIR}/CMakeModules/common.cmake)

set(openlitespeed_MAJOR_VERSION 1)
set(openlitespeed_MINOR_VERSION 2)
set(openlitespeed_PATCH_VERSION 7)
set(openlitespeed_VERSION
  ${FOOBAR_MAJOR_VERSION}.${FOOBAR_MINOR_VERSION}.${FOOBAR_PATCH_VERSION})

SET(CMAKE_INCLUDE_CURRENT_DIR ON)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/src/config.h.cmake ${CMAKE_CURRENT_BINARY_DIR}/src/config.h)

SET(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMakeModules)
find_package(ZLIB REQUIRED)
##find_package(LibLdap REQUIRED)
find_package(PCRE REQUIRED)
find_package(EXPAT REQUIRED)
find_package(OpenSSL REQUIRED)

add_subdirectory(src)




