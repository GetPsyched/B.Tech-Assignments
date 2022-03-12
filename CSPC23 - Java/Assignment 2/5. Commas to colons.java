import java.util.Scanner;

public class foobar {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the string --> ");
        String string = scanner.nextLine();

        System.out.println("\nCorrected string --> " + correctString(string));
    }

    public static String correctString(String s) {
        String corrected = "";
        for (int i = 0; i < s.length(); i++)
            corrected += s.charAt(i) == ',' ? ':' : s.charAt(i);
        return corrected;
    }
}
