import java.util.Scanner;

public class foobar {
   public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);

      System.out.print("Enter the number --> ");
      int num = sc.nextInt();

      System.out.println("Binary --> " + Integer.toBinaryString(num));
      System.out.println("Octal --> " + Integer.toOctalString(num));
      System.out.println("Hexadecimal --> " + Integer.toHexString(num));
   }
}
