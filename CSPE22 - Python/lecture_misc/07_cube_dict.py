def cube_dict(numbers: map) -> dict[int, int]:
    return {num: num ** 3 for num in numbers}

def main():
    """Define a function that takes input as number and returns a dictionary containing the cube of those numbers"""
    numbers = map(int, input('Enter the numbers --> ').split())

    for key, value in cube_dict(numbers).items():
        print(f'{key}: {value}')

if __name__ == '__main__':
    main()
