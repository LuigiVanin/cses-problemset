#!/bin/bash

debug_opt="-D CMAKE_BUILD_TYPE=Debug"
CC="C_COMPILER=clang"

# Check for --build flag
BUILD_ONLY=false
if [ "$1" = "--build" ]; then
  BUILD_ONLY=true
  shift  # Remove --build from arguments
fi

if [ -z "$1" ]; then
  # No argument provided, build all problems
  cmake ${debug_opt} ${CC} .
  make
else
  # Argument provided, build and run the specified problem
  # Strip the 'q' prefix if present (e.g., q1755 -> 1755)
  PROBLEM_ID=${1#q}
  
  cmake -DPROBLEM_ID=${PROBLEM_ID} ${debug_opt} ${CC} .
  make
  
  # Only run if --build flag is not set
  if [ "$BUILD_ONLY" = false ]; then
    if [ -z "$2" ]; then
      # No input file argument provided
      ./bin/q${PROBLEM_ID}
    else
      # Input file argument provided
      INPUT_FILE="./inputs/${PROBLEM_ID}/$2.txt"
      if [ -f "$INPUT_FILE" ]; then
        ./bin/q${PROBLEM_ID} < "$INPUT_FILE"
      else
        echo "Input file $INPUT_FILE does not exist."
      fi
    fi
  fi
fi

