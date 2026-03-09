#include "bits/stdc++.h"
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int a, b, k;
    cin >> a >> b >> k;
    int cnt = 0;
    while (a < b) {
        a *= k;
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}