#!/bin/bash

# Check if a parameter is provided
if [ -z "$1" ]; then
  echo "Usage: $0 <part_number>"
  exit 1
fi

# Get the current working directory
CURRENT_DIR="$(pwd)"

# Define the part and input file based on the argument
PART_NUMBER=$1
SOURCE_FILE="${CURRENT_DIR}/part${PART_NUMBER}.cpp"
echo "Current directory '$CURRENT_DIR'"
INPUT_FILE="${CURRENT_DIR}/input${PART_NUMBER}.txt"
OUTPUT_BINARY="${CURRENT_DIR}/run"

# Check if the source file exists
if [ ! -f "$SOURCE_FILE" ]; then
  echo "Error: Source file '$SOURCE_FILE' not found in the current directory!"
  exit 1
fi

# Check if the input file exists
if [ ! -f "$INPUT_FILE" ]; then
  echo "Error: Input file '$INPUT_FILE' not found in the current directory!"
  exit 1
fi

# Compile the source file
clang++ "/$SOURCE_FILE" -o "/$OUTPUT_BINARY"
if [ $? -ne 0 ]; then
  echo "Compilation failed!"
  exit 1
fi

# Measure execution time using `time`
echo "Running part $PART_NUMBER..."

# Measure the execution time of the program (run executable) with input redirection
TIMER_OUTPUT=$( { /usr/bin/time -p "$OUTPUT_BINARY" < "$INPUT_FILE"; } 2>&1 )

# Extract the real time from the output of `time`
ELAPSED_REAL_TIME=$(echo "$TIMER_OUTPUT" | grep "real" | awk '{print $2}')
if [[ "$ELAPSED_REAL_TIME" =~ ^[0-9]+(\.[0-9]+)?$ ]]; then
    ELAPSED_MS=$(echo "$ELAPSED_REAL_TIME * 1000" | bc)
    echo "Execution time: ${ELAPSED_MS} ms"
else
    echo "Error measuring time. Output from time: $TIMER_OUTPUT"
fi

# Clean up the compiled binary
rm -f "$OUTPUT_BINARY"
