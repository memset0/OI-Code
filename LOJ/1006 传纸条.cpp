// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int read() {
    int x = 0; bool m = 0; char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') m = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (m) return -x; else return x;
}

const int maxn = 52;

int n, m, v[maxn][maxn], f[maxn][maxn][maxn][maxn];

int main() {

    n = read(), m = read();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            v[i][j] = read();
    
    for (int a = 1; a <= n; a++)
        for (int b = 1; b <= m; b++)
            for (int c = 1; c <= n; c++)
                for (int d = b + 1; d <= m; d++) {
                    f[a][b][c][d] = max(max(f[a][b - 1][c][d - 1], f[a][b - 1][c - 1][d]),
                            max(f[a - 1][b][c][d - 1], f[a - 1][b][c - 1][d])) + 
                            v[a][b] + v[c][d];
                }
    printf("%d\n", f[n][m - 1][n - 1][m]);
    
    return 0;
}

