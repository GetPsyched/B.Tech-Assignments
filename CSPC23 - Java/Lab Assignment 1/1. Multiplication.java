import java.util.Scanner;

public class foobar {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the number --> ");
        int num = sc.nextInt();
        int result = multiply(num);

        System.out.println("Multiplication of all digits --> " + result);
    }

    public static int multiply(int num) {
        int result = 1;
        while(num > 0) {
            result *= num % 10;
            num /= 10;
        }
        return result;
    }
}
