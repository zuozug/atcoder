#include "bits/stdc++.h"
using namespace std;
#define int long long
vector<int> mx = {0, 0, -1, 1, 1, 1, -1, -1};
vector<int> my = {1, -1, 0, 0, 1, -1, -1, 1};
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    string ans = a[0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int mv = 0; mv < 8; mv++) {
                string temp;
                int x = i, y = j;
                for (int t = 0; t < n; t++) {
                    temp.push_back(a[x][y]);
                    x += mx[mv];
                    y += my[mv];
                    x = (x % n + n) % n;
                    y = (y % n + n) % n;
                }
                // cout << temp << endl;
                ans = max(ans, temp);
            }
        }
    }
    cout << ans << endl;
    return 0;
}