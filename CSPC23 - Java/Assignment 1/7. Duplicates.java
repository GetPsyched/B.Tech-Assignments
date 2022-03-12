import java.util.Scanner;

public class foobar {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter ten numbers --> ");
        int i, list[] = new int[10];
        for (i = 0; i < 10; i++)
            list[i] = scanner.nextInt();

        int result[] = eliminateDuplicates(list);

        System.out.print("The distinct numbers are --> ");
        for (i = 0; i < result.length; i++)
            System.out.print(result[i] + " ");
        System.out.println();
    }

    public static int[] eliminateDuplicates(int[] list) {
        int count = 0;
        int temp[] = new int[10];

        for (int i = 0; i < list.length; i++) {
            boolean exists = false;
            for (int j = 0; j < temp.length; j++)
                if (temp[j] == list[i])
                    exists = true;

            if (!exists)
                temp[count++] = list[i];
        }

        int result[] = new int[count];
        System.arraycopy(temp, 0, result, 0, count);
        return result;
    }
}
