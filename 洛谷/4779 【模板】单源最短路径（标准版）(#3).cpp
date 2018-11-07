#include <bits/stdc++.h>
#define il inline
#define rg register
#define ll long long
#define getc getchar
#define putc putchar
#define rep(i, l, r) for (int i = l; i <= r; ++i)
namespace ringo {

template < class T > il void read(T &x) {
	x = 0; rg char c = getc(); rg bool f = 0;
	while (!isdigit(c)) f ^= c == '-', c = getc();
	while (isdigit(c)) x = x * 10 + c - '0', c = getc();
	if (f) x = -x;
}

template < class T > il void print(T x) {
	if (x < 0) putc('-'), x = -x;
	if (x > 9) print(x / 10);
	putc('0' + x % 10);
}

const int maxn = 100010, maxm = 200010;

int n, m, s, u, v, w;
int dis[maxn]; bool vis[maxn];
int tot = 2, hed[maxn], nxt[maxm], to[maxm], val[maxm];

struct status {
	int u, w;
	il bool operator < (const status &other) const {
		return w > other.w;
	}
};
std::priority_queue < status > q;

void main() {
	read(n), read(m), read(s);
	rep(i, 1, m) { read(u), read(v), read(w);
		nxt[tot] = hed[u], to[tot] = v, val[tot] = w, hed[u] = tot++;
	}
	memset(dis, -1, sizeof(dis)); dis[s] = 0;
	q.push((status){s, 0});
	while (q.size()) {
		u = q.top().u, q.pop();
		if (vis[u]) continue; else vis[u] = 1;
		for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
			if (dis[u] + val[i] < dis[v] || dis[v] == -1) {
				dis[v] = dis[u] + val[i];
				q.push((status){v, dis[v]});
			}
	}
	for (int i = 1; i <= n; i++)
		print(dis[i]), putc(i == n ? '\n' : ' ');
}

} int main() { return ringo::main(), 0; }