#include "bits/stdc++.h"
using namespace std;
#define int long long
int MOD = 998244353;
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> move(3);
    for (int i = 0; i < 3; i++)
        cin >> move[i].first >> move[i].second;
    set<pair<int, int>> obs;
    map<pair<int, int>, int> dp;
    dp[{0, 0}] = 1;
    while (m--) {
        int x, y;
        cin >> x >> y;
        obs.insert({x, y});
    }
    for (int i = 0; i < n; i++) {
        map<pair<int, int>, int> temp;
        for (auto ii : dp) {
            for (int j = 0; j < 3; j++) {
                int x = ii.first.first + move[j].first, y = ii.first.second + move[j].second;
                if (obs.count({x, y}))
                    continue;
                temp[{x, y}] += ii.second;
                temp[{x, y}] %= MOD;
            }
        }
        swap(dp, temp);
    }
    int ans = 0;
    for (auto i : dp) {
        ans += i.second;
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}