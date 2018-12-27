// =================================
//   author: memset0
//   date: 2018.12.27 18:54:43
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
#define pb push_back
#define walk(i, u, v) for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
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

const int N = 1e5 + 10;
int T, n, root, full_size;
int vis[N], siz[N], map[N], bkt[N], maxp[N];
int tot = 2, hed[N], to[N << 1], nxt[N << 1], val[N << 1];
ll ans;
std::vector <int> rub, spl[N];

struct info {
	int u, val, cnt;
};
std::vector <info> vet;

inline void add(int u, int v, int w) {
	nxt[tot] = hed[u], to[tot] = v, val[tot] = w, hed[u] = tot++;
	nxt[tot] = hed[v], to[tot] = u, val[tot] = w, hed[v] = tot++;
}

inline void split(int x) {
	if (spl[x].size()) return;
	auto &p = spl[x];
	for (int i = 1; i * i <= x; i++)
		if (x % i == 0) {
			p.pb(i);
			if (i * i != x) p.pb(x / i);
		}
}

void get_root(int u, int father) {
	siz[u] = 1, maxp[u] = 0;
	walk(i, u, v) if (!vis[v] && v != father)
		get_root(v, u), siz[u] += siz[v], maxd(maxp[u], siz[v]);
	maxd(maxp[u], full_size - siz[u]);
	if (maxp[u] < maxp[root]) root = u;
}

void get_dis(int u, int father, int gcd, int cnt) {
	maxd(ans, (ll)gcd * cnt);
	// printf("get dis %d %d %d %d\n", u, father, gcd, cnt);
	vet.pb((info){u, gcd, cnt});
	walk(i, u, v) if (!vis[v] && v != father)
		get_dis(v, u, std::__gcd(gcd, val[i]), cnt + 1);
}

void solve(int u) {
	// printf("=== solve %d ===\n", u);
	vis[u] = 1;
	walk(i, u, v) if (!vis[v]) {
		get_dis(v, u, val[i], 1);
		for (info it : vet) split(it.val);
		for (info it : vet)
			for (int i : spl[it.val]) {
				// printf(">> %d %d %d\n", i, it.cnt, bkt[i]);
				maxd(ans, (ll)i * (it.cnt + bkt[i]));
			}
		for (info it : vet)
			for (int i : spl[it.val])
				maxd(bkt[i], it.cnt), rub.pb(i);
		vet.clear();
	}
	for (int i : rub) bkt[i] = 0;
	rub.clear();
	walk(i, u, v) if (!vis[v])
		root = 0, full_size = maxp[0] = siz[v], get_root(v, u), solve(root);
}

void main() {
	for (read(T); T--; ) {
		tot = 2, ans = 0;
		memset(vis, 0, sizeof(vis));
		memset(hed, 0, sizeof(hed));
		read(n);
		for (int i = 1, u, v, w; i < n; i++) read(u), read(v), read(w), add(u, v, w);
		root = 0, full_size = maxp[0] = n, get_root(1, 0), solve(root);
		print(ans, '\n');
	}
}

} signed main() { return ringo::main(), 0; }
