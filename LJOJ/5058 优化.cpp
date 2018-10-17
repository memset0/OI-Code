// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r) for (int i = l; i <= r; i++)
#define getc(x) getchar(x)
#define putc(x) putchar(x)
 
template <typename T> inline void read(T &x) {
    x = 0; register char ch; register bool fl = 0;
    while (ch = getc(), ch < 48 || 57 < ch) fl ^= ch == '-'; x = (ch & 15);
    while (ch = getc(), 47 < ch && ch < 58) x = (x << 1) + (x << 3) + (ch & 15);
    if (fl) x = -x;
}
template <typename T> inline void readc(T &x) {
    while (x = getc(), !islower(x) && !isupper(x));
}
template <typename T> inline void print(T x, char c = ' ') {
    static int buf[40];
    if (x == 0) { putc('0'); putc(c); return; }
    if (x < 0) putc('-'), x = -x;
    for (buf[0] = 0; x; x /= 10) buf[++buf[0]] = x % 10 + 48;
    while (buf[0]) putc((char) buf[buf[0]--]);
    putc(c);
}
 
const int maxn = 30010, maxm = 210, inf = 1044266559;
 
int n, m, ans;
int sumMax, sumMin, preMax, preMin;
int a[maxn], f[maxn][maxm][8];
 
/*
0: 0+
1: 0-
2: +0
3: -0
4: ++
5: --
6: -+
7: +-
*/
 
int main() {
    // freopen("1.in", "r", stdin);
    memset(f, -63, sizeof(f));
    read(n), read(m);
    for (int i = 1; i <= n; i++)
        read(a[i]);
    for (int i = 1; i <= n; i++) {
        f[i][1][0] = sumMax = std::max(sumMax, 0) + a[i];
        f[i][1][1] = sumMin = std::max(sumMin, 0) - a[i];
        for (int j = 1; j <= m; j++) {
            f[i][j][2] = f[i - 1][j][2] + a[i];
            f[i][j][3] = f[i - 1][j][3] - a[i];
            f[i][j][4] = f[i - 1][j][4] + a[i] * 2;
            f[i][j][5] = f[i - 1][j][5] - a[i] * 2;
            f[i][j][6] = f[i - 1][j][6];
            f[i][j][7] = f[i - 1][j][7];
        }
        for (int j = 2; j <= m; j++) {
            preMax = std::max(f[i - 1][j - 1][0], std::max(f[i - 1][j - 1][4], f[i - 1][j - 1][6]));
            preMin = std::max(f[i - 1][j - 1][1], std::max(f[i - 1][j - 1][5], f[i - 1][j - 1][7]));
            if (j == m) {
                f[i][j][2] = std::max(f[i][j][2], preMin + a[i]);
                f[i][j][3] = std::max(f[i][j][3], preMax - a[i]);
            } else {
                f[i][j][4] = std::max(f[i][j][4], preMin + a[i] * 2);
                f[i][j][5] = std::max(f[i][j][5], preMax - a[i] * 2);
                f[i][j][6] = std::max(f[i][j][6], preMax);
                f[i][j][7] = std::max(f[i][j][7], preMin);
            }
        }
    }
    // for (int i = 1; i <= n; i++) {
    //  for (int j = 1; j <= m; j++) {
    //      for (int k = 0; k < 8; k++)
    //          if (f[i][j][k] < -inf + 1000)
    //              printf("* ");
    //          else
    //              print(f[i][j][k]);
    //      putc('\n');
    //  }
    //  putc('\n');
    // }
    ans = -inf;
    for (int i = 1; i <= n; i++)
        ans = std::max(ans, std::max(f[i][m][2], f[i][m][3]));
    print(ans, '\n');
    return 0;
}