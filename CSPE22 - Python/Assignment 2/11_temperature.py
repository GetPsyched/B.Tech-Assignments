def main():
    """Question 11

    Write a program to convert temperature in Celsius to Fahrenheit
    """
    # Input the numbers
    celsius = float(input("Enter the temperature in Celsius --> "))

    # Conversion
    fahrenheit = celsius * 1.8 + 32

    # Printing the temperature in Fahrenheit
    print(f'Temperature in fahrenheit = {fahrenheit}')

if __name__ == '__main__':
   main()
