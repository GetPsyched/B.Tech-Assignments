import java.util.Scanner;

public class foobar {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter first number --> ");
        int num1 = sc.nextInt();
        System.out.print("Enter second number --> ");
        int num2 = sc.nextInt();

        if (num1 % num2 == 0)
            System.out.println("The first number is a multiple of second");
        else
            System.out.println("The first number is not a multiple of second");
    }
}
