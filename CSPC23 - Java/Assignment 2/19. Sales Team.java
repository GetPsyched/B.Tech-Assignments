import java.util.*;

public class foobar {
    public static void main(String[] args) {
        SalesTeam team = new SalesTeam("team");

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

        team.addSalesPerson(sp);
        team.weeklyReport();
        System.out.println("All tests passed");
    }
}

class SalesTeam {
    ArrayList<SalesPerson> members;
    String name;

    public SalesTeam(String name) {
        this.name = name;
        members = new ArrayList<>();
    }

    public void addSalesPerson(SalesPerson p) {
        members.add(p);
    }

    public void weeklyReport() {
        System.out.println("Sales team --> " + name);
        int sales = 0;
        for (SalesPerson per : members)
            sales += per.total();

        System.out.println("Total sales --> " + sales);

        for (SalesPerson per : members)
            System.out.println(per.toString());
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
