import java.util.Arrays;
import java.util.Random;
import java.util.Scanner;

public class foobar {
    public static void main(String[] args) {
        char playing = 'y';
        Scanner sc = new Scanner(System.in);

        int lost = 0;
        int won = 0;
        int tie = 0;
        while (playing == 'y') {
            switch (playGame(sc)) {
            case 1:
                won++;
                break;
            case -1:
                lost++;
                break;
            case 0:
                tie++;
                break;
            }
            System.out.print("\nDo you want to keep playing? [y/n] ");
            playing = sc.next().charAt(0);
            System.out.println();
        }

        System.out.println("Final stats:" + "\nWon  - " + won + "\nLost - " + lost + "\nTie  - " + tie + "\n");
    }

    static String[] choices = { "rock", "paper", "scissor" };

    static int playGame(Scanner sc) {
        int myChoice = new Random().nextInt(3);

        System.out.print("Choose [rock/paper/scissor] --> ");
        String userChoice = sc.next();

        int userChoiceInt = Arrays.asList(choices).indexOf(userChoice.toLowerCase());
        if (userChoiceInt == -1) {
            System.out.println("Invalid Choice!");
            return -1;
        }
        System.out.print("I choose " + choices[myChoice] + ", ");

        switch (userChoiceInt - myChoice) {
        case 1:
        case -2:
            System.out.println("You win!");
            return 1;

        case -1:
        case 2:
            System.out.println("You lose");
            return -1;

        case 0:
            System.out.println("Tie");
            return 0;
        default:
            return 0;
        }
    }
}
