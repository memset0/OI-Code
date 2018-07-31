#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
struct Road {
    int s, e, v;
} p[maxn * maxn];
int n, l = 0, a[maxn][maxn], fa[maxn];
bool cmp(Road a, Road b) {
    if (a.v == b.v) return a.s < b.s;
    else return a.v < b.v;
}
int find(int a) {
    if (fa[a] == a) return a;
    else return fa[a] = find(fa[a]);
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (a[i][j]) {
                l++; p[l].s = i; p[l].e = j; p[l].v = a[i][j];
            }
    sort(p + 1, p + l + 1, cmp);
    int ans = 0;
    for (int i = 1; i <= l; i++) {
        if (find(p[i].s) != find(p[i].e)) {
            ans += p[i].v;
            fa[find(p[i].s)] = find(p[i].e);
        }
    }
    cout << ans << endl;
}