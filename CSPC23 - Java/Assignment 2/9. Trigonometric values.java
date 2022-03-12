import java.util.Random;
import java.lang.Math;

public class foobar {
    public static void main(String[] args) {
        Random rand = new Random();
        int number = rand.nextInt(21) + 20;

        double sin = Math.sin(number);
        double cos = Math.cos(number);
        double tan = Math.tan(number);

        System.out.println("Generated number is --> " + number);
        System.out.println("Sine --> " + sin);
        System.out.println("Cosine --> " + cos);
        System.out.println("Tangent --> " + tan);
    }
}
