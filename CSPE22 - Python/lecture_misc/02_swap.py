a: int
b: int

def initialise():
    global a, b
    a = 20
    b = 10

def main():
    """Program to swap 2 integers using 2 different methods"""
    global a, b  # This tells the interpreter that the variables will be used from the global scope
    initialise() # Initialise the global variables with default values

    # With temp variable
    temp = a
    a = b
    b = temp
    # Now; a = 10, b = 20
    print(f'{a = }, {b = }')

    initialise() # This will revert the values of 'a' and 'b' to their initial values

    # Without temp variable
    b, a = a, b
    # Now; a = 10, b = 20
    print(f'{a = }, {b = }')

if __name__ == '__main__':
    main()