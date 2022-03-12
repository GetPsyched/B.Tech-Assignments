public class GoalTracker {
    public static void main(String[] args) {
        NumberOfGoals obj1 = new NumberOfGoals();
        NumberOfGoals obj2 = new NumberOfGoals();

        System.out.println("Initial values --> " + obj1.getGoal() + " " + obj2.getGoal());
        obj1.setGoal();
        obj2.setGoal();
        System.out.println("After 1st iteration --> " + obj1.getGoal() + " " + obj2.getGoal());
        obj1.setGoal();
        System.out.println("After 2nd iteration --> " + obj1.getGoal() + " " + obj2.getGoal());
        obj2.setGoal();
        obj2.setGoal();
        System.out.println("After 3rd iteration --> " + obj1.getGoal() + " " + obj2.getGoal());
    }
}

class NumberOfGoals {
    int goals;

    NumberOfGoals() {
        goals = 0;
    }

    void setGoal() {
        goals++;
    }

    int getGoal() {
        return goals;
    }
}
