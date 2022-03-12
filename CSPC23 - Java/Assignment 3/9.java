import java.util.Scanner;

public class foobar {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the String --> ");
        String s1 = sc.nextLine();
        System.out.println("Trimmed string is " + s1.trim());
    }
}
