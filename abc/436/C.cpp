#include "bits/stdc++.h"
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    set<pair<int, int>> used;
    while (m--) {
        int r, c;
        cin >> r >> c;
        if (used.count({r, c}) + used.count({r + 1, c}) + used.count({r, c + 1}) + used.count({r + 1, c + 1}) == 0) {
            used.insert({r, c});
            used.insert({r + 1, c});
            used.insert({r, c + 1});
            used.insert({r + 1, c + 1});
        }
    }
    cout << used.size() / 4 << endl;
    return 0;
}