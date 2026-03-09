#include "bits/stdc++.h"
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, h;
        cin >> n >> h;
        int maxh = h, minh = h;
        int flag = 1;
        int time = 0;
        while (n--) {
            int t, l, u;
            cin >> t >> l >> u;
            maxh += t - time;
            minh = max(minh - t + time, (int)1);
            if (l > maxh || u < minh)
                flag = 0;
            time = t;
            minh = max(minh, l);
            maxh = min(maxh, u);
        }
        if (flag == 1)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}