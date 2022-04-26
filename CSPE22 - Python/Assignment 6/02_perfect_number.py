def main():
    """Question 2

    Write a Python program to check whether the given number is a perfect number or not.
    """
    n = int(input('Enter an integer number --> '))
    sum = 0

    # Using for loop to find the divisors of the entered number
    for x in range(1, n):
        if(n % x == 0):
            sum += x

    if sum == n:
        print(f'The number {n} is a Perfect number')
    else:
        print(f'The number {n} is not a Perfect number as its sum: {sum} is not equal to the number itself')

if __name__ == '__main__':
    main()
