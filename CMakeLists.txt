# Copyright (c) 2017 - 2018 Michael Heilmann
# Assert minimum CMake version.
cmake_minimum_required(VERSION 3.8)

# Include the "Nucleus" build system.
if (NOT NUCLEUS_PATH)
  set(NUCLEUS_PATH ${CMAKE_CURRENT_SOURCE_DIR}/dependencies/nucleus)
endif()
if (NUCLEUS_PATH)
  include(${NUCLEUS_PATH}/buildsystem/buildsystem.cmake)
endif()

# Define module.
define_module(Nucleus.Language)

# Disable compilation/execution of unit tests of "Nucleus".
#string(CONCAT description
#       "enable/disable compilation and execution of unit tests for module Nucleus."
#  	    "ON enables compilation/execution of unit tests of Nucleus, OFF disables it."
#	    "Initial value is OFF.")
#set(Nucleus-With-Tests OFF CACHE BOOL ${description} FORCE)

# Include "Nucleus" unless it is already included.
if (NOT NUCLEUS_INCLUDED)
  set(Nucleus-With-Optimizations ${Nucleus.Language-With-Optimizations})
  set(Nucleus-With-Debug-Information ${Nucleus.Language-With-Debug-Information})
  set(Nucleus-With-Pthreads ${Nucleus.Language-With-Pthreads})
  set(Nucleus-With-Static-Runtime ${Nucleus.Language-With-Static-Runtime})
  add_subdirectory(${NUCLEUS_PATH})
  set(NUCLEUS_INCLUDED YES)
endif()

# Add module "Nucleus: Interpreter".
if (NOT NUCLEUS_INTERPRETER_PATH)
  set(NUCLEUS_INTERPRETER_PATH ${CMAKE_CURRENT_SOURCE_DIR}/dependencies/nucleus-interpreter)
endif()
if (NOT NUCLEUS_INTERPRETER_INCLUDED)
  set(Nucleus.Interpreter-With-Optimizations ${Nucleus.Language-With-Optimizations})
  set(Nucleus.Interpreter-With-Debug-Information ${Nucleus.Language-With-Debug-Information})
  set(Nucleus.Interpreter-With-Pthreads ${Nucleus.Language-With-Pthreads})
  set(Nucleus.Interpreter-With-Static-Runtime ${Nucleus.Language-With-Static-Runtime})
  add_subdirectory(${NUCLEUS_INTERPRETER_PATH})
  set(NUCLEUS_INTERPRETER_INCLUDED YES)
endif()

# Add module "library".
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/library")

# Add module "test".
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/test")
