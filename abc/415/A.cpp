#include "bits/stdc++.h"
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    set<int> s;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        s.insert(num);
    }
    int x;
    cin >> x;
    if (s.count(x))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}