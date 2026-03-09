#include "bits/stdc++.h"
using namespace std;
#define int long long
int n;
vector<int> p, a, b;
map<pair<int, int>, int> mem;
int solve(int pos, int num) {
    if (mem.count({pos, num}))
        return mem[{pos, num}];
    if (pos == n)
        return mem[{pos, num}] = num;
    if (num <= p[pos])
        return mem[{pos, num}] = solve(pos + 1, num + a[pos]);
    else
        return mem[{pos, num}] = solve(pos + 1, max(0ll, num - b[pos]));
}
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    p.resize(n);
    a.resize(n);
    b.resize(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> p[i] >> a[i] >> b[i];
        sum += b[i];
    }
    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        if (x > n * 500)
            cout << x - sum << endl;
        else
            cout << solve(0, x) << endl;
    }
    return 0;
}