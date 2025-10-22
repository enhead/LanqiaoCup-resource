n = int(input())
a = []
for i in range(n):
    ai = list(map(int, input().split()))
    a.append(ai)

ans = -1
for j in range(3):
    dp = [[[0 for k in range(2)] for j in range(3)] for i in range(n)]
    for i in range(3):
        dp[0][i][0] = dp[0][i][1] = a[0][i] if i == j else 0
    for i in range(1, n):
        dp[i][0][0] = max(dp[i-1][1][1], dp[i-1][2][1]) + a[i][0]
        dp[i][1][0] = dp[i-1][2][1] + a[i][1]
        dp[i][1][1] = dp[i-1][0][0] + a[i][1]
        dp[i][2][1] = max(dp[i-1][1][0], dp[i-1][0][0]) + a[i][2]
    for i in range(j):
        ans = max(ans, dp[n-1][i][0])
    for i in range(2, j, -1):
        ans = max(ans, dp[n-1][i][1])

print(ans)