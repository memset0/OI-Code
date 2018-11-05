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

const int maxn = 10010;

int T, n, m, a[maxn];
bool flag, f[maxn];

int main() {
	// freopen("1.in", "r", stdin);
    read(T);
    while (T--) {
        flag = false, memset(f, 0, sizeof(f));
        read(n); rep(i, 1, n) read(a[i]);
        for (int i = n; i >= 1; i--) {
            if (f[a[i]]) { flag = 1; break; }
            for (int j = i + 1, t; j <= n; j++) {
                t = (a[i] << 1) - a[j];
                if (t > 0 && t <= n) f[t] = 1;
            }
         }
         putc(flag ? 'Y' : 'N'), putc('\n');
    }
	return 0;
}