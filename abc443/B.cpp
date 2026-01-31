#include "bits/stdc++.h"
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    int l = 0, r = 1e9;
    while (l < r) {
        int mid = (l + r) / 2;
        int temp = (n + n + mid) * (mid + 1) / 2;
        if (temp >= k)
            r = mid;
        else
            l = mid + 1;
    }
    cout << l << endl;
    return 0;
}