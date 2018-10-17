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
 
const int maxb = 40;
const ll mod = 1000000007;
int l, r, T, u0, u1;
ll ans;
int a[maxb], f1[maxb][2], f2[maxb][2];
 
void calc(int x, int f[maxb][2]) {
    int len = 0, tmp = x;
    while (tmp) {
        a[++len] = tmp & 1;
        tmp >>= 1;
    }
    for (int i = len; i >= 1; i--) {
        if (a[i]) {
            for (int j = len; j > i; j--)
                f[j][a[j]] += 1 << (i - 1);
            f[i][0] += 1 << (i - 1);
            for (int j = i - 1; j >= 1; j--) {
                f[j][0] += 1 << (i - 2);
                f[j][1] += 1 << (i - 2);
            }
        }
    }
    for (int i = maxb - 1; i > len; i--)
        f[i][0] = x;
}
 
void solve() {
    ans = 0;
    memset(f1, 0, sizeof(f1));
    memset(f2, 0, sizeof(f2));
     
    read(l), read(r);
    calc(r + 1, f2), calc(l, f1);
//  for (int i = 1; i < maxb; i++) {
//      printf("> %d %d\n", f2[i][0] - f1[i][0], f2[i][1] - f1[i][1]);
//  }
    for (int i = 1; i < maxb; i++) {
        u0 = f2[i][0] - f1[i][0];
        u1 = f2[i][1] - f1[i][1];
        (ans += 2ll * u0 * u1 % mod * ((1ll << (i - 1)) % mod) % mod) %= mod;
    }
    print(ans, '\n');
}
 
int main() {
//  freopen("3.txt", "r", stdin);
//  freopen("1.txt", "w", stdout);
    read(T);
    while (T--)
        solve();
    return 0;
}
 
