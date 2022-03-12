import java.util.Scanner;

public class foorbar {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter time in minutes --> ");
        int min = sc.nextInt();
        int years = min / (365*24*60);

        int days = min - (years * 365*24*60);
        days /= 24 * 60;

        System.out.println(String.format("%s years and %s days", years, days));
    }
}
