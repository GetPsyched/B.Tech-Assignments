# Write a shell script program to copy the content of one file to another file

#!/bin/bash
echo -n "Enter the file from which the content is copied --> "
read copy_file

echo -n "Enter the file to which the content is pasted --> "
read paste_file

cat $copy_file > $paste_file

echo "Copied the contents of $copy_file to $paste_file successfully!"