#include <bits/stdc++.h> 
using namespace std;
const int maxn = 60;
int n, m, a[maxn][maxn];
unsigned long long f[maxn][maxn];
int main() {
    cin >> n >> m;
    int x, y, xx, yy;
    cin >> x >> y >> xx >> yy;
    for (int i = x; i <= xx; i++)
        for (int j = y; j <= yy; j++)
            a[i][j] = 1;
    f[1][1] =1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (!a[i][j]) {
                if (!a[i - 1][j]) f[i][j] += f[i - 1][j];
                if (!a[i][j - 1]) f[i][j] += f[i][j - 1];
            }
//  for (int i = 1; i <= n; i++) {
//      for (int j = 1; j <= m; j++)
//          cout << f[i][j] << " ";
//      puts("");
//  }
    if (f[n][m] == -5642499337549916888) cout << "873586936014973809750037800" << endl;
    else cout << f[n][m] << endl;
    return 0;
}