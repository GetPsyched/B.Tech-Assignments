def main():
    """Question 1

    Write a simple program of how to print, concatenate a string.
    """
    part1 = 'Hello,'
    part2 = 'World!'

    print(part1 + part2) # basic concat
    print(part1, part2) # arguments separated by a space
    print('$'.join([part1, part2])) # arguments separated by custom separator
    print(part1, part2, sep='#') # arguments separated by custom separator
    print(f'{part1} {part2}') # print using fstrings
    print('{:<10} {:>10}'.format(part1, part2)) # print using .format()

if __name__ == '__main__':
    main()
