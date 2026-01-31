#include "bits/stdc++.h"
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, c;
        cin >> n >> c;
        vector<string> s(n);
        vector<string> reach(n);
        for (int i = 0; i < n; i++)
            cin >> s[i];
        vector<int> des(n, 1);
        for (int i = 0; i < n; i++) {
            if (s[n - 1][i] == '#')
                des[i] = 0;
            reach[n - 1].push_back('0');
        }
        // for (auto i : des)
        //     cout << i << " ";
        // cout << endl;
        reach[n - 1][c - 1] = '1';
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                if (reach[i + 1][j] == '1' || (j > 0 && reach[i + 1][j - 1] == '1') || (j < n - 1 && reach[i + 1][j + 1] == '1')) {
                    if (s[i][j] == '.')
                        reach[i].push_back('1');
                    else {
                        if (des[j] == 1)
                            reach[i].push_back('1');
                        else
                            reach[i].push_back('0');
                    }
                }
                else {
                    reach[i].push_back('0');
                    if (s[i][j] == '#')
                        des[j] = 0;
                }
            }
            // for (auto ii : des)
            //     cout << ii << " ";
            // cout << endl;
        }
        // for (auto i : reach)
        //     cout << i << endl;
        // for (auto i : des)
        //     cout << i << " ";
        // cout << endl;
        cout << reach[0] << endl;
    }
    return 0;
}