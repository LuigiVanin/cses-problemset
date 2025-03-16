cmake_minimum_required(VERSION 3.31)

project(cses_problem_set)

set(CMAKE_CXX_STANDARD 23)

# Set the output directory for executables
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Get the problem number from the command line
if(DEFINED PROBLEM_ID)
  # Construct the source file path based on the problem number
  set(SOURCE_FILE "problems/q${PROBLEM_ID}.cpp")

  # Check if the source file exists
  if(NOT EXISTS ${SOURCE_FILE})
    message(FATAL_ERROR "Source file ${SOURCE_FILE} does not exist.")
  endif()

  # Add the executable for the specified problem
  add_executable(q${PROBLEM_ID} ${SOURCE_FILE})
  set_target_properties(q${PROBLEM_ID} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
else()
  # Get all .cpp files in the problems/ directory
  file(GLOB SOURCES "problems/*.cpp")

  # Add an executable for each source file
  foreach(SOURCE ${SOURCES})
    get_filename_component(EXE_NAME ${SOURCE} NAME_WE)
    add_executable(${EXE_NAME} ${SOURCE})
    set_target_properties(${EXE_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
  endforeach()
endif()