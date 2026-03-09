#include "bits/stdc++.h"
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int h, w;
    cin >> h >> w;
    vector<string> g(h);
    for (int i = 0; i < h; i++)
        cin >> g[i];
    int x = 0, y = 0;
    set<pair<int, int>> used;
    int flag = 1;
    while (true) {
        if (used.count({x, y})) {
            flag = 0;
            break;
        }
        used.insert({x, y});
        if (g[x][y] == 'U') {
            if (x == 0)
                break;
            x--;
        }
        else if (g[x][y] == 'D') {
            if (x == h - 1)
                break;
            x++;
        }
        else if (g[x][y] == 'L') {
            if (y == 0)
                break;
            y--;
        }
        else {
            if (y == w - 1)
                break;
            y++;
        }
    }
    if (flag == 1)
        cout << x + 1 << " " << y + 1 << endl;
    else
        cout << -1 << endl;
    return 0;
}