import java.util.*;

public class foobar {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter a string --> ");
        String input = sc.nextLine();
        System.out.print("Enter length --> ");
        int length = sc.nextInt();
        sc.close();

        String padded = pad(input, length);
        System.out.println("Padded String is --> " + padded);
    }

    public static String pad(String s, int length) {
        if (length < s.length())
            return s;

        return s + "0".repeat(length - s.length());
    }
}
