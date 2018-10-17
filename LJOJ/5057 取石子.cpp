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
 
const int maxn = 310, maxq = 510;
int a, b, c, ti, tj, tk, mx, T;
int f[maxn][maxn][maxn];
 
struct query {
    int a, b, c;
} q[maxq];
 
inline void sort(int &a, int &b, int &c) {
    if (a > b) std::swap(a, b);
    if (a > c) std::swap(a, c);
    if (b > c) std::swap(b, c);
}
 
inline void fill(int a, int b, int c) {
    sort(a, b, c);
//  printf("%d %d %d\n", a, b, c);
//  if (a == 2 && b == 3 && c == 8)
//      printf(">> %d %d %d\n", ti, tj, tk);
    if (a > mx || b > mx || c > mx)
        return;
    f[a][b][c] = 1;
}
 
int main() {
 
    read(T);
    for (int i = 1; i <= T; i++) {
        read(a), read(b), read(c);
        sort(a, b, c);
        q[i].a = a, q[i].b = b, q[i].c = c;
        mx = std::max(mx, std::max(a, std::max(b, c)));
    }
    for (int i = 0; i <= mx; i++)
        for (int j = i; j <= mx; j++)
            for (int k = j; k <= mx; k++)
                if (!f[i][j][k]) {
//                  printf("%d %d %d\n", i, j, k);
                    for (int t = 1, lim = std::max(mx - i, std::max(mx - j, mx - k)); t <= lim; t++) {
//                      printf("%d %d %d %d\n", i, j, k, t);
//                      ti = i, tj = j, tk = k;
                        fill(i + t, j, k);
                        fill(i, j + t, k);
                        fill(i, j, k + t);
                        fill(i, j + t, k + t);
                        fill(i + t, j, k + t);
                        fill(i + t, j + t, k);
                        fill(i + t, j + t, k + t);
                    }
                }
    for (int i = 1; i <= T; i++) {
        a = q[i].a, b = q[i].b, c = q[i].c;
//      printf(">>> %d %d %d %d\n", a, b, c, f[a][b][c]);
        puts(f[a][b][c] ? "Yes" : "No");
    }
 
    return 0;
}
