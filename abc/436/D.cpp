#include "bits/stdc++.h"
using namespace std;
#define int long long
vector<int> mx = {1, -1, 0, 0};
vector<int> my = {0, 0, 1, -1};
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    vector<vector<int>> len(h, vector<int>(w, -1));
    vector<vector<pair<int, int>>> tel(26);
    for (int i = 0; i < h; i++)
        cin >> s[i];
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (s[i][j] >= 'a' && s[i][j] <= 'z')
                tel[s[i][j] - 'a'].push_back({i, j});
        }
    }
    queue<pair<int, int>> q;
    q.push({0, 0});
    len[0][0] = 0;
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        if (s[x][y] >= 'a' && s[x][y] <= 'z') {
            for (auto j : tel[s[x][y] - 'a']) {
                if (len[j.first][j.second] != -1)
                    continue;
                len[j.first][j.second] = len[x][y] + 1;
                q.push(j);
            }
            tel[s[x][y] - 'a'].clear();
        }
        for (int i = 0; i < 4; i++) {
            if (x + mx[i] >= 0 && x + mx[i] < h && y + my[i] >= 0 && y + my[i] < w) {
                int xx = x + mx[i], yy = y + my[i];
                if (s[xx][yy] == '#' || len[xx][yy] != -1)
                    continue;
                len[xx][yy] = len[x][y] + 1;
                q.push({xx, yy});
            }
        }
    }
    // for (auto i : len) {
    // 	for (auto j : i)
    // 		cout << j;
    // 	cout << endl;
    // }
    cout << len[h - 1][w - 1] << endl;
    return 0;
}