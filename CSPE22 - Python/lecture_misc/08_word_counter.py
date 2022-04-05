def main():
    """Solve the word counter problem with the help of a dictionary"""
    string = input('Enter the string --> ')
    word_counter = {}
    for word in string.split():
        counter = word_counter.get(word)
        counter = counter + 1 if counter else 1
        word_counter[word] = counter

    for key, value in word_counter.items():
        print(f'{key}: {value}')


if __name__ == '__main__':
    main()
