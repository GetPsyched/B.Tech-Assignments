def main():
    """Question 2

    Calculate simple interest
    """
    principal = float(input('Enter the principal amount --> '))
    time = float(input('Enter the time --> '))
    rate = float(input('Enter the rate --> '))

    simple_interest = (principal * time * rate) / 100

    print('Simple interest =', simple_interest)

if __name__ == '__main__':
   main()
