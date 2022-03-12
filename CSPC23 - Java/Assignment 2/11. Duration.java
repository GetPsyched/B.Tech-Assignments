public class DurationTest {
    public static void main(String[] args) {
        Duration dr = new Duration(02, 50, 4, 50);
        assert dr.length() == 120;
        for (int i = 0; i < 24; i++) {
            Duration dri = new Duration(0, 0, i, 50);
            assert dri.length() == i * 60 + 50;
            dri.setEndHr(i / 2);
            assert dri.length() == i / 2 * 60 + 50;
            dri.setEndMin(i);
            assert dri.length() == i / 2 * 60 + i;
            dri.setStartHr(i / 3);
            assert dri.length() == i / 2 * 60 + i - i / 3 * 60;
        }
    }
}

class Duration {
    int startHr;
    int startMin;
    int endHr;
    int endMin;

    public Duration(int startHr, int startMin, int endHr, int endMin) {
        this.startHr = startHr;
        this.startMin = startMin;
        this.endHr = endHr;
        this.endMin = endMin;
    }

    public int length() {
        return 60 * (endHr - startHr) + (endMin - startMin);
    }

    @Override
    public String toString() {
        return String.format("[%02d:%02d, %02d:%02d]", startHr, startMin, endHr, endMin);
    }

    public int getStartHr() {
        return startHr;
    }

    public int getStartMin() {
        return startMin;
    }

    public void setStartHr(int startHr) {
        this.startHr = startHr;
    }

    public void setStartMin(int startMin) {
        this.startMin = startMin;
    }

    public int getEndHr() {
        return endHr;
    }

    public int getEndMin() {
        return endMin;
    }

    public void setEndHr(int endHr) {
        this.endHr = endHr;
    }

    public void setEndMin(int endMin) {
        this.endMin = endMin;
    }
}
