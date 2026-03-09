#include "bits/stdc++.h"
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (x[i] <= l && y[i] >= r)
            cnt++;
    }
    cout << cnt << endl;
    return 0;
}