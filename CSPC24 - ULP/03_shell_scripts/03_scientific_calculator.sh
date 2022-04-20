# Write a shell script program to develop a scientific calculator.

#!/bin/bash
while true
do

cat << MENU

    Menu:
    a) Floating Point Calculations
    b) Trigonometric Operations
    c) Logarithmic Operations
    d) Exponential Operations

MENU
read -p 'Enter your choice: ' choice

case $choice in

    a)  read -p 'Enter expression --> ' exp
        calc() {
            awk "BEGIN{print $*}";
        }
        echo 'Answer: ' `calc $exp`
        ;;

    b)  read -p 'Enter a trigonometric function --> ' exp
        read -p 'Enter the degree --> ' degree

        e=$(awk "BEGIN{print $exp($degree*atan2(0,-1)/180)}")
        echo '
        $exp($degree)= $e'
        ;;

    c)  read -p 'Enter a logarithmic value --> ' value
        echo $value | awk '{printf "%11.9f\n",log($1)/log(10)}'
        ;;

    d)  read -p 'Enter the base number x --> ' x
        read -p 'Enter exponent number y --> ' y
        e=$(echo "$x 1" | awk "{print (($x/1)^$y)}")
        echo '$x^$y = $e'
        ;;
    *)
        break;;

esac
done
