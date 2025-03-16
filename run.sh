#!/bin/bash

if [ -z "$1" ]; then
  # No argument provided, build all problems
  cmake .
  make
else
  # Argument provided, build and run the specified problem
  PROBLEM_ID=$1
  cmake -DPROBLEM_ID=${PROBLEM_ID} .
  make
  
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

