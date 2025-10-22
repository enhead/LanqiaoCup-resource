import sys

sys.setrecursionlimit(10**6)

n, root = 0, 0
N = 1000006
a, b, L, R = [0] * N, [0] * N, [0] * N, [0] * N
sum = [0] * N
S = []
ans = 0

def dfs(x):
    if x == 0:
        return
    dfs(L[x])
    dfs(R[x])
    sum[x] = sum[L[x]] + sum[R[x]] + b[x]

n = int(input())
for i in range(1, n+1):
    a[i], b[i] = map(int, input().split())

for i in range(1, n+1):
    while len(S) > 0 and a[S[-1]] > a[i]:
        L[i] = S[-1]
        S.pop()
    if len(S) > 0:
        R[S[-1]] = i
    S.append(i)

while len(S) > 0:
    root = S[-1]
    S.pop()

dfs(root)

for i in range(1, n+1):
    ans = max(ans, min(a[i], sum[i]) * min(a[i], sum[i]))

print(ans)
