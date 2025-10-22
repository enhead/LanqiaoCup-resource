#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int main()
{
    int n;
    cin >> n;
    int a = 1, b = 1;
    for (int i = 1; i <= n; ++i)
    {
        int t = a;
        a = b;
        b = (t + b) % MOD;
    }
    cout << 1ll * b * b % 1000000007 << endl;
    return 0;
}