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

const int maxn = 100010, maxm = 210;
const double inf = 1e20;

int n, m, l[maxm], r[maxm], a[maxn], p[maxn][maxm];
ll s[maxn], q[maxm][maxn], f[maxn][maxm];
std::vector < int > ans;

inline ll sqr(ll x) { return x * x; }
inline ll x(int i) { return -s[i]; }
inline ll y(int i, int j) { return f[i][j] - sqr(s[i]); }
inline double slope(int i, int j, int k) { return x(j) == x(i) ? inf : (y(j, k) - y(i, k)) / (x(j) - x(i)); }

int main() {
	read(n), read(m); rep(i, 1, n) read(a[i]);
	rep(i, 1, n) s[i] = s[i - 1] + a[i];
	// // rep(i, 1, n) print(s[i]); putc('\n');
	// rep(i, 1, n) rep(k, 1, std::min(i, m)) { int now, from; rep(j, 0, i - 1) {
	// 	now = std::max(f[i][k], f[j][k - 1] + s[j] * (s[i] - s[j]));
	// 	if (now > f[i][k]) f[i][k] = now, from = j; }
	// 	// printf("%d %d -> %d %d\n", from, k - 1, i, k);
	// }
	// // rep(i, 1, n) { rep(j, 1, m) print(f[i][j]); putc('\n'); }
	// memset(f, 0, sizeof(f));
	rep(i, 0, m) l[i] = 1;
	rep(i, 1, n) {
		// printf("%d %d %d\n", i, l[0], s[0]);
		while (l[0] < r[0] && slope(q[0][r[0] - 1], q[0][r[0]], 0) >= slope(q[0][r[0]], i, 0)) --r[0];
		q[0][++r[0]] = i;
	}
	// rep(i, l[0], r[0]) print(q[0][i]); putc('\n');
	for (int i = 1; i <= n; i++) {
		for (int k = 1; k <= std::min(i, m); k++) {
			while (l[k - 1] < r[k - 1] && slope(q[k - 1][l[k - 1]], q[k - 1][l[k - 1] + 1], k - 1) < (double)s[i]) ++l[k - 1];
			int j = q[k - 1][l[k - 1]]; f[i][k] = f[j][k - 1] + s[j] * (s[i] - s[j]), p[i][k] = j;
			// printf("%d %d -> %d %d : %d %d : %d %d\n", j, k - 1, i, k, l[k - 1], r[k - 1], q[k - 1][l[k - 1]], q[k - 1][r[k - 1]]);
			while (l[k] < r[k] && slope(q[k][r[k] - 1], q[k][r[k]], k) >= slope(q[k][r[k]], i, k)) --r[k];
			q[k][++r[k]] = i;
		}
	}
	// rep(i, 1, n) { rep(j, 1, m) print(f[i][j]); putc('\n'); }
	print(f[n][m], '\n');
	for (int i = m, u = n; i >= 1; i--)
		u = p[u][i], ans.push_back(u);
	std::sort(ans.begin(), ans.end());
	for (auto it : ans) print(it); puts("");
	return 0;
}