#include "bits/stdc++.h"
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int l = 0, r = 0;
    int sum = 0;
    set<int> num;
    while (r < n) {
        // for (auto i : num)
        //     cout << i << " ";
        // cout << endl;
        while (r < n) {
            // for (auto i : num)
            //     cout << i << " ";
            // cout << endl;
            int flag = 1;
            int temp = a[r];
            auto it = num.lower_bound(temp);
            if (num.count(temp))
                flag = 0;
            if (it != num.end() && *it < temp + d)
                flag = 0;
            if (it != num.begin()) {
                it--;
                if (*it > temp - d)
                    flag = 0;
            }
            if (flag == 0)
                break;
            num.insert(temp);
            r++;
        }
        r--;
        int len = r - l + 1;
        sum += (1 + len) * len / 2;
        // cout << l << " " << r << endl;
        if (r == n - 1)
            break;
        while (l <= r) {
            int temp = a[r + 1];
            int flag = 1;
            auto it = num.lower_bound(temp);
            if (num.count(temp))
                flag = 0;
            if (it != num.end() && *it < temp + d)
                flag = 0;
            if (it != num.begin()) {
                it--;
                if (*it > temp - d)
                    flag = 0;
            }
            if (flag == 1)
                break;
            num.erase(a[l]);
            l++;
        }
        r++;
        len = r - l;
        sum -= (1 + len) * len / 2;
        // cout << l << " " << r << endl;
    }
    cout << sum << endl;
    return 0;
}