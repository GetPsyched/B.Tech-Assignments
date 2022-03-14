# Write a shell Script program to search whether the element is present is in the list or not.

#!/bin/bash
value = $1
echo "Enter a value to check if it exists in the list --> "
# read value
arr = (10 3 2 34 543 5)
if [[ " ${arr[*]} " =~ " ${value} " ]]; then
	echo "Element exists."

else
	echo "Element doesn't exist."
	echo "Array is [10 3 2 34 543 5]"
fi