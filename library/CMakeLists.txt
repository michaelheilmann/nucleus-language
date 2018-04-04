# @author Michael Heilmann
# @copyright Copyright (c) Michael Heilmann 2017

# Minimum required CMake version.
cmake_minimum_required (VERSION 3.8)

# Project.
project (Nucleus.DataLanguage.Library C)
message("building Nucleus.DataLanguage.Library")

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
# Find and configure inlay files.
file(GLOB_RECURSE HEADER_FILES "${CMAKE_CURRENT_SOURCE_DIR}" "src/*.i")
set_source_files_properties(${INLAY_FILES} PROPERTIES HEADER_FILE_ONLY TRUE)
# Define and configure the library.
add_library(Nucleus.DataLanguage.Library STATIC ${SOURCE_FILES} ${HEADER_FILES} ${INLAY_FILES})
target_link_libraries(Nucleus.DataLanguage.Library Nucleus.Interpreter.Library)
target_include_directories(Nucleus.DataLanguage.Library PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src")
target_include_directories(Nucleus.DataLanguage.Library INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/src")


IF(DOXYGEN_FOUND)
    ADD_CUSTOM_TARGET(Nucleus.DataLanguage.Library.Documentation ${DOXYGEN_EXECUTABLE} COMMENT "Building documentation")
ELSE(DOXYGEN_FOUND)
    MESSAGE(STATUS "Doxygen not found. You won't be able to build documentation.")
ENDIF(DOXYGEN_FOUND)
