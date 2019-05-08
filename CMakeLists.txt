cmake_minimum_required(VERSION 3.1)
set(CMAKE_CXX_STANDARD 11)
include(ExternalProject)

project(ChessBoardCreator)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake-modules")
find_package(libps QUIET)
message(STATUS "LIBPS found: " ${LIBPS_FOUND})

if (NOT LIBPS_FOUND)
    set(Pslib_Version 0.4.5)
    ExternalProject_Add(
            libps
                PREFIX ${CMAKE_BINARY_DIR}/external/pslib
                URL https://sourceforge.net/projects/pslib/files/pslib/${Pslib_Version}/pslib-${Pslib_Version}.tar.gz
                URL_MD5 03f39393628a6d758799b9f845047e27
    )

    set_target_properties(libps PROPERTIES EXCLUDE_FROM_ALL TRUE)

    set(LIBPS_LIBRARY_DIRS ${CMAKE_BINARY_DIR}/external/pslib/src/libps-build)
    set(LIBPS_INCLUDE_DIRS ${CMAKE_BINARY_DIR}/external/pslib/src/libps/include)
    set(LIBPS_LIBRARIES pslib)
    
    link_directories(${LIBPS_LIBRARY_DIRS})
endif()

include_directories(${LIBPS_INCLUDE_DIRS})
add_executable(ChessBoardCreator ChessBoardCreator.cpp ChessBoardCreator.h)
target_link_libraries(ChessBoardCreator ${LIBPS_LIBRARIES})

if (NOT LIBPS_FOUND)
    add_dependencies(ChessBoardCreator libps)
    set_target_properties(ChessBoardCreator PROPERTIES EXCLUDE_FROM_ALL TRUE)
endif()

if (WIN32)
    add_custom_command(TARGET ChessBoardCreator POST_BUILD
                       COMMAND ${CMAKE_COMMAND} -E copy_if_different
                       "${LIBPS_LIBRARY_DIRS}/$(Configuration)/pslib.dll"
                       $<TARGET_FILE_DIR:ChessBoardCreator>)
endif()

