# @author Michael Heilmann
# @copyright Copyright (c) Michael Heilmann 2017

# Minimum required CMake version.
cmake_minimum_required (VERSION 3.8)

# Project.
project (Nucleus.Language.Library C)

if (NUCLEUS_PATH)
  include(${NUCLEUS_PATH}/buildsystem/detect_compiler_and_platform.cmake)
  include(${NUCLEUS_PATH}/buildsystem/set_default_project_properties.cmake)
else()
  include(${CMAKE_CURRENT_SOURCE_DIR}/../buildsystem/detect_compiler_and_platform.cmake)
  include(${CMAKE_CURRENT_SOURCE_DIR}/../buildsystem/set_default_project_properties.cmake)
endif()

set_project_default_properties()

# The Unicode codepoints file.
set(SOURCE_FILENAME "${CMAKE_CURRENT_SOURCE_DIR}/src/Nucleus/Language/UnicodeCodePoints.l")

# Define, configure, and invoke tool to generate
# "${CMAKE_CURRENT_SOURCE_DIR}/Nucleus/Language/UnicodeSymbols.h"
# from
# "${CMAKE_CURRENT_SOURCE_DIR}/Nucleus/Language/UnicodeSymbols.l"
set(TARGET_HEADER_FILENAME "${CMAKE_CURRENT_SOURCE_DIR}/src/Nucleus/Language/UnicodeCodePoints.h")
add_custom_command(
    OUTPUT
        ${TARGET_HEADER_FILENAME}
    DEPENDS
        ${SOURCE_FILENAME} Nucleus.Language.Tools.Unicode
    COMMAND
        Nucleus.Language.Tools.Unicode --generator=Header --prefix=Nucleus_Language_ ${SOURCE_FILENAME} ${TARGET_HEADER_FILENAME}
    COMMENT
        "Generating ${TARGET_HEADER_FILENAME} from ${SOURCE_FILENAME}"
    VERBATIM
)

# Define, configure, and invoke tool to generate
# "${CMAKE_CURRENT_SOURCE_DIR}/Nucleus/Language/UnicodeSymbols.i"
# from
# "${CMAKE_CURRENT_SOURCE_DIR}/Nucleus/Language/UnicodeSymbols.l"
set(TARGET_INLAY_FILENAME "${CMAKE_CURRENT_SOURCE_DIR}/src/Nucleus/Language/UnicodeCodePoints.i")
add_custom_command(
    OUTPUT
        ${TARGET_INLAY_FILENAME}
    DEPENDS
        ${SOURCE_FILENAME} Nucleus.Language.Tools.Unicode
    COMMAND
        Nucleus.Language.Tools.Unicode --generator=Inlay --prefix= ${SOURCE_FILENAME} ${TARGET_INLAY_FILENAME}
    COMMENT
        "Generating ${TARGET_INLAY_FILENAME} from ${SOURCE_FILENAME}"
    VERBATIM
)

# Find and configure source files.
file(GLOB_RECURSE SOURCE_FILES "${CMAKE_CURRENT_SOURCE_DIR}" "src/*.c")
# Find and configure header files.
file(GLOB_RECURSE HEADER_FILES "${CMAKE_CURRENT_SOURCE_DIR}" "src/*.h")
set_source_files_properties(${HEADER_FILES} PROPERTIES HEADER_FILE_ONLY TRUE)
# Find and configure inlay files.
file(GLOB_RECURSE INLAY_FILES "${CMAKE_CURRENT_SOURCE_DIR}" "src/*.i")
set_source_files_properties(${INLAY_FILES} PROPERTIES HEADER_FILE_ONLY TRUE)
# Define and configure the library.
add_library(Nucleus.Language.Library STATIC ${SOURCE_FILES} ${HEADER_FILES} ${INLAY_FILES} ${TARGET_HEADER_FILENAME} ${TARGET_INLAY_FILENAME})
target_link_libraries(Nucleus.Language.Library Nucleus.Interpreter.Library Nucleus.Library)
target_include_directories(Nucleus.Language.Library PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src")
target_include_directories(Nucleus.Language.Library INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/src")


IF(DOXYGEN_FOUND)
    ADD_CUSTOM_TARGET(Nucleus.Language.Library.Documentation ${DOXYGEN_EXECUTABLE} COMMENT "Building documentation")
ELSE(DOXYGEN_FOUND)
    MESSAGE(STATUS "Doxygen not found. You won't be able to build documentation.")
ENDIF(DOXYGEN_FOUND)
