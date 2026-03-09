#include "bits/stdc++.h"
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> ans(n, vector<int>(n, 0));
    ans[0][(n - 1) / 2] = 1;
    int r = 0, c = (n - 1) / 2;
    for (int i = 2; i <= n * n; i++) {
        if (ans[(r - 1 + n) % n][(c + 1) % n] == 0) {
            r = (r - 1 + n) % n;
            c = (c + 1) % n;
        }
        else {
            r = (r + 1) % n;
        }
        ans[r][c] = i;
    }
    for (auto i : ans) {
        for (auto j : i)
            cout << j << " ";
        cout<< endl;
    }
    return 0;
}