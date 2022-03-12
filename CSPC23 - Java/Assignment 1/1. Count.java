import java.util.Scanner;

public class foobar {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the string --> ");
        String string = scanner.nextLine();

        System.out.println("\nNumber of letters in the string --> " + countLetters(string));
    }

    public static int countLetters(String s) {
        int count = 0;
        for (int i = 0; i < s.length(); i++)
            if (Character.isLetter(s.charAt(i)))
                count++;
        return count;
    }
}
