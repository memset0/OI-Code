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

int n, l, r, A, B, C;
int a[maxn], q[maxn];
ll s[maxn], f[maxn];

ll sqr(ll x) { return x * x; }
ll x(ll i) { return s[i]; }
ll y(ll i) { return f[i] + A * sqr(s[i]) - B * s[i]; }
double slope(int i, int j) { return (y(j) - y(i)) / (x(j) - x(i)); }

int main() {
	// freopen("1.in", "r", stdin);

    read(n), read(A), read(B), read(C);
    for (int i = 1; i <= n; i++)
        read(a[i]), s[i] = s[i - 1] + a[i];
    // memset(f, -63, sizeof(f));
    // f[0] = 0;
    // for (int i = 1; i <= n; i++)
    //     for (int j = 0; j < i; j++) {
    //         int now = f[j] + A * sqr(s[i] - s[j]) + B * (s[i] - s[j]) + C;
    //         if (now > f[i]) {
    //             f[i] = now;
    //             printf("%d -> %d\n", j, i);
    //         }
    //     }
    // for (int i = 1; i <= n; i++)
    //     printf("%d ", f[i]);
    // puts("");
    // memset(f, 0, sizeof(f));
    l = r = 0, q[0] = 0;
    for (int i = 1; i <= n; i++) {
  
        while (l < r && slope(q[l], q[l + 1]) > 2 * A * s[i]) ++l;
        // printf("%d -> %d : %d : %d %d %d : %d %d\n", q[l], i, f[q[l]], A * sqr(s[i] - s[q[l]]), B * (s[i] - s[q[l]]), C, l, r);
        f[i] = f[q[l]] + A * sqr(s[i] - s[q[l]]) + B * (s[i] - s[q[l]]) + C;
        while (l < r && slope(q[r - 1], q[r]) <= slope(q[r], i)) --r;
        q[++r] = i;
    }
    // for (int i = 1; i < n; i++) print(f[i]);
    print(f[n], '\n');

	return 0;
}