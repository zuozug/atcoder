#include "bits/stdc++.h"
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s;
    cin >> s;
    int flag = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '#') {
            cout << "#";
            flag = 0;
        }
        else if (flag == 0) {
            cout << 'o';
            flag = 1;
        }
        else
            cout << '.';
    }
    cout << endl;
    return 0;
}