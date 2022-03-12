import java.util.Scanner;

public class foobar {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the password --> ");
        String string = scanner.nextLine();

        if (validatePassword(string))
            System.out.println("Valid Password");
        else
            System.out.println("Invalid Password");
    }

    public static boolean validatePassword(String s) {
        int len = s.length();

        if (len < 8)
            return false;

        int digits = 0;
        for (int i = 0; i < len; i++) {
            if (!Character.isLetterOrDigit(s.charAt(i)))
                return false;
            if (Character.isDigit(s.charAt(i)))
                digits++;
        }

        if (digits < 2)
            return false;

        return true;
    }
}
