import java.util.Scanner;

public class foobar {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the array starting with its size --> ");
        int n = sc.nextInt();

        int[] arr = new int[n];
        for (int i=0; i < n; i++)
            arr[i] = sc.nextInt();

        int count = 0;
        // Iterates through the given array until it finds a zero
        for(int i=0; i < n - 1; i++)
            if(arr[i] == 0) {
                // Iterates over the rest of the array and shifts
                // the elements to the left if they're not zero
                for(int j=i; j < n - 1; j++)
                    if(arr[j+1] != 0)
                        arr[j - count] = arr[j+1];
                    else
                        count++;
                count++;
                break;
            }

        // Changes the last few elements to zero depending on `count`
        for(int i=n-1; i > (n-1) - count; i--)
            arr[i] = 0;

        for (int i=0; i < n; i++)
            System.out.print(arr[i] + " ");
        System.out.println();
    }
}
