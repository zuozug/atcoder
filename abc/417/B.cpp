#include "bits/stdc++.h"
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    multiset<int> ms;
    while (n--) {
        int num;
        cin >> num;
        ms.insert(num);
    }
    while (m--) {
        int num;
        cin >> num;
        if (ms.count(num))
            ms.erase(ms.find(num));
    }
    for (auto i : ms)
        cout << i << " ";
    cout << endl;
    return 0;
}