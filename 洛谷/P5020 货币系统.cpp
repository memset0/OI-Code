#include <bits/stdc++.h>
using namespace std;
const int N = 101, M = 25001;
int T, n, ans, a[N], f[M];
int main() {
    for (scanf("%d", &T); T--; ) {
        memset(f, 0, sizeof(f));
        scanf("%d", &n), ans = n;
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        sort(a + 1, a + n + 1);
        f[0] = 1;
        for (int i = 1; i <= n; i++) {
            ans -= f[a[i]];
            for (int j = 0; j < M; j++)
                if (f[j] && j + a[i] < M)
                    f[j + a[i]] = 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}