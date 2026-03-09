#include "bits/stdc++.h"
using namespace std;
#define int long long
struct Node {
    int a, b;
};
bool cmp(Node a, Node b) {
    if (a.a - a.b == b.a - b.b)
        return a.a < b.a;
    return (a.a - a.b) < (b.a - b.b);
}
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<Node> node(m);
    for (int i = 0; i < m; i++)
        cin >> node[i].a >> node[i].b;
    sort(node.begin(), node.end(), cmp);
    int ans = 0;
    for (int i = 0; i < m; i++) {
        if (n < node[i].a)
            continue;
        ans += (n - node[i].a) / (node[i].a - node[i].b) + 1;
        n -= ((n - node[i].a) / (node[i].a - node[i].b) + 1) * (node[i].a - node[i].b);
    }
    cout << ans << endl;
    return 0;
}