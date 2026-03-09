#include "bits/stdc++.h"
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    int l, r;
    cin >> n >> l >> r;
    string s;
    cin >> s;
    int flag = 1;
    for (int i = l - 1; i < r; i++) {
        if (s[i] != 'o') {
            flag = 0;
            break;
        }
    }
    if (flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}