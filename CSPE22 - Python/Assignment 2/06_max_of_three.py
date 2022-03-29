def main():
    """Question 6

    Write a program to find the largest number among the three input numbers
    """
    num1 = float(input('Enter 1st number --> '))
    num2 = float(input('Enter 2nd number --> '))
    num3 = float(input('Enter 3rd number --> '))

    print('Max of the given 3 numbers =', max(num1, num2, num3))

if __name__ == '__main__':
   main()
