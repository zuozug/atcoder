#include "bits/stdc++.h"
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    string s;
    cin >> n;
    int a, b;
    cin >> a >> b;
    cin >> s;
    for (int i = a; i < n - b; i++)
        cout << s[i];
    cout << endl;
    return 0;
}