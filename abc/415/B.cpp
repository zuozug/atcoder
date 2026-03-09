#include "bits/stdc++.h"
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s;
    cin >> s;
    queue<int> q;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '#')
            q.push(i + 1);
    }
    while (!q.empty()) {
        cout << q.front() << ",";
        q.pop();
        cout << q.front() << endl;
        q.pop();
    }
    return 0;
}