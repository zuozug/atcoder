#include "bits/stdc++.h"
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    map<int, int> cnt, precnt;
    for (int i = 0; i < n; i++) {
        cnt[i + a[i]]++;
        precnt[i - a[i]]++;
    }
    int ans = 0;
    for (auto i : cnt) {
        if (i.first < 0 || i.second >= n)
            continue;
        if (precnt.count(i.first))
            ans += i.second * precnt[i.first];
    }
    cout << ans << endl;
    return 0;
}