#include "bits/stdc++.h"
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m, x, y;
        cin >> n >> m >> x >> y;
        vector<vector<int>> node(n, vector<int>(n, -1));
        while (m--) {
            int u, v;
            cin >> u >> v;
            node[u - 1][v - 1] = v - 1;
            node[v - 1][u - 1] = u - 1;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (node[i][k] == -1 || node[k][j] == -1)
                        continue;
                    if (node[i][k] < node[i][j])
                        node[i][j] = node[i][k];
                }
            }
        }
        int px = x - 1, py = y - 1;
        while (node[px][py] != y - 1) {
            cout << node[px][py] + 1 << " ";
            px = node[px][py];
        }
        cout << y << endl;
    }
    return 0;
}