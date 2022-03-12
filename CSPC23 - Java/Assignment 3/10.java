import java.util.Scanner;

public class foobar {
    public static void main(String[] args) {
        int[] arr = new int[101];
        Scanner sc = new Scanner(System.in);
        int n = 0;
        while(n != -1) {
            System.out.print("Enter the number --> ");
            n = sc.nextInt();
            if(n != -1)
                arr[n]++;
        }
        for(int i=2; i <= 100; i++)
            if(i % 2 == 0 && arr[i] != 0) {
                System.out.print(i + "->" + arr[i]);
                System.out.println();
            }
    }
}
