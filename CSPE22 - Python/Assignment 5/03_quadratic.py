import math

def get_roots(a, b, c) -> tuple:
    """Return the roots of a quadratic equation"""

    # Calculating discriminant using the following formula
    discriminant = b * b - 4 * a * c
    sqrt_dis = math.sqrt(abs(discriminant))

    # Checking the nature of the rots
    if discriminant > 0:
        return (-b + sqrt_dis) / (2 * a), (-b - sqrt_dis) / (2 * a)

    elif discriminant == 0:
        return -b / (2 * a), -b / (2 * a)

    else:
        return (
            '{:.2f} + {:.2f}i'.format(-b / (2 * a), sqrt_dis / (2 * a)),
            '{:.2f} - {:.2f}i'.format(sqrt_dis / (2 * a), -b / (2 * a))
        )

def main():
    """Question 3

    Write a Python program to display the roots of a quadratic equation.
    """
    a, b, c = map(int, input(f'Enter the constants for the quadratic equation ax² + bx + c --> ').split())

    # If a is 0, then incorrect equation
    if a == 0:
        print('Input a correct quadratic equation and try again!')
    else:
        root1, root2 = get_roots(a, b, c)
        if isinstance(root1, str):
            print(f'The roots of the equation are {root1} and {root2}')
        else:
            print(f'The roots of the equation are {root1:.2f} and {root2:.2f}')

if __name__ == '__main__':
    main()
