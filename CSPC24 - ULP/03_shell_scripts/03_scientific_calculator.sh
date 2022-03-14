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
echo '
Enter your Choice: \c'
read choice

case $choice in

    a) echo "\nEnter expression: "
        read exp
        cal()
            awk "BEGIN{print $*}";
        echo "Answer: " `cal $exp`
        ;;

    b) echo "\nEnter Trigonometric function : "
            read exp
            echo "Degree: "
            read degree

        e=$(awk "BEGIN{print $exp($degree*atan2(0,-1)/180)}")
            echo "
            $exp($degree)= $e"
            ;;

        c) echo "\nEnter the logarithmic value: "
            read value
            echo $value | awk '{printf "%11.9f\n",log($1)/log(10)}'
            ;;

        d) echo "\nEnter the base number x: "
        read x
        echo "Enter exponent number y: "
        read y
        E=$(echo "$x 1" | awk "{print (($x/1)^$y)}")
        echo "$x^$y = $E"
            ;;
        *)
            break;;
        *)
            break;;
esac
done