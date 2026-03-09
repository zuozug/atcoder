#include "bits/stdc++.h"
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    int x;
    cin >> n >> x;
    char c = 'A' + (x - 1) / n;
    cout << c << endl;
    return 0;
}