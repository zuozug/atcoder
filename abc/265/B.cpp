#include "bits/stdc++.h"
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, t;
    cin >> n >> m >> t;
    vector<int> a(n);
    for (int i = 1; i < n; i++)
        cin >> a[i];
    map<int, int> bonus;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        bonus[x] = y;
    }
    int flag = 1;
    for (int i = 1; i <= n - 1; i++) {
        t -= a[i];
        if (t <= 0) {
            flag = 0;
            break;
        }
        if (bonus.count(i + 1))
            t += bonus[i + 1];
    }
    if (flag == 1)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}