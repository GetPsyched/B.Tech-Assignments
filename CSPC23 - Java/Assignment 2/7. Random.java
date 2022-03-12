import java.util.Random;

public class foobar {
    public static void main(String[] args) {
        Random rand = new Random();

        System.out.println(rand.nextInt(11));
        System.out.println(rand.nextInt(401));
        System.out.println(rand.nextInt(10) + 1);
        System.out.println(rand.nextInt(400) + 1);
        System.out.println(rand.nextInt(26) + 25);
        System.out.println(rand.nextInt(26) - 10);
    }
}
