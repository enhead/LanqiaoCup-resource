import java.util.*;
import java.io.*;

public class Main {
    public static final int MAXN = (int) 1e3 + 5;
    public static final long INF = (long) 1e18;

    public static List<List<int[]>> adj = new ArrayList<>();
    public static List<List<int[]>> graph = new ArrayList<>();
    public static long[] dis = new long[MAXN];
    public static boolean[] vis = new boolean[MAXN];

    public static void dijkstra(int s) {
        PriorityQueue<long[]> pq = new PriorityQueue<>(Comparator.comparingLong(o -> o[0]));

        Arrays.fill(dis, INF);
        Arrays.fill(vis, false);
        dis[s] = 0;
        pq.add(new long[]{0, s});
        while (!pq.isEmpty()) {
            int u = (int) pq.poll()[1];
            if (vis[u]) continue;
            vis[u] = true;
            for (int[] edge : graph.get(u)) {
                int v = edge[0], w = edge[1];
                long newDis = dis[u] + w;
                if (newDis < dis[v]) {
                    dis[v] = newDis;
                    pq.add(new long[]{dis[v], v});
                }
            }
        }
    }

    public static void addNewEdge(int n) {
        for (int i = 1; i <= n; i++) {
            for (int[] next : adj.get(i)) {
                for (int[] nextNext : adj.get(next[0])) {
                    int v = nextNext[0];
                    int len1 = next[1], len2 = nextNext[1];
                    if (len2 % len1 == 0 && i != v) {
                        graph.get(i).add(new int[]{v, len2});
                    }
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        for (int i = 0; i <= MAXN; i++) {
            adj.add(new ArrayList<>());
            graph.add(new ArrayList<>());
        }

        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        int m = scanner.nextInt();
        for (int i = 0; i < m; ++i) {
            int u = scanner.nextInt();
            int v = scanner.nextInt();
            int w = scanner.nextInt();
            graph.get(u).add(new int[]{v, w});
            adj.get(u).add(new int[]{v, w});
            graph.get(v).add(new int[]{u, w});
            adj.get(v).add(new int[]{u, w});
        }

        addNewEdge(n);

        dijkstra(1);

        for (int i = 1; i <= n; ++i) {
            if (dis[i] >= INF) dis[i] = -1;
            System.out.print(dis[i]);
            if (i < n) System.out.print(" ");
            else System.out.print("\n");
        }

    }
}
