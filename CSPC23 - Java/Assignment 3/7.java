import java.util.Scanner;

public class foobar {
    public static void main(String [] args){
        System.out.print("Enter first string --> ");
        Scanner sc = new Scanner(System.in);
        String s1 = sc.nextLine();
        System.out.print("Enter second string --> ");
        String s2 = sc.nextLine();
        int comp = s1.compareTo(s2);
        if (comp < 0)
            System.out.println("String 1 is greater than string 2");
        else if (comp == 0)
            System.out.println("String 1 is equal to string 2");
        else
            System.out.println("String 1 is less than string 2");
    }
}
