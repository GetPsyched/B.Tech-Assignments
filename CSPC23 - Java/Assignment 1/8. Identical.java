import java.util.Scanner;

public class foobar {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter first list --> ");
        int list1[] = new int[scanner.nextInt()];
        for (int i = 0; i < list1.length; i++)
            list1[i] = scanner.nextInt();

        System.out.print("Enter second list --> ");
        int list2[] = new int[scanner.nextInt()];
        for (int i = 0; i < list2.length; i++)
            list2[i] = scanner.nextInt();

        if (equals(list1, list2))
            System.out.println("\nTwo lists are identical");
        else
            System.out.println("\nTwo lists are not identical");
    }

    public static boolean equals(int[] list1, int[] list2) {
        if (list1.length != list2.length)
            return false;

        for (int i = 0; i < list1.length; i++) {
            boolean exists = false;
            for (int j = 0; j < list2.length; j++)
                if (list1[i] == list2[j]) {
                    exists = true;
                    list2[j] = '\0';
                    break;
                }

            if (!exists)
                return false;
        }

        return true;
    }
}
