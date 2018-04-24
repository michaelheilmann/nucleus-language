# Copyright (c) Michael Heilmann 2017, 2018

# Minimum required CMake version.
cmake_minimum_required(VERSION 3.8)

# Project.
project (Nucleus.Language C)
message("building Nucleus.Language")

include(CTest)
enable_testing()

if (NOT DEFINED With-Optimizations)
  set(With-Optimizations ON CACHE BOOL
      "enable/disable compilation with optimizations. ON enables compilation with optimizations, OFF disables compilation with optimizations. Initial value is ON." FORCE)
endif()

if (NOT DEFINED With-Debug-Information)
  set(With-Debug-Information OFF CACHE BOOL
      "enable/disable compilation with debug information. ON enables compilation with debug information, OFF disables compilation with debug information. Initial value is OFF." FORCE)
endif()

if (NOT NUCLEUS_PATH)
  set(NUCLEUS_PATH ${CMAKE_CURRENT_SOURCE_DIR}/dependencies/nucleus)
endif()

# Add module "Nucleus".
if (NOT NUCLEUS_INCLUDED)
  add_subdirectory(${NUCLEUS_PATH})
  set(NUCLEUS_INCLUDED YES)
endif()

if (NOT NUCLEUS_INTERPRETER_PATH)
  set(NUCLEUS_INTERPRETER_PATH ${CMAKE_CURRENT_SOURCE_DIR}/dependencies/nucleus-interpreter)
endif()

# Add module "Nucleus: Interpreter".
if (NOT NUCLEUS_INTERPRETER_INCLUDED)
  add_subdirectory(${NUCLEUS_INTERPRETER_PATH})
  set(NUCLEUS_INTERPRETER_INCLUDED YES)
endif()

# Add module "library".
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/library")

# Add module "test".
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/test")
