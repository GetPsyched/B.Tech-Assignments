import java.util.Scanner;

public class foobar {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the first string --> ");
        String s1 = sc.nextLine();
        System.out.print("Enter the second string --> ");
        String s2 = sc.nextLine();
        if(s1.contains(s2))
            System.out.println("Yes");
        else
            System.out.println("No");
    }
}
