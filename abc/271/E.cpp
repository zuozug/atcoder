#include "bits/stdc++.h"
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(m), b(m), c(m);
    map<int, int> len;
    len[1] = 0;
    for (int i = 0; i < m; i++)
        cin >> a[i] >> b[i] >> c[i];
    for (int i = 0; i < k; i++) {
        int num;
        cin >> num;
        if (len.count(a[num - 1]) == 0)
            continue;
        if (len.count(b[num - 1]) == 0)
            len[b[num - 1]] = len[a[num - 1]] + c[num - 1];
        else
            len[b[num - 1]] = min(len[b[num - 1]], len[a[num - 1]] + c[num - 1]);
    }
    if (len.count(n) == 0)
        cout << -1 << endl;
    else
        cout << len[n] << endl;
    return 0;
}