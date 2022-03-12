import java.util.Random;

public class foobar {
    static class NumberOfSixes {
        int six;
        NumberOfSixes() { six = 0; }
        void setSix() { six++; }
        int getSix() { return six; }
    }

    public static void main(String[] args) {
        NumberOfSixes obj = new NumberOfSixes();
        Random r = new Random();
        for(int i=0; i < r.nextInt(10); i++)
            obj.setSix();
        System.out.println("Total Sixes are " + obj.getSix());
    }
}
