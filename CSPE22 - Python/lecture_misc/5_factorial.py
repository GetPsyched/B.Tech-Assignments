from timeit import timeit
from functools import lru_cache

def normal_method():
    """Get factorial with an iterative approach"""
    number = int(input('Enter the number --> '))
    factorial = 1

    # These checks prevent invalid inputs
    if number < 0:
        print('The number must be positive!')
    for num in range(number, 0, -1): # Here, -1 is the "step" of `range()` which tells the function how to traverse through the number line
        factorial *= num

    print(f'Factorial of {number} is {factorial}')

@lru_cache(maxsize=10)
def getFactorial(n):
    return n * getFactorial(n-1) if n else 1

def recursive_with_caching():
    """Get factorial with recursion + lru cache"""
    number = int(input('Enter the number --> '))
    factorial = 1

    # These checks prevent invalid inputs
    if number < 0:
        print('The number must be positive!')
    factorial = getFactorial(number)

    print(f'Factorial of {number} is {factorial}')

def timing():
    """Function to measure time taken with both methods"""
    start = timeit()
    normal_method()
    end = timeit()
    print(f'Time to execute iterative approach = {end - start}')

    start = timeit()
    getFactorial()
    end = timeit()
    print(f'Time to execute recursive approach (with lru cache) = {end - start}')

if __name__ == '__main__':
    recursive_with_caching()