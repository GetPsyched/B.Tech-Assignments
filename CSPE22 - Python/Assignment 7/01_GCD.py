def GCDFunction(num1: int, num2: int) -> int:
    """Compute the GCD of 2 numbers using the Euclidean algorithm"""
    while num2:
        num1, num2 = num2, num1 % num2
    return num1

def main():
    """Question 1

    Write a program that prompts the user to enter two integers and displays their greatest
    common divisor (GCD). You can rewrite the program 6.3, and implement this program
    with the help of a function and place it into a module named GCDFunction.py
    """
    num1, num2 = map(int, input('Enter 2 numbers --> ').split())
    print(f'GCD of the given numbers is --> {GCDFunction(num1, num2)}')

if __name__ == '__main__':
    main()
