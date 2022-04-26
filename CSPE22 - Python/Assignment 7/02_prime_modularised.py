from prime_utils import isPrime, printPrimeNumbers

def main():
    """Question 2

    Apply the concept of code modularization to improve the program implemented in
    experiment 6.4 with title PrimeNumber.py. This program defines two new functions,
    isPrime and printPrimeNumbers. The isPrime function determines whether a number is
    prime, and the printPrimeNumbers function prints prime numbers.

    NOTE: In a line, total prime numbers permissible are less than 15 in the count.
    """
    number = int(input('Enter a number --> '))
    if isPrime(number):
        print(f'The number {number} is a prime number')
    else:
        print(f'The number {number} is not a prime number')

    print(f'Prime numbers uptil {number}:', end=' ')
    printPrimeNumbers(number)

if __name__ == '__main__':
    main()
