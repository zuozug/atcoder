#include "bits/stdc++.h"
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        multiset<int> a, b;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            a.insert(num);
            ans += num;
        }
        for (int i = 0 ; i < n; i++) {
            int num;
            cin >> num;
            b.insert(num);
            ans += num;
        }
        for (auto i : a) {
            auto temp = b.lower_bound(m - i);
            if (temp == b.end()) {
                continue;
            }
            b.erase(temp);
            ans -= m;
        }
        cout << ans << endl;
    }
    return 0;
}