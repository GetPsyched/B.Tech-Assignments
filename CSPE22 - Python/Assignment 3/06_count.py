def main():
    """Question 6

    Write a Python program to count the numbers of occurrences of characters in the given string and store them in a dictionary.
    """
    string = input('Enter the string --> ')
    occurrences = {}

    for char in string:
        occurrences[char] = string.count(char)

    for char, freq in occurrences.items():
        print(f'Frequency of {char} = {freq}')

if __name__ == '__main__':
   main()
