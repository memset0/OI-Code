#include <bits/stdc++.h>
using namespace std;
const int maxn = 20010;
const int maxm = 100010;
int n, m, v[maxn], f[maxn];
vector < int > a[maxn];
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        scanf("%d", &v[i]), f[i] = v[i];
    int x, y;
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &x, &y);
        if (x > y) a[x].push_back(y);
        else a[y].push_back(x);
    }
    int ans = -1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < a[i].size(); j++) {
            f[i] = max(f[i], f[a[i][j]] + v[i]);
        }
        if (f[i] > ans) ans = f[i];
    }
    cout << ans << endl;
    return 0;
}