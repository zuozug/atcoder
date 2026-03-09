#include "bits/stdc++.h"
using namespace std;
#define int long long
int ee18 = 1e18;
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> len(n + 1, vector<int>(n + 1, ee18));
    for (int i = 0; i <= n; i++)
        len[i][i] = 0;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        len[a - 1][b - 1] = min(len[a - 1][b - 1], c * 2);
        len[b - 1][a - 1] = min(len[b - 1][a - 1], c * 2);
    }
    int k, t;
    cin >> k >> t;
    for (int i = 0 ; i < k; i++) {
        int d;
        cin >> d;
        len[d - 1][n] = min(len[d - 1][n], t);
        len[n][d - 1] = min(len[n][d - 1], t);
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            for (int ij = 0; ij <= n; ij++)
                len[i][j] = min(len[i][j], len[i][ij] + len[ij][j]);
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x, y, tt;
            cin >> x >> y >> tt;
            for (int i = 0; i <= n; i++) {
                for (int j = 0; j <= n; j++)
                    len[i][j] = min({len[i][j], len[i][x - 1] + tt * 2 + len[y - 1][j], len[i][y - 1] + tt * 2 + len[x - 1][j]});
            }
        }
        else if (op == 2) {
            int x;
            cin >> x;
            for (int i = 0; i <= n; i++) {
                for (int j = 0; j <= n; j++)
                    len[i][j] = min({len[i][j], len[i][x - 1] + t + len[n][j], len[i][n] + t + len[x - 1][j]});
            }
        }
        else {
            int ans = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (len[i][j] != ee18)
                        ans += len[i][j];
                }
            }
            cout << ans / 2 << endl;
        }
    }
    return 0;
}