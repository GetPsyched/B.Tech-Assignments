import java.util.Scanner;

public class foobar {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number --> ");
        int n = sc.nextInt();
        String num = Integer.toString(n);
        int check = 1;
        for(int i=0,j=num.length()-1;i<j;i++,j--)
            if(num.charAt(i)!=num.charAt(j)) {
                check = 0;
                break;
            }
        if(check == 0)
            System.out.println("The number is not a palindrome");
        else
            System.out.println("The number is a Palindrome");

    }
}
