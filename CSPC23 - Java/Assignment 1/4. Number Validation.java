import java.util.Scanner;

public class foobar {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter a SSN --> ");
        String ssn = scanner.nextLine();

        if (validateNumber(ssn))
            System.out.println(ssn + " is a valid SSN");
        else
            System.out.println(ssn + " is an invalid SSN");
    }

    public static boolean validateNumber(String s) {
        if (s.length() < 11)
            return false;

        try {
            Integer.parseInt(s.substring(0, 3));
            Integer.parseInt(s.substring(4, 6));
            Integer.parseInt(s.substring(7, 11));
        } catch (NumberFormatException e) {
            return false;
        }

        if (s.charAt(3) != '-' || s.charAt(6) != '-')
            return false;

        return true;
    }
}
