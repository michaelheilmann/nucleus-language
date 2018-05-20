# Copyright (c) 2017 - 2018 Michael Heilmann
# Assert minimum CMake version.
cmake_minimum_required (VERSION 3.8)
# Define the static library.
define_static_library(Nucleus.Language Nucleus.Language.Library ${NUCLEUS_LANGUAGE_ID_C})
target_link_libraries(Nucleus.Language.Library Nucleus.Interpreter.Library)
