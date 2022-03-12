import java.util.*;

public class vowels {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter a string --> ");
        String input = sc.nextLine();
        sc.close();

        int a = 0;
        int e = 0;
        int i = 0;
        int o = 0;
        int u = 0;

        int nonVowel = 0;

        for (int j = 0; j < input.length(); j++) {
            char ch = input.charAt(j);
            switch (ch) {
            case 'a':
                a++;
                break;
            case 'e':
                e++;
                break;
            case 'i':
                i++;
                break;
            case 'o':
                o++;
                break;
            case 'u':
                u++;
                break;

            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                break;

            default:
                if (Character.isLetter(ch))
                    nonVowel++;
            }
        }
        System.out.println("a = " + a);
        System.out.println("e = " + e);
        System.out.println("i = " + i);
        System.out.println("o = " + o);
        System.out.println("u = " + u);
        System.out.println("Non vowels = " + nonVowel);
    }
}
