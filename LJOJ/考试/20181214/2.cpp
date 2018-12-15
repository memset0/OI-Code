// =================================
//   author: memset0
//   date: 2018.12.14 08:18:28
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
#define int long long
namespace ringo {
typedef long long ll;

template <class T> inline void read(T &x) {
	x = 0; register char c = getchar(); register bool f = 0;
	while (!isdigit(c)) f ^= c == '-', c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (f) x = -x;
}
template <class T> inline void print(T x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) print(x / 10);
	putchar('0' + x % 10);
}
template <class T> inline void maxd(T &a, T b) { if (b > a) a = b; }
template <class T> inline void mind(T &a, T b) { if (b < a) a = b; }
template <class T> inline void print(T x, char c) { print(x), putchar(c); }

const int N = 5e5 + 10, M = 6e6 + 10, inf = 2e18;
int n, m, u, v, w, x, now, flag, sumk, sumb, minx, maxx;
int p[N], k[N], b[N];
int tot = 2, hed[N], to[M], nxt[M], val[M], lst[M];
bool vis[N];
ll ans1, ans2;
std::vector < int > vet; 

inline void die() { puts("NIE"); exit(0); }

inline void add_edge(int u, int v, int w) {
	// printf("add edge %lld %lld %lld\n", u, v, w);
	nxt[tot] = hed[u], to[tot] = v, val[tot] = w, hed[u] = tot++;
	nxt[tot] = hed[v], to[tot] = u, val[tot] = w, hed[v] = tot++;
}

void dfs(int u) {
	vis[u] = 1, vet.push_back(u);
	for (int i = hed[u], v = to[i], vk, vb, vx; i; i = nxt[i], v = to[i]) {
		vk = k[u] * -1, vb = val[i] - b[u];
		if (!vis[v]) {
			k[v] = vk, b[v] = vb;
			dfs(v);
		} else if (vk == k[v]) {
			if (vb != b[v]) die();
		} else {
			vx = vb - b[v];
			if (vx % (k[v] - vk)) die();
			vx /= k[v] - vk;
			if (flag && vx != x) die();
			flag = 1, x = vx;
		}
	}
}

void main() {
	read(n), read(m);
	for (int i = 1; i <= n; i++) read(p[i]);
	for (int i = 1; i <= m; i++) {
		read(u), read(v), read(w);
		add_edge(u, v, p[u] + p[v] - w);
	}
	for (int i = 1, u; i <= n; i++) 
		if (!vis[i]) {
			vet.clear(), flag = x = sumk = sumb = 0;
			maxx = p[i], minx = 0, k[i] = 1;
			dfs(i);
			for (size_t j = 0; j < vet.size(); j++) {
				u = vet[j], sumk += k[u], sumb += b[u];
				if (k[u] == 1) {
					mind(maxx, p[u] - b[u]);
					maxd(minx, -b[u]);
				} else {
					mind(maxx, b[u]);
					maxd(minx, b[u] - p[u]);
				}
			}
			if (minx > maxx) die();
			if (flag) {
				if (!(minx <= x && x <= maxx)) die();
				ans1 += sumk * x + sumb;
				ans2 += sumk * x + sumb;
			} else {
				if (sumk > 0) {
					ans1 += sumk * minx + sumb;
					ans2 += sumk * maxx + sumb;
				} else {
					ans1 += sumk * maxx + sumb;
					ans2 += sumk * minx + sumb;
				}
			}
			// printf(">> %lld %lld : %lld %lld : %lld %lld\n", x, flag, sumk, sumb, minx, maxx);
		}
	print(ans1, ' '), print(ans2, '\n');
}

} signed main() { return ringo::main(), 0; }