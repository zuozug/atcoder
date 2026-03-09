#include "bits/stdc++.h"
using namespace std;
#define int long long
int n;
string s;
map<int, int> memory;
int solve(int p) {
    if (memory.count(p))
        return memory[p];
    // cout << p << endl;
    if (s[p - 1] == '1')
        return memory[p] = 0;
    int flag = 0;
    for (int i = 0; i < n; i++) {
        if ((p & (1 << i)) == 0)
            continue;
        if (solve(p ^ 1 << i) == 1) {
            flag = 1;
            break;
        }
    }
    return memory[p] = flag;
}
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        memory.clear();
        cin >> n;
        cin >> s;
        int temp = 1;
        while (temp <= (1 << n) - 1) {
            if (s[temp - 1] == '0')
                memory[temp] = 1;
            else
                memory[temp] = 0;
            temp *= 2;
        }
        if (solve((1 << n) - 1) == 1)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        // for (auto i : memory)
        //     cout << i.first << " " << i.second << endl;
    }
    return 0;
}