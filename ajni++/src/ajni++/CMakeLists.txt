cmake_minimum_required(VERSION 3.1)

include_directories(..)

add_library(ajni++ STATIC
    ast.cpp
    android.cpp
    jnienv.cpp
    inspect.cpp
    jre.cpp
    variant.cpp
    kotlin.cpp
    java-prv.cpp
    android-prv.cpp
    )

target_link_libraries(ajni++ cross log)

set_target_properties(ajni++
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    )
