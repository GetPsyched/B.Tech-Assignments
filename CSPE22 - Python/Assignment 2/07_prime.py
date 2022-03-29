def main():
    """Question 7

    Write a program that prints prime numbers less than 20
    """
    primes = []
    for i in range(2, 20):
        j = 2
        while j <= i/2:
            if i % j == 0:
                break
            j += 1

        if j > i/2:
            primes.append(str(i))

    print('Prime numbers less than 20 -->', ', '.join(primes))

if __name__ == '__main__':
   main()
