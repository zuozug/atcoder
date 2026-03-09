#include "bits/stdc++.h"
using namespace std;
#define int long long
int Mod = 998244353;
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> dp(n, vector<int>(k + 1, 0));
    for (int i = 1; i <= min(k ,m); i++)
        dp[0][i] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            for (int ii = max(0ll, j - m); ii < j; ii++) {
                dp[i][j] += dp[i - 1][ii];
                dp[i][j] %= Mod;
            }
        }
    }
    int sum = 0;
    for (auto i : dp[n - 1]) {
        sum += i;
        sum %= Mod;
    }
    cout << sum << endl;
    return 0;
}