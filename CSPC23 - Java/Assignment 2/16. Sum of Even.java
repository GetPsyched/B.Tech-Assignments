import java.util.Scanner;

public class foobar {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter a number --> ");
        int num = sc.nextInt();
        sc.close();

        if (num < 2) {
            System.out.println("Invalid number!");
            return;
        }

        int sum = 0;
        for (int i = 2; i <= num; i += 2)
            sum += i;

        System.out.println("Sum --> " + sum);
    }
}
