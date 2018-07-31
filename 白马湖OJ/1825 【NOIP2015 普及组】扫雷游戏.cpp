#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
int n, m, a[maxn][maxn];
char c[maxn][maxn];
int main() {
    scanf("%d%d\n", &n, &m);
    for (int i = 1; i <= n; i++) gets(c[i] + 1);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (c[i][j] == '*') {
                a[i + 1][j]++;
                a[i - 1][j]++;
                a[i][j + 1]++;
                a[i][j - 1]++;
                a[i + 1][j + 1]++;
                a[i + 1][j - 1]++;
                a[i - 1][j + 1]++;
                a[i - 1][j - 1]++;
            }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            if (c[i][j] == '*') putchar('*');
            else printf("%d", a[i][j]);
        puts("");
    }
    return 0;
}