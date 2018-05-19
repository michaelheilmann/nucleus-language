# Copyright (c) 2017, 2018 Michael Heilmann
# Assert minimum CMake version.
cmake_minimum_required (VERSION 3.8)
# Define the static library.
set(libraries Machine.Library)
define_static_library(Nucleus.Language Nucleus.Language.Library ${libraries} ${NUCLEUS_LANGUAGE_ID_C})
