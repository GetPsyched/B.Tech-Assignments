def main():
    """Question 2

    Write a script and use the string slicing with positive and negative indexes.
    """
    string = 'Hello, World!'
    
    print(string[1:]) # 2nd char till the end
    print(string[3:5]) # 4th and 5th char
    print(string[:-1]) # 1st char till the 2nd last char
    print(string[6:-2]) # 7th char till the 3rd last char
    print(string[-2]) # 2nd last char

if __name__ == '__main__':
    main()
