#include "bits/stdc++.h"
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> p(n);
    vector<int> used(n, 0);
    vector<int> huan;
    for (int i = 0; i < n; i++)
        cin >> p[i];
    for (int i = 0; i < n; i++) {
        if (used[i] == 1)
            continue;
        int ii = i;
        if (ii == p[i] - 1)
            used[i] = 1;
        else {
            int cnt = 0;
            while (used[ii] == 0) {
                used[ii] = 1;
                ii = p[ii] - 1;
                cnt++;
            }
            huan.push_back(cnt);
        }
    }
    // for (auto i : huan)
    // 	cout << i << " ";
    int ans = 0;
    for (auto i : huan)
        ans += i * (i - 1) / 2;
    cout << ans << endl;
    return 0;
}