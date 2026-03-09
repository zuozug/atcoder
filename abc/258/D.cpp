#include "bits/stdc++.h"
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, x;
    cin >> n >> x;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    int ans = 5e18;
    int minb = 5e18;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (i >= x)
            break;
        sum += a[i] + b[i];
        minb = min(minb, b[i]);
        int temp = sum;
        temp += (x - i - 1) * minb;
        // cout << temp << " ";
        ans = min(ans, temp);
    }
    cout << ans << endl;
    return 0;
}