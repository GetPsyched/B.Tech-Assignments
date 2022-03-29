def main():
    """Question 2

    Python program to find smallest and largest number in a list.
    """
    element_map = map(int, input('Enter the elements --> ').split())
    print(f'Smallest = {min(element_map)}')
    print(f'Largest = {max(element_map)}')

if __name__ == '__main__':
   main()
