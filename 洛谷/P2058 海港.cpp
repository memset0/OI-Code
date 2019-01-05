#include <bits/stdc++.h> 
using namespace std;
const int maxn = 100010;
const int maxm = 300010;
int n, m, t, l = 1, r = 0, ans = 0;
int b[maxm];
struct AAA {
    int t, v;
} a[maxm];
int main() {
    cin >> n;
    for (int k = 1; k <= n; k++) {
        scanf("%d%d", &t, &m);
        for (int i = r + 1; i <= r + m; i++) {
            scanf("%d", &a[i].v);
            a[i].t = t;
            if (!b[a[i].v]) ans++;
            b[a[i].v]++;
        }
        r += m;
        for (int i = l; i <= r; i++) {
            if (a[i].t + 86400 <= t) {
                b[a[i].v]--;
                if (!b[a[i].v]) ans--;
                l++;
            } else break;
        }
        printf("%d\n", ans);
    }
    return 0;
}