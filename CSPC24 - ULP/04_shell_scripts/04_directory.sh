# Write a shell script program to create a directory, write contents in it, copy it to a suitable location in your home directory

#!/bin/bash
echo -n "Enter a name for the new directory --> "
read dirName

mkdir "$dirName"

echo -n "Enter the number of files you wish to create --> "
read num

let "counter = $num"
echo
while [ $counter -gt 0 ]
do
    echo -n "Enter the name of file --> "
    read name

    touch "$dirName/$name"

    let "counter--"
done

echo "$num files have been created."

echo -n "Enter a source destination to move this directory to --> "
read loc

mv "$dirName" "$loc"
echo -e "\nMoved $dirName -> $loc"
