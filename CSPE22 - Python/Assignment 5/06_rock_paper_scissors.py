import random

def battle(choice: str):
    options = 'rock', 'paper', 'scissors'

    compMove = random.choice(options)
    if options[(options.index(choice) + 1) % 3] == compMove:
        print(f'{choice.title()} beats {compMove.title()}. You won!')
    elif choice == compMove:
        print('You both had the same move. Draw!')
    else:
        print(f'{compMove.title()} beats {choice.title()}. You lost!')

def main():
    """Question 6

    Write a program that plays the popular rock-paper-scissor game. \
    Instruction: A scissor can cut the paper, a rock can knock a scissor, \
    and a paper can wrap a rock. For this, the program randomly generates a \
    number 0, 1, or 2 representing scissor, rock, and paper. The program \
    prompts the user to enter a number 0, 1, or 2 and displays a message \
    indicating whether the user or the computer wins, loses, or draws.
    """
    play_again = 'y'
    while play_again == 'y':
        choice = input('Rock!! Paper!! Scissors!!: ').lower()
        battle(choice)

        play_again = input('Would you like to play again? (y/n) --> ').lower()

if __name__ == '__main__':
    main()
