def main():
    """Question 9

    Write a program to compute the quotient and remainder of two numbers
    """
    # Input the numbers
    num1 = float(input("Enter the first number --> "))
    num2 = float(input("Enter the second number --> "))

    # Quotient
    quo = num1 / num2

    # Remainder
    rem = num1 % num2

    # Printing the results
    print(f'Quotient = {quo}')
    print(f'Remainder = {rem}')

if __name__ == '__main__':
   main()
