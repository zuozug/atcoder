#include "bits/stdc++.h"
using namespace std;
#define int long long
map<int, int> f;
int find(int a) {
    if (f[a] == a)
        return a;
    return f[a] = find(f[a]);
}
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    int cnt = 0;
    vector<int> x(n), r(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> r[i];
        if (!f.contains(x[i] - r[i])) {
            f[x[i] - r[i]] = x[i] - r[i];
            cnt++;
        }
        if (!f.contains(x[i] + r[i])) {
            f[x[i] + r[i]] = x[i] + r[i];
            cnt++;
        }
        f[find(x[i] - r[i])] = find(f[x[i] + r[i]]);
        // for (auto i : f)
        // 	cout << i.first << " " << i.second << endl;
    }
    // for (auto i : f)
    // 	cout << i.first << " " << i.second << endl;
    for (auto i : f) {
        find(i.first);
    }

    map<int, int> fcnt;
    map<int, int> xrcnt;
    for (auto i : f)
        fcnt[i.second]++;
    for (int i = 0; i < n; i++)
        xrcnt[f[x[i] - r[i]]]++;
    int ans = 0;
    for (auto i : fcnt)
        ans += min(i.second, xrcnt[i.first]);
    cout << ans << endl;
    return 0;
}