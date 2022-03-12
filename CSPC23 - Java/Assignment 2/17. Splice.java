import java.util.Scanner;

public class foobar {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter a string --> ");
        String str = sc.nextLine();
        System.out.print("Enter start index --> ");
        int startingIndex = sc.nextInt();
        System.out.print("Enter delete count --> ");
        int deleteLength = sc.nextInt();

        String string = splice(str, startingIndex, deleteLength);

        System.out.println("Result is " + string);
    }

    public static String splice(String str, int start, int del) {
        if (start < 0)
            start = 0;
        return str.substring(0, start) + str.substring(start + del);
    }
}
