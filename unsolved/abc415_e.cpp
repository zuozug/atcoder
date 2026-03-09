#include "bits/stdc++.h"
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int h, w;
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w, 0));
    vector<int> p(h + w - 1);
    for (int i = 0; i < h; i ++) {
        for (int j = 0; j < w; j++)
            cin >> a[i][j];
    }
    for (int i = 0; i < h + w - 1; i++)
        cin >> p[i];
    int l = 0, r = 1e18;
    while (l < r) {
        int mid = (l + r) >> 1;
        vector<vector<int>> dp(h, vector<int>(w, 0));
        dp[0][0] = mid + a[0][0] - p[0];
        for (int i = 1; i < w; i++)
            dp[0][i] = dp[0][i - 1] + a[0][i] - p[i];
        for (int i = 1; i < h; i++)
            dp[i][0] = dp[i - 1][0] + a[i][0] - p[i];
        for (int i = 1; i < h; i++) {
            for (int j = 1; j < w; j++)
                dp[i][j] = max(dp[i - 1][j], dp[i][j  - 1]) + a[i][j] - p[i + j];
        }
        int flag = 1;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (dp[i][j] < 0) {
                    flag = 0;
                    break;
                }
            }
        }
        if (flag == 1)
            r = mid;
        else
            l = mid  + 1;
    }
    cout << l << endl;
    return 0;
}