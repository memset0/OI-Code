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

const int maxn = 100010;
const int mod = 1000000007;

int n, m, x, y, opt, now;
int ans[maxn], inv[maxn], fa[maxn], siz[maxn];

std::map < int, int > map[maxn];

struct edge {
	int u, v;
};

struct rubbish {
	int u, fa, v, siz;
};

struct node {
	int l, r, mid;
	int rub_ans;
	std::vector < edge > set;
	std::vector < rubbish > rub;
} p[maxn << 2];

void build(int u, int l, int r) {
	p[u].l = l, p[u].r = r, p[u].mid = (l + r) >> 1;
	if (l == r)
		return;
	build(u << 1, l, p[u].mid);
	build(u << 1 | 1, p[u].mid + 1, r);
}

void insert(int u, int l, int r, const edge &x) {
	// printf("insert %d %d %d : %d %d\n", u, l, r, x.u, x.v);
	if (p[u].l == l && p[u].r == r) {
		p[u].set.push_back(x);
		return;
	}
	if (r <= p[u].mid)
		insert(u << 1, l, r, x);
	else if (l > p[u].mid)
		insert(u << 1 | 1, l, r, x);
	else {
		insert(u << 1, l, p[u].mid, x);
		insert(u << 1 | 1, p[u].mid + 1, r, x);
	}
}

inline int find(int x) {
	if (fa[x] == x)
		return x;
	return find(fa[x]);
}

inline void link(int u, int v, std::vector < rubbish > &vet) {
	int fu = find(u), fv = find(v);
	if (fu != fv) {
		// printf("link %d %d : %d -> %d\n", u, v, now, 1ll * now * inv[siz[fu]] % mod * inv[siz[fv]] % mod * (siz[fu] + siz[fv]) % mod);
		if (siz[fu] > siz[fv])
			std::swap(fu, fv);
		now = 1ll * now * inv[siz[fu]] % mod * inv[siz[fv]] % mod * (siz[fu] + siz[fv]) % mod;
		// merge u -> v
		vet.push_back(rubbish{fu, fa[fu], fv, siz[fv]});
		fa[fu] = fv;
		siz[fv] += siz[fu];
	}
}

void dfs(int u) {
// 	printf("=== dfs in %d : %d ===\n", u, now);
// 	for (int i = 1; i <= n; i++)
// 		print(fa[i]);
// 	putc('\n');
// 	for (int i = 1; i <= n; i++)
// 		print(siz[i]);
// 	putc('\n');
	p[u].rub_ans = now;
	for (std::vector < edge > ::iterator
			it = p[u].set.begin(); it != p[u].set.end(); it++)
		link(it->u, it->v, p[u].rub);
	if (p[u].l == p[u].r) {
		// printf(">>> %d >>> %d\n", p[u].l, now);
		ans[p[u].l] = now;
	} else {
		dfs(u << 1);
		dfs(u << 1 | 1);
	}
	now = p[u].rub_ans;
	for (std::vector < rubbish > ::reverse_iterator
			it = p[u].rub.rbegin(); it != p[u].rub.rend(); it++) {
		// printf("cut %d %d\n", it->u, it->v);
		// printf("back %d %d %d\n", it->u, it->v, it->siz);
		fa[it->u] = it->fa;
		siz[it->v] = it->siz;
	}
	// for (int i = 1; i <= n; i++)
	// 	print(fa[i]);
	// putc('\n');
	// for (int i = 1; i <= n; i++)
	// 	print(siz[i]);
	// putc('\n');
	// printf("=== dfs out %d : %d ===\n", u, now);
}

int main() {
	// freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);

	read(n), read(m);
	build(1, 1, m);
	for (int i = 1; i <= m; i++) {
		read(opt), read(x), read(y);
		if (opt == 1) {
			map[x][y] = i;
		} else {
			insert(1, map[x][y], i - 1, edge{x, y});
			map[x][y] = 0;
		}
	}
	for (int i = 1; i <= n; i++)
		for (std::map < int, int > ::iterator
				it = map[i].begin(); it != map[i].end(); it++)
			if (it->second) {
				insert(1, it->second, m, edge{i, it->first});
			}
	now = 1;
	for (int i = 1; i <= n; i++) {
		fa[i] = i;
		siz[i] = 1;
	}
	inv[0] = inv[1] = 1;
	for (int i = 2; i <= n; i++)
		inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;

	dfs(1);

	for (int i = 1; i <= m; i++)
		print(ans[i], '\n');

	return 0;
}