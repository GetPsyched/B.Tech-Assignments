# Write a shell script program to count the number of files in a directory

#!/bin/bash
echo -n "Enter a directory name --> "
read dirName

if [ -d "$dirName" ]
then
    ls "$dirName" | echo "Number of files/folders in the given directory = $(wc -l)"

else
    echo "$dirName is invalid."

fi