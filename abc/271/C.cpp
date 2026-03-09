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
    int l = 0, r = 1e9;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        set<int> s;
        int cntl = 0, cntr = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] <= mid)
                s.insert(a[i]);
        }
        cntr = n - s.size();
        cntl = mid - s.size();
        if (cntr / 2 >= cntl)
            l = mid;
        else
            r = mid - 1;
    }
    cout << l << endl;
    return 0;
}