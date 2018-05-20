# Copyright (c) 2017 - 2018 Michael Heilmann
# Assert minimum CMake version.
cmake_minimum_required (VERSION 3.8)
# Define the test.
define_test(Nucleus.Language Nucleus.Language.Test.Parser ${NUCLEUS_LANGUAGE_ID_C})
target_link_libraries(Nucleus.Language.Test.Parser Nucleus.Language.Library)
