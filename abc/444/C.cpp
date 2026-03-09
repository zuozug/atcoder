#include "bits/stdc++.h"
using namespace std;
#define int long long
set<int> number;
void solve(int num, map<int, int> cnt) {
    for (auto i : number) {
        if (i == num)
            cnt.erase(i);
        else {
            if (i * 2 == num) {
                if (cnt[i] % 2 == 0)
                    cnt.erase(i);
                else
                    break;
            }
            else {
                if (cnt[i] == cnt[num - i]) {
                    cnt.erase(i);
                    cnt.erase(num - i);
                }
                else
                    break;
            }
        }
    }
    if (cnt.empty())
        cout << num << " ";
}
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    map<int, int> cnt;
    for (auto i : a) {
        cnt[i]++;
        number.insert(i);
    }
    solve(cnt.rbegin()->first, cnt);
    solve(cnt.rbegin()->first + cnt.begin()->first, cnt);
    cout << endl;
    return 0;
}