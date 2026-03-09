#include "bits/stdc++.h"
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> len(n, vector<int>(n, 1e18));
    vector<array<int, 3>> arr(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++)
            cin >> arr[i][j];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                len[i][j] = 0;
            else
                len[i][j] = (abs(arr[i][0] - arr[j][0]) + abs(arr[i][1] - arr[j][1]) - 1) / arr[i][2] + 1;
        }
    }
    // for (auto i : len) {
    //     for (auto j : i)
    //         cout << j << " ";
    //     cout << endl;
    // }
    // cout << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                len[i][j] = min(len[i][j], max(len[i][k], len[k][j]));
            }
        }
    }
    // for (auto i : len) {
    //     for (auto j : i)
    //         cout << j << " ";
    //     cout << endl;
    // }
    int ans = 5e18;
    for (auto i : len) {
        int temp = 0;
        for (auto  j : i)
            temp = max(temp, j);
        ans = min(ans, temp);
    }
    cout << ans << endl;
    return 0;
}