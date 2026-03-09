#include "bits/stdc++.h"
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    string s;
    cin >> n >> s;
    map<int, pair<int, int>> w;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if (s[i] == '0')
            w[num] = {w[num].first + 1, w[num].second};
        else
            w[num] = {w[num].first, w[num].second + 1};
    }
    // for (auto i : w)
    //     cout << i.first << " " << i.second.first << " " << i.second.second << endl;
    vector<int> pre(w.size() + 1, 0), rev(w.size() + 1, 0);
    int p = 1;
    for (auto i : w) {
        pre[p] = pre[p - 1] + i.second.first;
        p++;
    }
    p = w.size() - 1;
    for (auto it = w.rbegin(); it != w.rend(); it++) {
        rev[p] = rev[p + 1] + it->second.second;
        p--;
    }
    // for (auto i : pre)
    //     cout << i << " ";
    // cout << endl;
    // for (auto i : rev)
    //     cout << i << " ";
    // cout << endl;
    int ans = 0;
    for (int i = 0; i <= w.size(); i++)
        ans = max(ans, pre[i] + rev[i]);
    cout << ans << endl;
    return 0;
}