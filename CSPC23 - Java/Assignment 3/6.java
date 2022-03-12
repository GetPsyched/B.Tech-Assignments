import java.util.Scanner;

public class foobar {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the First String --> ");
        String s1 = sc.nextLine();
        System.out.print("Enter the Second String --> ");
        String s2 = sc.nextLine();
        if(s2.contains(s1))
            System.out.println("The second string contains the first string");
        else
            System.out.println("The second string does not contain the first string");

    }
}
