#include <stdio.h>
#define MOD 1000000007

int main() {
    int n;
    scanf("%d", &n);
    int a = 1, b = 1;
    for (int i = 1; i <= n; i++) {
        int t = a;
        a = b;
        b = (t + b) % MOD;
    }
    printf("%lld\n", (long long)b * b % MOD);
    return 0;
}