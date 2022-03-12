import java.io.File;
import java.io.FileNotFoundException;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class foobar {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Scanner text = new Scanner(System.in);
        Set<String> names = new HashSet<String>();

        System.out.print("Enter number of files --> ");
        int n = sc.nextInt();
        sc.nextLine();

        for (int i = 0; i < n; i++) {
            System.out.print("Enter name of file " + (i + 1) + " --> ");
            sc = new Scanner(System.in);
            File textFile = new File(sc.nextLine() + ".txt");

            try {
                text = new Scanner(textFile);
            } catch (FileNotFoundException error) {
                System.out.println("File doesn't exist.");
                return;
            }

            while (text.hasNextLine()) {
                String name = text.nextLine();
                names.add(name);
            }
        }
        System.out.println("Students that have attended at least on day of the course:");
        for (String name : names) {
            System.out.println(name);
        }
    }
}
