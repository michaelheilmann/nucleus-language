# @author Michael Heilmann
# @copyright Copyright (c) Michael Heilmann 2017

# Minimum required CMake version.
cmake_minimum_required(VERSION 3.8)

# Project.
project (nucleus-language C)

include(CTest)
enable_testing()

set(NUCLEUS_PATH ${CMAKE_CURRENT_SOURCE_DIR}/dependencies/nucleus)

include(${NUCLEUS_PATH}/buildsystem/detect_compiler_and_platform.cmake)
include(${NUCLEUS_PATH}/buildsystem/set_default_project_properties.cmake)

# Add module "Nucleus".
add_subdirectory(${NUCLEUS_PATH})

# Add module "library".
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/library")

# Add module "demo".
#add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/demo")

# Add module "test".
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/test")