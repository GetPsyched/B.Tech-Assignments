import java.util.Scanner;

public class foobar {
    public static void main(String[] args) {
        String paragraph = String.join(" ", "This semester, a new course on %s",
                "has been added to the curriculum. It consists of %s credits",
                "and the reference book for this course is %s.");
        Scanner sc = new Scanner(System.in);
        String courseName, credits, refBook;

        System.out.print("Enter course name --> ");
        courseName = sc.nextLine();
        System.out.print("Enter credits --> ");
        credits = sc.nextLine();
        System.out.print("Enter name of reference book --> ");
        refBook = sc.nextLine();

        System.out.println(String.format(paragraph, courseName, credits, refBook));

        sc.close();
    }
}
