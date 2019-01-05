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

const int maxn = 10010, maxm = 50010, maxen = maxn * 21, maxem = maxm * 85;

#define at(x,y) ((x)+((y)*n))

int n, m, p, u, v, w, ans;
int dis[maxen], vis[maxen];
int tot = 2, hed[maxen], nxt[maxem], to[maxem], val[maxem];

inline void add_edge(int u, int v, int w) {
	// printf("add edge %d -> %d : %d\n", u, v, w);
	nxt[tot] = hed[u], to[tot] = v, val[tot] = w, hed[u] = tot++;
}

struct dist {
	int u, v;
};
inline bool operator < (const dist &a, const dist &b) {
	return a.v > b.v;
}
std::priority_queue < dist > q;


int main() {
	// freopen("1.in", "r", stdin);
	memset(dis, -1, sizeof(dis));

	read(n), read(m), read(p);
	for (int i = 1; i <= m; i++) {
		read(u), read(v), read(w);
		for (int i = 0; i <= p; i++) {
			add_edge(at(u, i), at(v, i), w);
			add_edge(at(v, i), at(u, i), w);
			if (i) add_edge(at(u, i - 1), at(v, i), 0);
			if (i) add_edge(at(v, i - 1), at(u, i), 0);
		}
	}
	dis[1] = 0, q.push(dist{1, 0});
	while (q.size()) {
		u = q.top().u, q.pop();
		if (vis[u]) continue; else vis[u] = 1;
		// printf(">>> %d %d\n", u, dis[u]);
		for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i]) {
			// printf("%d -> %d : %d\n", u, v, val[i]);		
			if (!~dis[v] || dis[u] + val[i] < dis[v]) {
				dis[v] = dis[u] + val[i];
				q.push(dist{v, dis[v]});
			}
		}
	}
	ans = -1;
	for (int i = 0; i <= p; i++)
		if ((!~ans || ans > dis[at(n, i)]) && ~dis[at(n, i)])
			ans = dis[at(n, i)];
	print(ans, '\n');

	return 0;
}