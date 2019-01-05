// luogu-judger-enable-o2
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

const int maxn = 1000010;

int n, l, r, p[maxn], c[maxn], q[maxn];
ll d[maxn], f[maxn], s1[maxn], s2[maxn];

inline ll sqr(ll x) { return x * x; }
inline ll x(int i) { return s1[i]; }
inline ll y(int i) { return f[i] + s2[i]; }
inline double slope(int i, int j) { return (y(j) - y(i)) / (x(j) - x(i)); }

int main() {
	// freopen("1.in", "r", stdin);
    read(n);
    for (int i = 1; i <= n; i++)
        read(d[i]), read(p[i]), read(c[i]);
    for (int i = 1; i <= n; i++) {
        s1[i] = s1[i - 1] + p[i];
        s2[i] = s2[i - 1] + 1ll * p[i] * d[i];
    }
    // for (int i = 1; i <= n; i++) print(d[i]); putc('\n');
    // for (int i = 1; i <= n; i++) print(s1[i]); putc('\n');
    // for (int i = 1; i <= n; i++) print(s2[i]); putc('\n');
    // memset(f, 0x3f, sizeof(f)); f[0] = 0;
    // for (int i = 1, k; i <= n; i++) {
    //     for (int j = 0; j < i; j++) {
    //         int now = f[j] + c[i] + d[i] * (s1[i] - s1[j]) - (s2[i] - s2[j]);
    //         // printf("%d[%d] > %d[%d] : %d %d %d : %d %d\n", j, now, i, f[i], d[i], (i - j) * s1[i] - s1[j], s2[i] - s2[j], f[j], d[i] * (s1[i] - s1[j]) - (s2[i] - s2[j]));
    //         if (now < f[i]) {
    //             k = j;
    //             f[i] = now;
    //         }
    //     }
    //     printf("%d -> %d\n", k, i);
    // }
    // for (int i = 1; i < n; i++)
    //     print(f[i]);
    // print(f[n], '\n');
    // memset(f, 0, sizeof(f));
    l = r = q[0] = 0;
    for (int i = 1, j; i <= n; i++) {
        while (l < r && slope(q[l], q[l + 1]) < d[i]) ++l;
        // printf("%d -> %d [%d %d]\n", q[l], i, q[l], q[r]);
        j = q[l], f[i] = f[j] + c[i] + d[i] * (s1[i] - s1[j]) - (s2[i] - s2[j]);
        while (l < r && slope(q[r - 1], q[r]) >= slope(q[r], i)) --r;
        q[++r] = i;
    }
    // for (int i = 1; i < n; i++)
    //     print(f[i]);
    print(f[n], '\n');
    return 0;
}