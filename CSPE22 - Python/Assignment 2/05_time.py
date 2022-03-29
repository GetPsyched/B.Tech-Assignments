def main():
    """Question 5

    Write a program that returns minutes and remaining seconds from an amount of time (in seconds)
    """
    seconds = int(input('Enter time in seconds --> '))
    remaining_seconds = seconds % 60
    minutes = seconds // 60

    print(f'Minutes = {minutes}, Remaining seconds = {remaining_seconds}')

if __name__ == '__main__':
   main()
