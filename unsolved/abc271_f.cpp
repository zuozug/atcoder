#include "bits/stdc++.h"
using namespace std;
#define int long long
int n;
vector<vector<int>> a;
int solve(int i, int j, int num) {
    if (i == 0 && j == 0 && num == a[0][0])
        return 1;
    int res = 0;
    if (i > 0)
        res += solve(i - 1, j, num ^ a[i][j]);
    if (j > 0)
        res += solve(i, j - 1, num ^ a[i][j]);
    return res;
}
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    a.resize(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    }
    cout << solve(n - 1, n - 1, 0) << endl;
    return 0;
}