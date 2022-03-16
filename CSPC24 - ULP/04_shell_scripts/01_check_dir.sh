# Write a shell script program to check whether a given file is a directory or not

#!/bin/bash
echo -n "Enter the name of the file/folder --> "
read name

if [ -d "$name" ]
then
	echo "$name is a directory."

elif [ -f "$name"]
then
    echo "$name is a file."

else
	echo "$name is invalid."

fi