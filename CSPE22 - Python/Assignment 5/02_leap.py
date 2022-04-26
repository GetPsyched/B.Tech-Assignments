def is_leap_year(year: int) -> bool:
    if not year % 4:
        if not year % 100:
            if not year % 400:
                return True
        else:
            return True
    return False

def main():
    """Question 2

    Write a Python program to check whether the given year is leap year or not.
    """
    num = int(input('Enter a year --> '))
    value = '' if is_leap_year(num) else 'not '
    print(f'The given year is {value}a leap year.')

if __name__ == '__main__':
    main()
