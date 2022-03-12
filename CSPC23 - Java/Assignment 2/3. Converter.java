import java.util.Scanner;

public class foobar {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the weight --> ");
        int kg = scanner.nextInt();
        int g = scanner.nextInt();
        int mg = scanner.nextInt();

        String string = "";

        if (kg > 0)
            string += kg > 1 ? kg + " kilograms, " : kg + " kilogram, ";
        if (g > 0)
            string += g > 1 ? g + " grams, " : g + " gram, ";
        if (mg > 0)
            string += mg > 1 ? mg + " milligrams " : mg + " milligram ";

        System.out.println(String.format("\n%sis equivalent to %d milligrams", string, convertToMg(kg, g, mg)));
    }

    public static int convertToMg(int kg, int g, int mg) {
        // Changes the value to 0 if entered value is negative
        kg = kg < 0 ? 0 : kg * 1000000;
        g = g < 0 ? 0 : g * 1000;
        mg = mg < 0 ? 0 : mg;

        return kg + g + mg;
    }
}
