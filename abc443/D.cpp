#include "bits/stdc++.h"
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> r(n);
        for (int i = 0; i < n; i++)
            cin >> r[i];
        vector<int> lr(n), rl(n);
        lr[0] = r[0];
        for (int i = 0; i < n; i++) {
            if (r[i] < lr[i])
                lr[i] = r[i];
            if (i < n - 1)
                lr[i + 1] = lr[i] + 1;
        }
        rl[n - 1] = r[n - 1];
        for (int i = n -1; i >= 0; i--) {
            if (r[i] < rl[i])
                rl[i] = r[i];
            if (i > 0)
                rl[i - 1] = rl[i] + 1;
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
            ans += r[i] - min(rl[i], lr[i]);
        cout << ans << endl;
    }
    return 0;
}