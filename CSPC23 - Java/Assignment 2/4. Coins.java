import java.util.Scanner;

public class foobar {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of quarters, dimes, nickels and pennies --> ");
        int quarters = scanner.nextInt();
        int dimes = scanner.nextInt();
        int nickels = scanner.nextInt();
        int pennies = scanner.nextInt();

        int cents = 0;
        cents += quarters < 0 ? 0 : quarters * 25;
        cents += dimes < 0 ? 0 : dimes * 10;
        cents += nickels < 0 ? 0 : nickels * 5;
        cents += pennies < 0 ? 0 : pennies;

        int dollars = cents / 100;
        cents -= dollars * 100;

        System.out.println("\nValue --> " + dollars + " dollars, " + cents + " cents");
    }
}
