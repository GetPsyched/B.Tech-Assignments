import random

def get_category(bmi: float) -> str:
    """Return the BMI category of the given BMI"""
    if 0 <= bmi < 18.5:
        return 'underweight'
    if 18.5 <= bmi < 25:
        return 'healthy'
    if 25 <= bmi < 30:
        return 'overweight'
    if 30 <= bmi:
        return 'obese'
    return 'invalid'

def main():
    """Question 5

    Write a program that lets the user guess whether a flipped coin displays \
    the head or the tail. For this, the program randomly generates a number \
    0 or 1, which represents head or tail. The program prompts the user to \
    enter a guess and reports whether the guess is correct or incorrect.
    """
    play_again = 'y'
    while play_again == 'y':
        coin_face = random.choice(['heads', 'tails'])
        guess = input('The program has flipped a coin, guess heads or tails --> ').lower()
        if guess == coin_face:
            print("Your guess is correct! Computer's choice was", coin_face)
        else:
            print("Your guess was incorrect! Computer's choice was", coin_face)

        play_again = input('Would you like to play again? (y/n) --> ').lower()

if __name__ == '__main__':
    main()
