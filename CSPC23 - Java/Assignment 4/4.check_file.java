import java.io.File;
import java.io.FileNotFoundException;
import java.lang.Character;
import java.util.Scanner;
import java.util.Set;

public class foobar {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int vowelCounter = 0, consonantCounter = 0;
        Set<Character> vowels = Set.of('A', 'a', 'E', 'e', 'I', 'i', 'O', 'o', 'U', 'u');

        System.out.print("Enter name of file --> ");
        File textFile = new File(sc.nextLine() + ".txt");
        sc.close();

        try {
            sc = new Scanner(textFile);
        } catch (FileNotFoundException error) {
            System.out.println("File doesn't exist.");
            return;
        }

        while (sc.hasNextLine()) {
            String str = sc.nextLine();
            char arr[] = str.toCharArray();

            for (char c : arr)
                if (Character.isAlphabetic(c))
                    if (vowels.contains(c))
                        vowelCounter++;
                    else
                        consonantCounter++;
        }
        System.out.println("Number of vowels --> " + vowelCounter);
        System.out.println("Number of consonants --> " + consonantCounter);
    }
}
