# Write a shell script program using pipelines and command substitution to set the length of a line in a file to a variable

#!/bin/bash
echo -n "Enter the name of the file --> "
read name

len=$(cat $name | wc -L)
echo "The length of the longest line in the file $name is $len."
