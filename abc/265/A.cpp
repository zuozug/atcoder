#include "bits/stdc++.h"
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int x, y, n;
    cin >> x >> y >> n;
    if (3 * x <= y)
        cout << n * x << endl;
    else
        cout << n / 3 * y + n % 3 * x << endl;
    return 0;
}