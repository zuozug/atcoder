#include <bits/stdc++.h>
using namespace std;
#define int long long

struct Fenwick {
    int n;
    vector<int> tree;

    Fenwick(int n) : n(n), tree(n + 1, 0) {}

    void add(int i, int v = 1) {
        while (i <= n) {
            tree[i] += v;
            i += i & -i;
        }
    }

    int sum(int i) {
        int s = 0;
        while (i > 0) {
            s += tree[i];
            i -= i & -i;
        }
        return s;
    }

    void clear() {
        fill(tree.begin(), tree.end(), 0);
    }
};
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    Fenwick bit(n);
    vector<int> L(n + 1), R(n + 1);
    for (int i = 1; i <= n; i++) {
        L[i] = bit.sum(a[i] - 1);
        bit.add(a[i], 1);
    }
    bit.clear();
    for (int i = n; i >= 1; i--) {
        R[i] = bit.sum(a[i] - 1);
        bit.add(a[i], 1);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans += (L[i] + 1) * (R[i] + 1);
    cout << ans << endl;
    return 0;
}
