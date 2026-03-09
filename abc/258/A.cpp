#include "bits/stdc++.h"
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int k;
    cin >> k;
    if (k == 0)
        cout << "21:00" << endl;
    else if (k < 10)
        cout << "21:0" << k << endl;
    else if (k < 60)
        cout << "21:" << k << endl;
    else if (k == 60)
        cout << "22:00" << endl;
    else if (k < 70)
        cout << "22:0" << k - 60 << endl;
    else
        cout << "22:" << k - 60 << endl;
    return 0;
}