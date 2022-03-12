import java.util.Random;

public class foobar {
    public static void main(String[] args) {
        String password = "";
        Random rand = new Random();

        password += rand.nextInt(3) + 7;
        for (int i = 0; i < 5; i++)
            password += rand.nextInt(10);
        password += "-";
        for (int i = 0; i < 5; i++)
            password += (char) (rand.nextInt(27) + 65);

        System.out.println("Password --> " + password);
    }
}
