#include "bits/stdc++.h"
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> pre(2002, vector<int>(2002, 0));
    vector<int> u(n), d(n), l(n), r(n);
    for (int i = 0; i < n; i++) {
        cin >> u[i] >> d[i] >> l[i] >> r[i];
        pre[u[i]][l[i]]++;
        pre[u[i]][r[i] + 1]--;
        pre[d[i] + 1][l[i]]--;
    }
    for (int i = 0; i < 2001; i++) {
        for (int j = 1; j < 2001; j++)
            pre[i][j] += pre[i][j - 1];
    }
    for (int i = 1; i < 2001; i++) {
        for (int j = 0; j < 2001; j++)
            pre[i][j] += pre[i - 1][j];
    }
    vector<vector<int>> prepre(2002, vector<int>(2002, 0));
    for (int i = 0; i < 2001; i++) {
        for (int j = 0; j < 2001; j++) {
            if (pre[i][j] == 1) {
                prepre[i][j]++;
                prepre[i][j + 1]--;
                prepre[i + 1][j]--;
            }
        }
    }
    int sum = 2000 * 2000;
    for (int i = 0; i < 2001; i++) {
        for (int j = 0; j < 2001; j++) {
            if (pre[i][j] > 0)
                sum--;
        }
    }
    for (int i = 0; i < 2002; i++) {
        for (int j = 1; j < 2002; j++)
            prepre[i][j] += prepre[i][j - 1];
    }
    for (int i = 1; i < 2002; i++) {
        for (int j = 0; j < 2002; j++)
            prepre[i][j] += prepre[i - 1][j];
    }

    for (int i = 0; i < n; i++) {
        cout << sum + (prepre[d[i]][r[i]] - prepre[u[i] - 1][r[i]] - prepre[d[i]][l[i] - 1] + prepre[u[i] - 1][l[i]] - 1) << endl;
    }
    return 0;
}