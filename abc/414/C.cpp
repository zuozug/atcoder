#include "bits/stdc++.h"
using namespace std;
#define int long long
bool check(int num, int a) {
    string s;
    while (num != 0) {
        s.push_back('0' + num % a);
        num /= a;
    }
    int flag = 1;
    for (int i = 0; i < s.size() / 2; i++) {
        if (s[i] != s[s.size() - i - 1]) {
            flag = 0;
            break;
        }
    }
    if (flag == 0)
        return false;
    return true;
}
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int a, n;
    cin >> a >> n;
    set<int> s;
    for (int i = 0; i <= 999999; i++) {
        int num = 0, ii = i;
        int temp = i;
        while (ii != 0) {
            num *= 10;
            num += ii % 10;
            ii /= 10;
            temp *= 10;
        }
        temp += num;
        if (temp > n)
            break;
        if (check(temp, a))
            s.insert(temp);
    }
    // cout << 1 << endl;
    for (int i = 0; i <= 999999; i++) {
        int num = 0, ii = i;
        int temp = i / 10;
        while (ii != 0) {
            num *= 10;
            num += ii % 10;
            ii /= 10;
            temp *= 10;
        }
        temp += num;
        // cout << temp << endl;
        if (temp > n)
            break;
        if (check(temp, a))
            s.insert(temp);
    }
    int ans = 0;
    for (auto i : s)
        ans += i;
    cout << ans << endl;
    return 0;
}