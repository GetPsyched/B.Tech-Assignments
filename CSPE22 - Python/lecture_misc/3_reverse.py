def main():
    """Program to reverse strings with 2 different methods"""
    string = 'Hello, World!'

    # Method 1: Using while loop
    new_str = ''
    l = len(string)
    while l > 0:
        new_str += string[l - 1] # Get lth element of the original string
        l -= 1
    print(new_str)

    # Method 2: Using slicing
    print(string[::-1])

if __name__ == '__main__':
    main()