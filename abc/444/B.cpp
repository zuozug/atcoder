#include "bits/stdc++.h"
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        int temp = i;
        int sum = 0;
        while (temp) {
            sum += temp % 10;
            temp /= 10;
        }
        if (sum == k)
            cnt++;
    }
    cout << cnt << endl;
    return 0;
}