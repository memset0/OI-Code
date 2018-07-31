#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
int n, m, a[maxn][maxn], f[maxn][maxn], anss[maxn];
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &a[i][j]);
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= m; j++) {
            if (j == i) f[i][j] = a[i][j] + f[i - 1][j - 1];
            else f[i][j] = max(f[i][j - 1], f[i - 1][j - 1] + a[i][j]);
        }
    }
    int ans = f[n][m];
    cout << ans << endl;
    for (int i = n; i > 0; i--) {
        for (int j = 1; j <= m; j++)
            if (f[i][j] == ans) {
                anss[i] = j;
                ans = f[i - 1][j - 1];
                break;
            }
    }
    for (int i = 1; i <= n; i++)
        printf("%d ", anss[i]);
    puts("");
//  for (int i = 1; i <= n; i++) {
//      for (int j = 1; j <= m; j++)
//          cout << f[i][j] << " ";
//      cout << endl;
//  }
    return 0;
}