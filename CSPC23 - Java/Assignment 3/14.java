public class foobar {
    static class SavingsAccount{
        static float annualInterestRate;
        private float savingsBalance;
        SavingsAccount(float money) {savingsBalance=money;}
        float calculateMonthlyInterest() {
            return savingsBalance+=(savingsBalance*annualInterestRate)/12;
        }
        static void modifyInterestRate(float i) { annualInterestRate = i; }
    }

    public static void main(String[] args) {
        SavingsAccount saver1 = new SavingsAccount(2000);
        SavingsAccount saver2 = new SavingsAccount(3000);
        saver1.modifyInterestRate(4);
        System.out.println("For saver1");
        for(int i=0; i < 12; i++)
            System.out.println("Balance after "+(i+1)+ " month-->"+saver1.calculateMonthlyInterest());
        System.out.println();
        System.out.println("For saver2");
        for(int i=0; i < 12; i++)
            System.out.println("Balance after "+(i+1)+ " month-->"+saver2.calculateMonthlyInterest());
        System.out.println("With new interest rate:");
        saver1.modifyInterestRate(5);
        System.out.println("Balance for saver1 is "+saver1.calculateMonthlyInterest());
        System.out.println("Balance for saver2 is "+saver2.calculateMonthlyInterest());
    }
}
