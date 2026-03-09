#include "bits/stdc++.h"
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    int p = 0;
    while (q--) {
        int op, x;
        cin >> op >> x;
        if (op == 1) {
            p -= x;
            p = (p % n + n) % n;
        }
        else
            cout << s[((p + x - 1) % n + n) % n] << endl;
    }
    return 0;
}