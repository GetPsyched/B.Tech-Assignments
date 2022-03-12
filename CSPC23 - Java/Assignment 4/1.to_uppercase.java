import java.util.ArrayList;
import java.util.ListIterator;
import java.util.Scanner;

public class foobar {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList<String> strings = new ArrayList<String>();

        System.out.print("Enter the number of strings --> ");
        int n = sc.nextInt();
        sc.nextLine();

        System.out.println("Enter the strings:");
        int i;
        for (i = 0; i < n; i++) {
            System.out.print("Enter string " + (i + 1) + " --> ");
            strings.add(sc.nextLine());
        }

        ArrayList<String> upperCaseStrings;
        upperCaseStrings = usingIterator(strings);
        upperCaseStrings = usingLoop(strings);
        upperCaseStrings = usingReplaceAll(strings);

        System.out.println("\nArray of strings is:");
        for (String string : upperCaseStrings)
            System.out.println(string);
    }

    public static ArrayList usingIterator(ArrayList<String> strings) {
        ListIterator<String> iter = strings.listIterator();
        while (iter.hasNext())
            iter.set(iter.next().toUpperCase());
        return strings;
    }

    public static ArrayList usingLoop(ArrayList<String> strings) {
        for (int i = 0; i < strings.size(); i++)
            strings.set(i, strings.get(i).toUpperCase());
        return strings;
    }

    public static ArrayList usingReplaceAll(ArrayList<String> strings) {
        ListIterator<String> iter = strings.listIterator();
        while (iter.hasNext()) {
            String temp = iter.next();
            iter.set(temp.replaceAll(temp, temp.toUpperCase()));
        }
        return strings;
    }

}
