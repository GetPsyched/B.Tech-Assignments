def getPrimes(start: int, end: int) -> list[str] | None:
    """Function to get all primes in an interval"""
    # These checks are inserted for the code to not break when a very small or negative value is inputted
    if start < 2:
        start = 2
    if end < 2:
        return None

    primes = []
    for number in range(start, end + 1): # end + 1 as the range() function ignores the last index inputted
        isPrime = True
        for num in range(2, number // 2 + 1): # The // operator divides the 2 numbers and floors the value to an integer
            if number % num == 0:
                isPrime = False
                break

        # If the `if` statement above wasn't invoked even once, it means the number is prime
        if isPrime:
            primes.append(number)
    return list(map(str, primes))

def main():
    """Program to print all the primes in an interval"""
    start = int(input('Enter the start number --> '))
    end = int(input('Enter the end number --> '))
    primes = getPrimes(start, end)

    # Check if the function returned `None` or an empty list
    if not primes:
        print('No primes were found!')
        return

    print(f'The primes upto {end} are -->', ', '.join(primes))
    print('Total number of primes are --> ', len(primes))

if __name__ == '__main__':
    main()