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
    vector<int> pre(1000000, 0);
    for (auto i : a) {
        pre[0]++;
        pre[i]--;
    }
    for (int i = 1; i < 1000000; i++)
        pre[i] += pre[i - 1];
    for (int i = 0; i < 999999; i++) {
        pre[i + 1] += pre[i] / 10;
        pre[i] %= 10;
    }
    reverse(pre.begin(), pre.end());
    int p = 0;
    while (pre[p] == 0)
        p++;
    for (int i = p; i < 1000000; i++)
        cout << pre[i];
    cout << endl;
    return 0;
}