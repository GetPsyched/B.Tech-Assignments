import java.util.Scanner;

public class foobar {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of values --> ");
        int n = scanner.nextInt();

        System.out.print("Enter the values --> ");
        int i;
        int values[] = new int[n];
        for (i = 0; i < n; i++)
            values[i] = scanner.nextInt();

        if (isConsecutiveFour(values))
            System.out.println("\nThe list has consecutive fours");
        else
            System.out.println("\nThe list has no consecutive fours");
    }

    public static boolean isConsecutiveFour(int[] values) {
        int count = 0;
        for (int num = 1; num < values.length; num++) {
            if (values[num] == values[num - 1])
                count += 1;
            else
                count = 1;
            if (count == 4)
                return true;
        }
        return false;
    }
}
