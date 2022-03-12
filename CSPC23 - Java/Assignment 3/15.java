import java.util.Arrays;
import java.time.LocalTime;

public class foobar {
    public static class StopWatch {
        long startTime;
        long endTime;
        public
        StopWatch() {
            startTime = System.currentTimeMillis();
        }
        void start() {
            startTime = System.currentTimeMillis();
        }
        void end() {
            endTime = System.currentTimeMillis();
        }
        long getStartTime() {
            return startTime;
        }
        long getEndTime() {
            return endTime;
        }
        long elapsedTime() {
            return endTime-startTime;
        }
    }

    public static void main(String[] args) {
        int[] randomArray = new int[100000];
        System.out.println("Creating an unsorted array of 100,000 numbers");
        for (int i = 0; i < randomArray.length; i++)
            randomArray[i] = (int) (Math.random() * 100000);
        StopWatch s = new StopWatch();
        s.start();
        Arrays.sort(randomArray);
        s.end();
        System.out.println("Start time is "+s.getStartTime()+"\nEnd time is "+s.getEndTime()+"\nTime Elapsed is "+ s.elapsedTime());
    }
}
