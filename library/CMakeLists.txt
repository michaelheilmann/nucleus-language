# @author Michael Heilmann
# @copyright Copyright (c) Michael Heilmann 2017

# Minimum required CMake version.
cmake_minimum_required (VERSION 3.8)

# Project.
project (dl-library C)

if (NUCLEUS_PATH)
  include(${NUCLEUS_PATH}/buildsystem/detect_compiler_and_platform.cmake)
  include(${NUCLEUS_PATH}/buildsystem/set_default_project_properties.cmake)
else()
  include(${CMAKE_CURRENT_SOURCE_DIR}/../buildsystem/detect_compiler_and_platform.cmake)
  include(${CMAKE_CURRENT_SOURCE_DIR}/../buildsystem/set_default_project_properties.cmake)
endif()

set_project_default_properties()

# Find and configure source files.
file(GLOB_RECURSE SOURCE_FILES "${CMAKE_CURRENT_SOURCE_DIR}" "src/*.c")
# Find and configure header files.
file(GLOB_RECURSE HEADER_FILES "${CMAKE_CURRENT_SOURCE_DIR}" "src/*.h")
set_source_files_properties(${HEADER_FILES} PROPERTIES HEADER_FILE_ONLY TRUE)
# Define and configure the library.
add_library(dl-library STATIC ${SOURCE_FILES} ${HEADER_FILES})
target_link_libraries(dl-library nucleus-library)
target_include_directories(dl-library PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src")
target_include_directories(dl-library INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/src")


IF(DOXYGEN_FOUND)
    ADD_CUSTOM_TARGET(dl-library-doc ${DOXYGEN_EXECUTABLE} COMMENT "Building documentation")
ELSE(DOXYGEN_FOUND)
    MESSAGE(STATUS "Doxygen not found. You won't be able to build documentation.")
ENDIF(DOXYGEN_FOUND)
