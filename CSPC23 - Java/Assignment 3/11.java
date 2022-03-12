import java.util.Scanner;

public class foobar {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] arr = new int[5];
        int j = -1;
        for(int i=0; i < 5; i++) {
            System.out.print("Enter the element --> ");
            int n = sc.nextInt();
            boolean check = false;
            for(int k=0; k <= j; k++)
                if(arr[k] == n) {
                    check = true;
                    break;
                }
            if(!check)
                arr[++j] = n;
            for(int x=0; x <= j; x++)
                System.out.print(arr[x] + " ");
            System.out.println();
        }
    }
}
