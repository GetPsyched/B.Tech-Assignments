import java.util.Scanner;

public class foobar {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter first string --> ");
        String string1 = scanner.nextLine();

        System.out.print("Enter second string --> ");
        String string2 = scanner.nextLine();

        String prefix = checkPrefix(string1, string2);

        if (!prefix.isEmpty())
            System.out.println("\nThe common prefix is " + prefix);
        else
            System.out.println(String.format("\n%s and %s have no common prefix", string1, string2));
    }

    public static String checkPrefix(String s1, String s2) {
        int len1 = s1.length();
        int len2 = s2.length();

        String prefix = "";

        for (int i = 0; i < len1 && i < len2; i++)
            if (s1.charAt(i) == s2.charAt(i))
                prefix += s1.charAt(i);
            else
                return prefix;

        return prefix;
    }
}
