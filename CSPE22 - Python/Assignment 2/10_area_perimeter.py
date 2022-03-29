def main():
    """Question 10

    Write a program to find the area and perimeter of a rectangle
    """
    # Input the numbers
    length = float(input("Enter the length of the rectangle --> "))
    breadth = float(input("Enter the breadth of the rectangle --> "))

    # Area
    area = length * breadth

    # Perimeter
    peri = 2 * (length + breadth)

    # Printing the results
    print(f'Quotient = {area}')
    print(f'Perimeter = {peri}')

if __name__ == '__main__':
   main()
