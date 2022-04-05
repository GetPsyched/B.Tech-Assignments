def main():
    """Take an example of either student or employee with at least 5 attributes & takes the values from the user.
    Print these with the help of a dictionary
    """
    student = {}
    for attr in (
        'name',
        'age',
        'mobile',
        'gender',
        'dob'
    ):
        student[attr] = input(f'Input your {attr} --> ')

    for key, value in student.items():
        print(f'{key}: {value}')

if __name__ == '__main__':
    main()
