import java.util.Scanner;

public class foobar {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter balance --> ");
        double bal = sc.nextDouble();
        System.out.print("Enter interest rate --> ");
        double rate = sc.nextDouble();

        System.out.println(String.format("Next month's interest --> %.2f", bal * (rate/1200)));
    }
}
