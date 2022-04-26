def check_num(num: int) -> str:
    if num > 0:
        return 'positive'
    elif num < 0:
        return 'negative'
    else:
        return 'zero'

def main():
    """Question 1

    Write a Python program to check whether the given number is zero, positive or negative.
    """
    num = int(input('Enter a number --> '))
    value = check_num(num)
    print(f'The given number is {value}.')

if __name__ == '__main__':
    main()
