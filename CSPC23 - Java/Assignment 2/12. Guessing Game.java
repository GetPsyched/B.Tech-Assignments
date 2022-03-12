import java.util.Random;
import java.util.Scanner;

public class foobar {
    public static void main(String[] args) {
        char playing = 'y';
        Scanner sc = new Scanner(System.in);

        while (playing == 'y') {
            playGame(sc);
            System.out.print("Do you want to keep playing? [y/n] ");
            playing = sc.next().charAt(0);
        }
    }

    static void playGame(Scanner sc) {
        char quit;
        int answer = new Random().nextInt(101);
        int guess, tries = 0;
        do {
            System.out.print("Choose a number --> ");
            guess = sc.nextInt();
            if (guess == answer) {
                System.out.println("You won in " + tries + " tries!");
                break;
            }
            if (guess < answer)
                System.out.println("You guess is too low");
            else if (guess > answer)
                System.out.println("You guess is too high");

            System.out.print("Do you want to quit? [y/n] ");
            quit = sc.next().charAt(0);
            tries++;
        } while (quit == 'n');
    }
}
