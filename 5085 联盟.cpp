// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

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

const int maxn = 300010;
const int inf = 1000000000;

int n, m, u, v, s, e, l, r, now, ans, cnt, ret, start;
int q[maxn], fa[maxn], dep[maxn], dis[maxn], vis[maxn], pre[maxn];
int mx1[maxn], mx2[maxn], mx3[maxn], fr1[maxn], fr2[maxn], fr3[maxn], up[maxn], down[maxn];
int tot = 2, hed[maxn], to[maxn << 1], nxt[maxn << 1], id[maxn << 1];

typedef std::vector < int > vector;
typedef vector::iterator iterator;
vector vet;

void dfs(int u) {
	mx1[u] = 1;
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (v != fa[u]) {
			fa[v] = u;
			dep[v] = dep[u] + 1;
			dfs(v);
			if (mx1[v] + 1 > mx1[u]) {
				mx3[u] = mx2[u], fr3[u] = fr2[u];
				mx2[u] = mx1[u], fr2[u] = fr1[u];
				mx1[u] = mx1[v] + 1, fr1[u] = v;
			} else if (mx1[v] + 1 > mx2[u]) {
				mx3[u] = mx2[u], fr3[u] = fr2[u];
				mx2[u] = mx1[v] + 1, fr2[u] = v;
			} else if (mx1[v] + 1 > mx3[u]) {
				mx3[u] = mx1[v] + 1, fr3[u] = v;
			}
		}
}

void dfs2(int u, int from) {
	// printf("dfs2 %d %d\n", u, from);
	down[u] = std::max(mx1[u], mx1[u] + mx2[u] - 1);
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (v != fa[u]) {
			if (v == fr1[u]) {
				dfs2(v, std::max(from + 1, mx2[u] + 1));
				up[v] = from + mx2[u] - 1;
			} else {
				dfs2(v, std::max(from + 1, mx1[u] + 1));
				up[v] = from + mx1[u] - 1;
			}
			down[u] = std::max(down[u], down[v]);
		}
}

void dfs3(int u, int mx, int tag) {
	// printf("%d %d %d\n", u, mx, tag);
	up[u] = std::max(up[u], mx);
	if (tag) {
		int son1 = 0, son2 = 0;
		for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
			if (v != fa[u]) {
				if (down[v] > down[son1]) {
					son2 = son1;
					son1 = v;
				} else if (down[v] > down[son2]) {
					son2 = v;
				}
			}
		for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
			if (v != fa[u]) {
				up[v] = std::max(up[v], up[u]);
				int nxt;
				if (v == fr1[u]) nxt = mx2[u] + mx3[u] - 1;
				else if (v == fr2[u]) nxt = mx1[u] + mx3[u] - 1;
				else nxt = mx1[u] + mx2[u] - 1;
				if (v == son1) {
					dfs3(v, std::max(nxt, down[son2]), 1);
				} else {
					dfs3(v, std::max(nxt, down[son1]), 0);
				}
			}
	} else {
		for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
			if (v != fa[u]) {
				up[v] = std::max(up[v], up[u]);
				dfs3(v, mx, 0);
			}
	}
}

void dfs4(int u) {
	--up[u], --down[u];
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (v != fa[u]) {
			dfs4(v);
			int now = std::max(((up[v] + 1) >> 1) + ((down[v] + 1) >> 1) + 1, std::max(up[v], down[v]));
			// printf("%d : %d\n", v, now);
			if (now < ans) {
				ans = now;
				vet.clear();
				vet.push_back(id[i]);
				start = v;
			} else if (now == ans) {
				vet.push_back(id[i]);
			}
		}
}

int bfs(int s, int x) {
	memset(dis, 0, sizeof(dis));
	memset(pre, 0, sizeof(pre));
	l = r = 1, q[1] = s, dis[s] = 1;
	while (l <= r) {
		u = q[l++];
		for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
			if (!dis[v] && v != x) {
				dis[v] = dis[u] + 1;
				pre[v] = u;
				q[++r] = v;
			}
	}
	ret = 0;
	for (int i = 1; i <= n; i++)
		if (dis[i] > dis[ret])
			ret = i;
	// for (int i = 1; i <= n; i++)
	// 	print(dis[i]);
	// putc('\n');
	// for (int i = 1; i <= n; i++)
	// 	print(pre[i]);
	// putc('\n');
	return ret;
}

int find_middle(int u, int v) {
	int s = bfs(u, v);
	int e = bfs(s, v);
	// printf("%d %d\n", s, e);
	int l = (dis[e] - 1) >> 1;
	while (l--) {
		e = pre[e];
	}
	return e;
}

int main() {
	// freopen("1.in", "r", stdin);

	read(n);
	for (int i = 1; i < n; i++) {
		read(u), read(v);
		nxt[tot] = hed[u], to[tot] = v, id[tot] = i, hed[u] = tot++;
		nxt[tot] = hed[v], to[tot] = u, id[tot] = i, hed[v] = tot++;
	}
	ans = inf, dep[1] = 1;
	dfs(1), dfs2(1, 1), dfs3(1, 0, 1), dfs4(1);
	// for (int i = 1; i <= n; i++) print(up[i]); putc('\n');
	// for (int i = 1; i <= n; i++) print(down[i]); putc('\n');
	// for (int i = 1; i <= n; i++) print(mx1[i]); putc('\n');
	// for (int i = 1; i <= n; i++) print(mx2[i]); putc('\n');
	print(ans, '\n');
	print(vet.size());
	std::sort(vet.begin(), vet.end());
	for (iterator it = vet.begin(); it != vet.end(); it++)
		print(*it);
	putc('\n');
	e = find_middle(fa[start], start);
	memset(vis, 0, sizeof(vis));
	s = find_middle(start, fa[start]);
	// print(start), print(fa[start]), print(s), print(e, '\n');
	return 0;
}

// 3 1 2 5
