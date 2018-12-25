// =================================
//   author: memset0
//   date: 2018.12.25 08:09:28
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
namespace ringo {
typedef long long ll;
typedef unsigned long long ull;
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
template <class T> inline T abs(const T &a) { if (a < 0) return -a; return a; }

const int N = 1e5 + 10, inf = 2e9;
int n, m, x, y, op, min, max;
int a[N], ch[N][2];

int pos, id[N], fa[N], top[N], wid[N], siz[N], son[N], side[N];
struct info {
	int min, max, _min, _max;
	inline info reverse() {
		return (info) {
			_max, _min,
			max, min
		};
	}
};
inline info merge(const info &a, const info &b) {
	return (info) {
		std::max(a.min, b.min), 
		std::min(a.max, b.max),
		std::min(a._min, b._min),
		std::max(a._max, b._max)
	};
}
struct node {
	int l, r, mid;
	bool rev, lazy;
	info x;
} p[N << 2];
inline info get_info(int k, bool flag) {
	if (flag) return (info){a[k], inf, a[k], -inf};
	else return (info){-inf, a[k], inf, a[k]};
}
inline void pushup(int u) {
	p[u].lazy ^= 1, p[u].rev ^= 1;
	p[u].x = p[u].x.reverse();
}
inline void pushdown(int u) {
	if (p[u].lazy) {
		if (p[u].l != p[u].r)
			pushup(u << 1), pushup(u << 1 | 1);
		p[u].lazy = 0;
	}
}
void dfs1(int u) {
	siz[u] = 1;
	for (int i = 0; i < 2; i++)
		if (ch[u][i]) {
			dfs1(ch[u][i]), fa[ch[u][i]] = u, siz[u] += siz[ch[u][i]];
			if (siz[ch[u][i]] > siz[son[u]]) son[u] = ch[u][i], side[u] = i;
		}
}
void dfs2(int u, int toppoint) {
	id[u] = ++pos, wid[id[u]] = u, top[u] = toppoint;
	if (siz[u] == 1) return;
	dfs2(son[u], toppoint);
	for (int i = 0; i < 2; i++)
		if (ch[u][i] && i != side[u])
			dfs2(ch[u][i], ch[u][i]);
}
void build(int u, int l, int r) {
	p[u].l = l, p[u].r = r, p[u].mid = (l + r) >> 1;
	if (l == r) { p[u].x = get_info(wid[l], side[wid[l]]); return; }
	build(u << 1, l, p[u].mid);
	build(u << 1 | 1, p[u].mid + 1, r);
	p[u].x = merge(p[u << 1].x, p[u << 1 | 1].x);
}
void modify(int u, int k) {
	pushdown(u);
	if (p[u].l == p[u].r) {
		p[u].x = get_info(wid[k], side[wid[k]] ^ p[u].rev);
		return;
	}
	modify(k <= p[u].mid ? u << 1 : u << 1 | 1, k);
	p[u].x = merge(p[u << 1].x, p[u << 1 | 1].x);
}
void reverse(int u, int l, int r) {
	pushdown(u);
	if (p[u].l == l && p[u].r == r) { pushup(u); return; }
	if (r <= p[u].mid) reverse(u << 1, l, r);
	else if (l > p[u].mid) reverse(u << 1 | 1, l, r);
	else reverse(u << 1, l, p[u].mid), reverse(u << 1 | 1, p[u].mid + 1, r);
	p[u].x = merge(p[u << 1].x, p[u << 1 | 1].x);
}
info query(int u, int l, int r) {
	pushdown(u);
	if (p[u].l == l && p[u].r == r) return p[u].x;
	if (r <= p[u].mid) return query(u << 1, l, r);
	else if (l > p[u].mid) return query(u << 1 | 1, l, r);
	else return merge(query(u << 1, l, p[u].mid), query(u << 1 | 1, p[u].mid + 1, r));
}
inline bool check(int u, const info &lim) { return lim.min < u && u < lim.max; }
bool query(int u, int w) {
	info ret = (info){-inf, inf, inf, -inf};
	while (u) {
		if (top[u] != u) {
			info tmp = query(1, id[top[u]], id[fa[u]]);
			// printf("xay ak ioi %d %d %d %d\n", tmp.min, tmp.max, tmp._min, tmp._max);
			ret = merge(ret, tmp);
		}
		if (fa[top[u]]) {
			info tmp = query(1, id[fa[top[u]]], id[fa[top[u]]]).reverse();
			// printf("mwh ak ioi %d %d %d %d\n", tmp.min, tmp.max, tmp._min, tmp._max);
			ret = merge(ret, tmp);
		}
		u = fa[top[u]];
	}
	// printf("<< %d %d %d %d >>\n", ret.min, ret.max, ret._min, ret._max);
	return check(w, ret);
}
void main() {
	read(n), read(m);
	for (int i = 1; i <= n; i++) read(a[i]), read(ch[i][0]), read(ch[i][1]);
	dfs1(1), dfs2(1, 1), build(1, 1, n);
	// for (int i = 1; i <= n; i++) print(id[i], " \n"[i == n]);
	// for (int i = 1; i <= n; i++) print(son[i], " \n"[i == n]);
	for (int i = 1; i <= m; i++) {
		read(op), read(x);
		if (op == 1) {
			read(y), a[x] = y, modify(1, id[x]);
		} else if (op == 2) {
			// for (int i = 1; i <= n; i++)
			// 	for (int j = i; j <= n; j++) {
			// 		auto it = query(1, i, j);
			// 		printf("[%d %d] %d %d %d %d\n", i, j, it.min, it.max, it._min, it._max);
			// 	}
			reverse(1, id[x], id[x] + siz[x] - 1);
			// for (int i = 1; i <= n; i++)
			// 	for (int j = i; j <= n; j++) {
			// 		auto it = query(1, i, j);
			// 		printf("[%d %d] %d %d %d %d\n", i, j, it.min, it.max, it._min, it._max);
			// 	}
		} else {
			if (x == 1) puts("YES");
			else puts(query(x, a[x]) ? "YES" : "NO");
		}
		// if (op == 1) printf(">>> %d %d %d\n", op, x, y);
		// else printf(">>> %d %d\n", op, x);
	}
}

} signed main() { return ringo::main(), 0; }
