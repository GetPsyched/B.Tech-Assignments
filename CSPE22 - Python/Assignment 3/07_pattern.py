def main():
    """Question 7

    Write a Python program to print alphabet pattern 'A'.
    """
    n = int(input('Enter the size (min 3) --> '))
    for i in range(n):
        for j in range(n - i):
            print(' ', end='')
        for j in range(2 * i + 1):
            if j in (0, 2 * i) or i == n // 2:
                print('*', end='')
            else:
                print(' ', end='')
        print()

if __name__ == '__main__':
   main()
