import java.util.*;

public class Main {

    static class City implements Comparable<City> {
        int activities;
        int decrease;

        City(int a, int d) {
            this.activities = a;
            this.decrease = d;
        }

        @Override
        public int compareTo(City other) {
            return Integer.compare(other.activities, this.activities);  // note the order of the arguments!
        }
    }

    public static int calculateMaxActivities(int n, int m, int[] travelTimes, int[] initialActivities, int[] activityDecreases) {
        // 枚举最后停留的位置城市i
        int maxActivities = 0;
        for (int i = 1; i <= n; i++) {
            // 构建优先队列
            PriorityQueue<City> pq = new PriorityQueue<>();
            // 初始化队列，将每个城市的初始活动数量放入队列
            for (int j = 1; j <= i ; j++) {
                City city = new City(initialActivities[j], activityDecreases[j]);
                pq.offer(city);
            }
            // 计算剩余时间
            m = m - travelTimes[i - 1];
            int remainingTime = m;
            // 用优先队列维护前面i个城市可以停留一分钟可以体验的最多的旅行活动
            int curActivities = 0;
            while (!pq.isEmpty() && remainingTime > 0) {
                City city = pq.poll();
                // 每次从优先队列取出最大值，更新最大活动数量
                curActivities += city.activities;
                // 更新剩余时间
                remainingTime--;
                // 每次减去活动数量的减少值，再放回队列
                city.activities -= city.decrease;
                if (city.activities > 0) pq.offer(city);
            }
            maxActivities = Math.max(maxActivities, curActivities);
        }
        return maxActivities;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] travelTimes = new int[n+1];
        for (int i = 1; i < n; i++) {
            travelTimes[i] = sc.nextInt();
        }
        int[] initialActivities = new int[n+1];
        for (int i = 1; i <= n; i++) {
            initialActivities[i] = sc.nextInt();
        }
        int[] activityDecreases = new int[n+1];
        for (int i = 1; i <= n; i++) {
            activityDecreases[i] = sc.nextInt();
        }
        int maxActivities = calculateMaxActivities(n, m, travelTimes, initialActivities, activityDecreases);
        System.out.println(maxActivities);
    }
}
