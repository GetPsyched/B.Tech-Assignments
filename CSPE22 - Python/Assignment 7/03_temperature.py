def celsiusToFahrenheit(celsius):
    fahrenheit = (9 / 5) * celsius + 32
    return fahrenheit

def fahrenheitToCelsius(fahrenheit):
    celsius = (5 / 9) * (fahrenheit - 32)
    return celsius

def main():
    """Question 3

    Write a module that contains the following two functions:
    # Converts from Celsius to Fahrenheit
        def celsiusToFahrenheit(celsius):
    # Converts from Fahrenheit to Celsius
        def fahrenheitToCelsius(fahrenheit):

    The formulas for the conversion are:
        celsius = (5 / 9) * (fahrenheit - 32)
        fahrenheit = (9 / 5) * celsius + 32
    """
