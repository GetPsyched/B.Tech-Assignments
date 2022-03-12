import java.util.Scanner;

public class foobar {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter first string --> ");
        String string1 = scanner.nextLine();

        System.out.print("Enter second string --> ");
        String string2 = scanner.nextLine();

        if (checkSubstring(string1, string2))
            System.out.println(String.format("\n%s is a substring of %s", string2, string1));
        else
            System.out.println(String.format("\n%s is not a substring of %s", string2, string1));
    }

    public static boolean checkSubstring(String s1, String s2) {
        int len1 = s1.length();
        int len2 = s2.length();

        if (len2 > len1)
            return false;

        int i, j;
        for (i = 0; i < len1 - len2; i++)
            for (j = 0; j < len2; j++)
                if (s1.charAt(i + j) != s2.charAt(j))
                    break;
                else if (j == len2 - 1)
                    return true;

        return false;
    }
}
