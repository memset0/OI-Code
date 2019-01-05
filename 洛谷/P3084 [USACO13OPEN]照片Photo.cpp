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

const int maxn = 200010, maxm = 600010;
int n, m, u, l, r;
int dis[maxn], cnt[maxn], inq[maxn];
int tot = 2, hed[maxn], nxt[maxm], to[maxm], val[maxm];

std::deque < int > q;

inline void add_edge(int u, int v, int w) {
	nxt[tot] = hed[u], to[tot] = v, val[tot] = w;
	hed[u] = tot++;
}

bool spfa() {
	memset(dis, 63, sizeof(dis));
	q.push_back(0), inq[0] = 1, dis[0] = 0;
	while (q.size()) {
		u = q.front(), q.pop_front();
		inq[u] = 0;
		// printf("%d : %d\n", l, r);
		for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
			if (dis[v] > dis[u] + val[i]) {
				// printf("%d -> %d\n", u, v);
				dis[v] = dis[u] + val[i];
				if (!inq[v]) {
					if (++cnt[v] > 1000)
						return true;
					inq[v] = 1;
					if (q.size() && dis[v] > dis[q.front()])
						q.push_back(v);
					else
						q.push_front(v);
				}
			}
	}
	// for (int i = 1; i <= n; i++)
	// 	printf("%d : %d\n", i, dis[i] - dis[i - 1]);
	// putc('\n');
	return false;
}

int main() {
	// freopen("1.in", "r", stdin);

	read(n), read(m);
	for (int i = 1; i <= n; i++) {
		add_edge(i - 1, i, 1);
		add_edge(i, i - 1, 0);
	}
	for (int i = 1; i <= m; i++) {
		read(l), read(r);
		add_edge(l - 1, r, 1);
		add_edge(r, l - 1, -1);
	}
	if (spfa()) puts("-1");
	else print(dis[n], '\n');

	return 0;
}