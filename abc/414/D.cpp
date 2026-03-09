#include "bits/stdc++.h"
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> x(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];
    sort(x.begin(), x.end());
    vector<int> xx(n - 1);
    for (int i = 0; i < n - 1; i++)
        xx[i] = x[i + 1] - x[i];
    sort(xx.begin(), xx.end());
    int ans = 0;
    for (int i = 0; i < n - m; i++)
        ans += xx[i];
    cout << ans << endl;
    return 0;
}