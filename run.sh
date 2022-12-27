#!/bin/bash
OUTPUT_NAME=output

echo "Compiling project..."
gcc *.c *.h -o $OUTPUT_NAME

./$OUTPUT_NAME

rm $OUTPUT_NAME