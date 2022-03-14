# Write a shell Script program to check whether the given number is even or odd.

#!/bin/bash
echo -n "Enter a number --> "
read n

if [ `expr $n % 2` == 0 ]
then
	echo "$n is even"
else
	echo "$n is Odd"
fi