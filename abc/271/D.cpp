#include "bits/stdc++.h"
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, s;
    cin >> n >> s;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    vector<set<int>> h(n), t(n);
    h[0].insert(a[0]);
    t[0].insert(b[0]);
    for (int i = 1; i < n; i++) {
        for (auto j : h[i - 1]) {
            h[i].insert(j + a[i]);
            t[i].insert(j + b[i]);
        }
        for (auto j : t[i - 1]) {
            h[i].insert(j + a[i]);
            t[i].insert(j + b[i]);
        }
    }
    int flag = 1;
    stack<int> ans;
    for (int i = n - 1; i >= 0; i--) {
        if (h[i].count(s)) {
            ans.push(0);
            s -= a[i];
        }
        else if (t[i].count(s)) {
            ans.push(1);
            s -= b[i];
        }
        else {
            flag = 0;
            break;
        }
    }
    if (flag == 0)
        cout << "No" << endl;
    else {
        cout << "Yes" << endl;
        while (!ans.empty()) {
            if (ans.top() == 0)
                cout << 'H';
            else
                cout << 'T';
            ans.pop();
        }
    }
    return 0;
}