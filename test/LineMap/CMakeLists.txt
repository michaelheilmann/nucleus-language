# Copyright (c) Michael Heilmann 2017, 2018

# Minimum required CMake version.
cmake_minimum_required (VERSION 3.8)

# Project.
project(Nucleus.DataLanguage.Test.LineMap C)
message("building Nucleus.DataLanguage.Test.LineMap")

if (NUCLEUS_PATH)
  include(${NUCLEUS_PATH}/buildsystem/detect_compiler_and_platform.cmake)
  include(${NUCLEUS_PATH}/buildsystem/set_default_project_properties.cmake)
else()
  include(${CMAKE_CURRENT_SOURCE_DIR}/../buildsystem/detect_compiler_and_platform.cmake)
  include(${CMAKE_CURRENT_SOURCE_DIR}/../buildsystem/set_default_project_properties.cmake)
endif()

set_project_default_properties()

# Find and configure source files.
file(GLOB_RECURSE SOURCE_FILES RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" "src/*.c")
# Find and configure header files.
file(GLOB_RECURSE HEADER_FILES RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" "src/*.h")
set_source_files_properties(${HEADER_FILES} PROPERTIES HEADER_FILE_ONLY TRUE)
# Add and configure executable.
add_executable(Nucleus.DataLanguage.Test.LineMap ${SOURCE_FILES} ${HEADER_FILES})
target_link_libraries(Nucleus.DataLanguage.Test.LineMap Nucleus.DataLanguage.Library)

# Test.
add_test(NAME Nucleus.DataLanguage.Test.LineMap COMMAND $<TARGET_FILE:Nucleus.DataLanguage.Test.LineMap>
         WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
