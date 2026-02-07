#include "bits/stdc++.h"
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s;
    cin >> s;
    if (s[0] == s[1] && s[1] == s[2])
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}