#include <stdio.h>
#define max(a, b) ((a) > (b) ? (a) : (b))

int dp[100010][3][2], n, a[100010][3], ans;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);
    }

    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < 3; i++) {
            for (int k = 0; k < 2; k++) {
                dp[0][i][k] = 0;
            }
            dp[1][i][0] = dp[1][i][1] = (i == j) ? a[1][j] : 0;
        }
        for (int i = 2; i <= n; i++) {
            dp[i][0][0] = max(dp[i-1][1][1], dp[i-1][2][1]) + a[i][0];
            dp[i][1][0] = dp[i-1][2][1] + a[i][1];
            dp[i][1][1] = dp[i-1][0][0] + a[i][1];
            dp[i][2][1] = max(dp[i-1][1][0], dp[i-1][0][0]) + a[i][2];
        }
        for (int i = 0; i < j; i++) {
            ans = max(ans, dp[n][i][0]);
        }
        for (int i = 2; i > j; i--) {
            ans = max(ans, dp[n][i][1]);
        }
    }

    printf("%d", ans);
    return 0;
}