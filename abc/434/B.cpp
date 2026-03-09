#include "bits/stdc++.h"
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    map<int, double> sum, cnt;
    while (n--) {
        int a, b;
        cin >> a >> b;
        sum[a] += b;
        cnt[a]++;
    }
    for (int i = 1; i <= m; i++)
        cout << fixed << setprecision(9) << sum[i] / cnt[i] << endl;
    return 0;
}