#include <bits/stdc++.h>
using namespace std;
const int maxn = 40;
int n, a[maxn][maxn], f[maxn][maxn][maxn][maxn];
int main() {
    cin >> n;
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    while (x != 0 && y != 0 && z != 0) {
        a[x][y] = z;
        scanf("%d%d%d", &x, &y, &z);
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++)
                for (int l = 1; l <= n; l++) {
                    f[i][j][k][l] = a[i][j] + a[k][l] + max(f[i - 1][j][k - 1][l], max(f[i - 1][j][k][l - 1], max(f[i][j - 1][k - 1][l], f[i][j - 1][k][l - 1])));
                    if (i == k && j == l) f[i][j][k][l] -= a[i][j];
                }
    cout << f[n][n][n][n] << endl;
    return 0;
}