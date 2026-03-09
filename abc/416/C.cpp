#include "bits/stdc++.h"
using namespace std;
#define int long long
int n, k, x;
vector<string> s(n);
string st;
vector<string> ans;
void dfs(int p) {
    if (p == k) {
        ans.push_back(st);
        return;
    }
    for (int i = 0; i < n; i++) {
        string temp = st;
        st += s[i];
        dfs(p + 1);
        st = temp;
    }
}
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> k >> x;
    s.resize(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];
    dfs(0);
    sort(ans.begin(), ans.end());
    cout << ans[x - 1] << endl;
    return 0;
}