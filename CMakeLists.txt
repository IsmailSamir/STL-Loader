cmake_minimum_required(VERSION 3.9)

project(STL-Loader VERSION 1.0.0 LANGUAGES CXX C)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/$<CONFIG>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/$<CONFIG>")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/$<CONFIG>")

#external libraries

# internal libraries
add_subdirectory(playground)
add_subdirectory(STL)

# Organize Targets into folders

set_target_properties(
	STL
	PROPERTIES FOLDER STL
)

set_target_properties(
	playground
	PROPERTIES FOLDER Testing
)