#include "bits/stdc++.h"
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m, a, b;
        cin >> n >> m >> a >> b;
        cout << m * a / __gcd(m, a) / a << endl;
        for (int i = 0; i < n; i++)
            cout << (a * i + b) % m << " ";
        cout << endl;
    }
    return 0;
}