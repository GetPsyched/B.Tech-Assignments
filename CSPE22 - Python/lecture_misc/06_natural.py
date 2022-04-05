def main():
    """Program to find the sum of natural number to n"""
    number = int(input('Enter the number --> '))
    sum_of_natural = 0

    # These checks prevent invalid inputs
    if number < 1:
        print('The number must be greater than 0!')
    # Traverse through all numbers till `number`
    for num in range(number):
        sum_of_natural += num

    print(f'Sum of natural numbers till {number} is {sum_of_natural}')

if __name__ == '__main__':
    main()