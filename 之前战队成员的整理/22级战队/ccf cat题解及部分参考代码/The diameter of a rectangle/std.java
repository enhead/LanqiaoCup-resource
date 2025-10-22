import java.util.Scanner;
import java.util.Stack;

public class Main {

    static int n, root;
    static int[] a, b, L, R;
    static long[] sum;
    static Stack<Integer> S;
    static long ans;

    public static void dfs(int x) {
        if (x == 0) return;
        dfs(L[x]);
        dfs(R[x]);
        sum[x] = sum[L[x]] + sum[R[x]] + (long) b[x];
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        a = new int[n + 1];
        b = new int[n + 1];
        L = new int[n + 1];
        R = new int[n + 1];
        sum = new long[n + 1];
        S = new Stack<>();
        ans = 0;

        for (int i = 1; i <= n; i++) {
            a[i] = scanner.nextInt();
            b[i] = scanner.nextInt();
        }

        for (int i = 1; i <= n; i++) {
            while (!S.empty() && a[S.peek()] > a[i]) {
                L[i] = S.peek();
                S.pop();
            }
            if (!S.empty()) R[S.peek()] = i;
            S.push(i);
        }

        while (!S.empty()) {
            root = S.peek();
            S.pop();
        }

        dfs(root);

        for (int i = 1; i <= n; i++) {
            ans = Math.max(ans, Math.min((long) a[i], sum[i]) * Math.min((long) a[i], sum[i]));
        }

        System.out.println(ans);
    }

}