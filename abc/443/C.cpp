#include "bits/stdc++.h"
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, t;
    cin >> n >> t;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int opentime = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (opentime < a[i]) {
            ans += a[i] - opentime;
            opentime = a[i] + 100;
        }
    }
    if (t > opentime)
        ans += t - opentime;
    cout << ans << endl;
    return 0;
}