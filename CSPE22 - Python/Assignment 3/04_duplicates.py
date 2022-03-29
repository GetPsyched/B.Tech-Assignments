def main():
    """Question 4

    Write a Python program to find duplicate characters in the given string and store them in a list.
    """
    string = input('Enter the string --> ')
    duplicates = set()

    for char in string:
        if string.count(char) > 1:
            duplicates.add(char)

    print(f'Duplicates = {duplicates}')

if __name__ == '__main__':
    main()
