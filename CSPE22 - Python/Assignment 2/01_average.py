def main():
    """Question 1

    Compute the average of at least five numbers
    """
    num1 = float(input('Enter 1st number --> '))
    num2 = float(input('Enter 2nd number --> '))
    num3 = float(input('Enter 3rd number --> '))
    num4 = float(input('Enter 4th number --> '))
    num5 = float(input('Enter 5th number --> '))

    avg = (num1 + num2 + num3 + num4 + num5) / 5

    print('Average =', avg)

if __name__ == '__main__':
   main()
