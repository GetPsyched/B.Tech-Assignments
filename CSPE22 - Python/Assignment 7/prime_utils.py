def isPrime(number: int) -> bool:
    """Check if the given number is prime"""
    for num in range(2, number // 2 + 1):
        if number % num == 0:
            return False
    return True

def printPrimeNumbers(number: int):
    """Print prime numbers from 1 to the given number"""
    for num in range(1, number + 1):
        if isPrime(num):
            print(num, end=' ')
