import java.util.Arrays;
import java.util.Scanner;

public class foobar {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the array starting with its size --> ");
        int n = sc.nextInt();

        int[] arr = new int[n];
        for (int i=0; i < n; i++)
            arr[i] = sc.nextInt();

        System.out.print("Enter k --> ");
        int k = sc.nextInt();
        Arrays.sort(arr);

        for (int i=0; i < n; i++)
            System.out.print(arr[i] + " ");
        System.out.println();
    }
}
