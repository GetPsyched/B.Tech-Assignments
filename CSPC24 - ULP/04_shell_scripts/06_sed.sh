# Write a shell script program using sed command to print duplicated lines of input

#!/bin/bash
sed '$!N; /^\(.*\)\n\1$/!P; D' sample.txt
