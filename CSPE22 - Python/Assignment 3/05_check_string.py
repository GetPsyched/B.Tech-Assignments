def main():
    """Question 5

    Write a Python program to check each character in the given string is an alphabet or digit.
    """
    string = input('Enter the string --> ')

    alphabets = []
    numbers = []
    for char in string:
        if char.isalpha():
            alphabets.append(char)
        elif char.isdigit():
            numbers.append(char)

    print(f'Alphabets = {alphabets}')
    print(f'Numbers = {numbers}')

if __name__ == '__main__':
   main()
