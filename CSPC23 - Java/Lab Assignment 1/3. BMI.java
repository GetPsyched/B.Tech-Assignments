import java.util.Scanner;

public class foobar {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter weight --> ");
        double weight = sc.nextDouble();
        System.out.print("Enter height --> ");
        double height = sc.nextDouble();

        System.out.println(BMI(weight, height));
    }

    public static String BMI(double weight, double height) {
        weight *= 0.45359237;
        height *= 0.0254;
        double bmi = weight / (height*height);

        String str = "";

        if (bmi < 18.5) str = "Underweight";
        else if (bmi >= 18.5 && bmi < 25) str = "Healthy";
        else if (bmi > 25 && bmi < 30) str = "Overweight";
        else if (bmi > 30) str = "Obese";

        return String.format("BMI --> %.2f (%s)", bmi, str);
    }
}
