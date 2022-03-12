import java.util.Scanner;

public class foobar {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter x, y, p respectively --> ");
        int x = sc.nextInt();
        int y = sc.nextInt();
        int p = sc.nextInt();
        int count = 0;
        for(int i=x; i <= y; i++)
            if(i % p == 0)
                count++;
        System.out.println("Number of integers between "+x+" and "+y+" which are divisible by "+p+" are "+count);

    }
}
