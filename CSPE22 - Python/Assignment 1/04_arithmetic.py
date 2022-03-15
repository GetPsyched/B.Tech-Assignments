def main():
    """Question 4

    Write a program to perform different arithmetic operations on numbers in python.
    """
    # Input the numbers
    num1 = float(input("Enter the first number --> "))
    num2 = float(input("Enter the second number --> "))

    # Addition
    sum = num1 + num2

    # Subtraction
    diff = num1 - num2

    # Multiplication
    prod = num1 * num2

    # Float Division
    fdiv = num1 / num2

    # Integer Division
    idiv = num1 // num2

    # Remainder
    rem = num1 % num2

    # Exponent
    exp = num1 ** num2

    # Printing the results
    print(f'Addition = {sum}')
    print(f'Subtraction = {diff}')
    print(f'Product = {prod}')
    print(f'Float Division = {fdiv}')
    print(f'Integer Division = {idiv}')
    print(f'Remainder = {rem}')
    print(f'Exponent = {exp}')

if __name__ == '__main__':
   main()