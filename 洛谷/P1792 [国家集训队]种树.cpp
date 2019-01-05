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

const int maxn = 400010;

int n, m, u, v, cnt, ans;
int l[maxn], r[maxn], val[maxn], vis[maxn];

struct pair {
	int k, v;
	inline bool operator < (const pair &other) const {
		return v < other.v;
	}
};
std::priority_queue < pair > q;

int main() {
	// freopen("1.in", "r", stdin);

	read(n), read(m);
	if (m > (n >> 1)) {
		puts("Error!");
		return 0;
	}
	for (int i = 1; i <= n; i++)
		read(val[i]);
	l[1] = n, r[n] = 1;
	for (int i = 2; i <= n; i++)
		l[i] = i - 1;
	for (int i = 1; i < n; i++)
		r[i] = i + 1;
	for (int i = 1; i <= n; i++)
		q.push(pair{i, val[i]});
	cnt = n;
	for (int i = 1; i <= m; i++) {
		while (vis[q.top().k])
			q.pop();
		u = q.top().k, ans += q.top().v;
		q.pop();

		vis[u] = vis[l[u]] = vis[r[u]] = 1;
		v = ++cnt;
		r[l[l[u]]] = l[r[r[u]]] = v;
		l[v] = l[l[u]];
		r[v] = r[r[u]];
		val[v] = val[l[u]] + val[r[u]] - val[u];
		q.push(pair{v, val[v]});
	}
	print(ans, '\n');

	return 0;
}