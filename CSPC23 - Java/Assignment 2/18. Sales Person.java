import java.util.*;

public class foobar {
    public static void main(String[] args) {
        SalesPerson sp = new SalesPerson("someName", "9999999999", "someDistrict");
        sp.setDailyAmount(0, 1000);
        sp.setDailyAmount(1, 2000);
        sp.setDailyAmount(2, 3000);
        sp.setDailyAmount(3, 4000);
        sp.setDailyAmount(4, 5000);

        assert sp.getDailyAmount(2) == 3000;
        assert sp.getDailyAmount(4) == 5000;

        assert sp.total() == 15000;
        assert (int) sp.avg() == (int) (15000 / 7);

        System.out.println("All tests passed");
    }
}

class SalesPerson {
    String name;
    String phoneNum;
    String district;
    int[] sales;

    public SalesPerson(String name, String phoneNum, String district) {
        this.name = name;
        this.phoneNum = phoneNum;
        this.district = district;
        sales = new int[] { 0, 0, 0, 0, 0, 0, 0 };
    }

    public int getDailyAmount(int day) {
        return sales[day];
    }

    public void setDailyAmount(int day, int amt) {
        this.sales[day] = amt;
    }

    public int total() {
        int sum = 0;
        for (int val : sales)
            sum += val;
        return sum;
    }

    public double avg() {
        return total() / 7.0;
    }

    @Override
    public String toString() {
        return "\nName --> " + name + "\nDistrict --> " + district + "\nPhone --> " + phoneNum + "\nTotal sales --> "
                + total();
    }
}
