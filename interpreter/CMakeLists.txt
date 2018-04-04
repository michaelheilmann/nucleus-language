# @author Michael Heilmann
# @copyright Copyright (c) Michael Heilmann 2017

# Minimum required CMake version.
cmake_minimum_required(VERSION 3.8)

# Project.
project (Nucleus.Interpreter C)
message("building Nucleus.Interpreter")

# Add module "tools".
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/tools")

# Add module "library".
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/library")

# Add module "test".
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/test")
