import java.time.Year;
import java.util.ArrayList;
import java.util.Scanner;

public class PhoneCheck {
    public static void main(String[] args) {
        ArrayList<Phone> phones = new ArrayList<Phone>();
        Scanner sc = new Scanner(System.in);
        char choice;

        do {
            Phone temp = new Phone();

            System.out.print("Enter make --> ");
            temp.setMake(sc.nextLine());
            System.out.print("Enter model --> ");
            temp.setModel(sc.nextLine());
            System.out.print("Enter year of manufacture --> ");
            if (!temp.setYear(sc.nextInt()))
                System.out.println("Invalid year!");
            else
                phones.add(temp);
            sc.nextLine();

            System.out.print("Do you want to enter more (y/n)? ");
            choice = sc.nextLine().toLowerCase().charAt(0);
        } while (choice == 'y');

        int i = 1;
        for (Phone phone : phones) {
            System.out.println("Phone " + i + " : " + phone.phoneToString());
            if (phone.isObsolete())
                System.out.println("This model is obsolete.");
            ++i;
        }

        sc.close();
    }
}

class Phone {

    private String make, model;
    private int year;
    private static int currentYear = Year.now().getValue();

    Phone() {
        make = null;
        model = null;
        year = 0;
    }

    String getMake() {
        return make;
    }

    void setMake(String customMake) {
        make = customMake;
    }

    String getModel() {
        return model;
    }

    void setModel(String customModel) {
        model = customModel;
    }

    int getYear() {
        return year;
    }

    boolean setYear(int customYear) {
        if (customYear > currentYear)
            return false;
        else
            year = customYear;
        return true;
    }

    String phoneToString() {
        String formatString = "This phone is the %s model with make %s, and manufactured in year %d.";

        return String.format(formatString, model, make, year);
    }

    boolean isObsolete() {
        return (currentYear - year >= 10);
    }
}
