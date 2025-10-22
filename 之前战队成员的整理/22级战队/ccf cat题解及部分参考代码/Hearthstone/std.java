import java.util.Scanner;

public class std {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] a = new int[n+1][3];
        for (int i = 1; i <= n; i++) {
            a[i][0] = sc.nextInt();
            a[i][1] = sc.nextInt();
            a[i][2] = sc.nextInt();
        }
        int ans = -1;
        for (int j = 0; j < 3; j++) {
            int[][][] dp = new int[n+1][3][2];
            for (int i = 0; i < 3; i++) {
                dp[1][i][0] = dp[1][i][1] = (i==j)?a[1][j]:0;
            }
            for (int i = 2; i <= n; i++) {
                dp[i][0][0] = Math.max(dp[i-1][1][1], dp[i-1][2][1]) + a[i][0];
                dp[i][1][0] = dp[i-1][2][1] + a[i][1];
                dp[i][1][1] = dp[i-1][0][0] + a[i][1];
                dp[i][2][1] = Math.max(dp[i-1][1][0], dp[i-1][0][0]) + a[i][2];
            }
            for (int i = 0; i < j; i++) {
                ans = Math.max(ans, dp[n][i][0]);
            }
            for (int i = 2; i > j; i--) {
                ans = Math.max(ans, dp[n][i][1]);
            }
        }
        System.out.println(ans);
    }
}