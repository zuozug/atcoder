#include "bits/stdc++.h"
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<char> c(n);
    vector<int> l(n);
    for (int i = 0; i < n; i++)
        cin >> c[i] >> l[i];
    int sum = 0;
    int flag = 1;
    for (auto i : l) {
        sum += i;
        if (sum > 100) {
            flag = 0;
            break;
        }
    }
    if (flag == 0)
        cout << "Too Long" << endl;
    else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < l[i]; j++)
                cout << c[i];
        }
        cout << endl;
    }
    return 0;
}