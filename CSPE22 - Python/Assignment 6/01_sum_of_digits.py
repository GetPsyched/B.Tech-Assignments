def main():
    """Question 1

    Write a Python program to accept an integer number and find the sum of digits in the number.
    """
    n = int(input('Enter an integer number --> '))
    sum = 0

    # Using a while loop to traverse the digits of the entered number
    while n != 0:
        sum += n % 10
        n //= 10

    print('The sum of digits of the entered number is', sum)

if __name__ == '__main__':
    main()
