def main():
    """Question 8

    Write a program to exchange the values of two variables using a temporary variable
    """
    num1 = int(input('Enter 1st number --> '))
    num2 = int(input('Enter 2nd number --> '))

    temp = num1
    num1 = num2
    num2 = temp

    print(f'{num1 = }, {num2 = }')

if __name__ == '__main__':
   main()
