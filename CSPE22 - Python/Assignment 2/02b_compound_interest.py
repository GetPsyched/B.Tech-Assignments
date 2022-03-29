def main():
    """Question 2

    Calculate compound interest
    """
    principal = float(input('Enter the principal amount --> '))
    time = float(input('Enter the time --> '))
    rate = float(input('Enter the rate --> '))

    compound_interest = principal * ( (1 + rate / 100) ** time - 1)

    print('Compound interest =', compound_interest)

if __name__ == '__main__':
   main()
