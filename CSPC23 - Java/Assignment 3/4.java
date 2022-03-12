import java.util.Scanner;

public class foobar {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the array starting with its size --> ");
        int n = sc.nextInt();

        int[] arr = new int[n];
        for (int i=0; i < n; i++)
            arr[i] = sc.nextInt();

        int check=1;
        for (int i=0; i < n-3; i++)
            if(arr[i+1] > arr[i] && arr[i+2] > arr[i+1]) {
                System.out.println("Yes it contains 3 adjacent numbers in increasing order");
                check=0;
            }
        if(check == 1)
            System.out.println("Three increasing adjacent numbers not found");
    }
}
