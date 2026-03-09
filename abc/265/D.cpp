#include "bits/stdc++.h"
using namespace std;
#define int long long
int n, p[3];
vector<int> a;
int flag = 0;
int fun(int l, int r, int num) {
    if (l > r)
        return -1;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (a[mid] > num)
            r = mid - 1;
        else
            l = mid;
    }
    if (a[l] == num)
        return l;
    return -1;
}
void dfs(int l, int num) {
    // cout << l << " " << num << endl;
    if (flag == 1)
        return;
    if (num == 3) {
        flag = 1;
        return;
    }
    int pp = p[num] + a[l - 1];
    int temp = fun(l, n, pp);
    if (temp == -1)
        return;
    else
        dfs(temp + 1, num + 1);
}
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> p[0] >> p[1] >> p[2];
    a.resize(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        a[i] += a[i - 1];
    // for (auto i : a)
    //     cout << i << " ";
    // cout << endl;
    for (int i = 1; i <= n; i++)
        dfs(i, 0);
    if (flag == 1)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}