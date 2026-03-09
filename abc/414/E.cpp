#include "bits/stdc++.h"
using namespace std;
#define int long long
int MOD = 998244353;
int qpow(int a, int b) {
    int res = 1;
    while (b != 0) {
        if (b % 2 == 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b /= 2;
    }
    return res;
}
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    int ans = (1 + n - 2) % MOD * ((n - 2) % MOD) % MOD * qpow(2, MOD - 2) % MOD;
    int l, r;
    for (int i = 2; ; i++) {
        if (n * (i - 1) % i == 0)
            l = n * (i - 1) / i;
        else
            l = n * (i - 1) / i + 1;
        if (n * i % (i + 1) == 0)
            r = n * i / (i + 1) - 1;
        else
            r = n * i / (i + 1);
        if (r < l)
            break;
        ans -= (r - l + 1) % MOD * (i - 1) % MOD;
        ans = (ans % MOD + MOD) % MOD;
    }
    for (int i = l; i <= n - 2; i++) {
        ans -= i / (n - i) % MOD;
        ans = (ans % MOD + MOD) % MOD;
    }
    cout << ans << endl;
    return 0;
}