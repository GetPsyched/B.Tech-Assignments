import java.util.HashSet;
import java.util.Iterator;
import java.util.Scanner;
import java.util.Set;

public class foobar {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Set<String> set1, set2;
        set1 = Set.of("Chemistry", "Maths", "Biology", "English");
        set2 = Set.of("Biology", "English", "Geography", "Physics");
        HashSet<String> tempSet = new HashSet<String>();

        firstStack(set1, set2, tempSet);
        tempSet.clear();
        secondStack(set1, set2, tempSet);
        tempSet.clear();
        bothStacks(set1, set2, tempSet);

        sc.close();
    }

    public static void firstStack(Set<String> set1, Set<String> set2, HashSet<String> tempSet) {
        Iterator<String> iter1 = set1.iterator();
        Iterator<String> iter2 = set2.iterator();
        boolean flag = true;

        while (iter1.hasNext()) {
            iter2 = set2.iterator();
            String temp = iter1.next();
            flag = true;
            while (iter2.hasNext()) {
                if (temp == iter2.next()) {
                    flag = false;
                    break;
                }
            }

            if (flag)
                tempSet.add(temp);
        }

        System.out.println("Unique books in first stack:");
        for (String string : tempSet)
            System.out.println(string);
    }

    public static void secondStack(Set<String> set1, Set<String> set2, HashSet<String> tempSet) {
        Iterator<String> iter1 = set1.iterator();
        Iterator<String> iter2 = set2.iterator();
        boolean flag = true;

        while (iter2.hasNext()) {
            iter1 = set1.iterator();
            String temp = iter2.next();
            flag = true;
            while (iter1.hasNext()) {
                if (temp == iter1.next()) {
                    flag = false;
                    break;
                }
            }

            if (flag) {
                tempSet.add(temp);
            }
        }

        System.out.println("\nUnique books in second stack:");
        for (String string : tempSet)
            System.out.println(string);
    }

    public static void bothStacks(Set<String> set1, Set<String> set2, HashSet<String> tempSet) {
        Iterator<String> iter1 = set1.iterator();
        Iterator<String> iter2 = set2.iterator();
        boolean flag = true;

        while (iter2.hasNext()) {
            iter1 = set1.iterator();
            String temp = iter2.next();
            flag = false;

            while (iter1.hasNext()) {
                if (temp == iter1.next()) {
                    flag = true;
                    break;
                }
            }

            if (flag)
                tempSet.add(temp);
        }

        System.out.println("\nCommon books in both stacks:");
        for (String string : tempSet)
            System.out.println(string);
    }
}
