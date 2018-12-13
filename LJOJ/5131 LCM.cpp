// =================================
//   author: memset0
//   date: 2018.12.11 18:03:31
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
namespace ringo {
typedef long long ll;

template < class T >
inline void read(T &x) {
	x = 0; register char c = getchar(); register bool f = 0;
	while (!isdigit(c)) f ^= c == '-', c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (f) x = -x;
}

template < class T >
inline void print(T x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) print(x / 10);
	putchar('0' + x % 10);
}

template < class T >
inline void print(T x, char c) {
	print(x), putchar(c);
}

const int N = 2e3 + 10, M = 4330, p = 1e9 + 7;
const int pri[6] = { 2, 3, 5, 7, 11, 13 };
int n, m, cnt, ans, f[M], g[M], t[M], fpow[6][10];

struct status {
	ll val;
	int f[6];
	inline bool operator < (const status &other) const {
		return val < other.val;
	}
	inline int init() {
		ll tmp = val;
		for (int i = 0; i < 6; i++)
			while (tmp % pri[i] == 0)
				++f[i], tmp /= pri[i];
		val /= tmp;
		return tmp;
	}
} s[M];

struct node {
	int max;
	status s;
	inline bool operator < (const node &other) const {
		return max < other.max;
	}
} a[N];

inline ll merge(const status &a, const status &b) {
	ll ans = 1;
	for (int i = 0; i < 6; i++)
		ans = ans * fpow[i][std::max(a.f[i], b.f[i])];
	return ans;
}

inline int find(int l, int r, ll x) {
	int ans = 0;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (s[mid].val <= x) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	return ans;
}

void init() {
	int a, b, c, d, e, f; ll sa, sb, sc, sd, se, sf;
	for (a = 0, sa = 1; a <= 7; a++, sa *= 2)
		for (b = 0, sb = sa; b <= 4; b++, sb *= 3)
			for (c = 0, sc = sb; c <= 3; c++, sc *= 5)
				for (d = 0, sd = sc; d <= 2; d++, sd *= 7)
					for (e = 0, se = sd; e <= 2; e++, se *= 11)
						for (f = 0, sf = se; f <= 2; f++, sf *= 13) {
							++cnt, s[cnt].val = sf, s[cnt].init();
						}
	for (int i = 0, s = 1; i < 6; i++, s = 1)
		for (int j = 0; s <= 200; j++)
			fpow[i][j] = s, s *= pri[i];
}

void print(char c, int *f) {
	printf("--- %c ---\n", c	);
	for (int j = 1; j <= cnt; j++)
		if (f[j]) {
			printf("%d => %lld ", f[j], s[j].val);
			for (int k = 0; k < 6; k++)
				print(s[j].f[k], ' ');
			putchar('\n');
		}
}

void main() {
	init(), read(n);
	for (int i = 1; i <= n; i++) {
		read(a[i].s.val);
		a[i].max = a[i].s.init();
	}
	std::sort(a + 1, a + n + 1);
	std::sort(s + 1, s + cnt + 1);
	f[1] = 1;
	for (int l = 1, r; l <= n; l = r) {
		for (r = l + 1; r <= n && a[l].max == a[r].max; ++r);
		memset(g, 0, sizeof(g));
		memset(t, 0, sizeof(t));
		for (int i = l; i < r; i++) {
			// printf("=== %d ===\n", i);
			for (int u = cnt, v; u >= 1; u--) {
				v = find(u, cnt, merge(s[u], a[i].s));
				// if (f[u]) printf("F : %d -> %d\n", u, v);
				// if (t[u]) printf("T : %d -> %d\n", u, v);
				g[v] = (g[v] + (ll)(f[u] + t[u]) % p * a[i].max) % p;
				t[v] = (t[v] + (ll)(f[u] + t[u])) % p;
			}
			// print('f', f);
			// print('g', g);
			// print('t', t);
		}
		for (int j = 1; j <= cnt; j++)
			f[j] = (f[j] + g[j]) % p;
	}
	// print('f', f);
	// for (int i = 1; i <= n; i++) {
	// 	printf("%d %lld > ", a[i].max, a[i].s.val);
	// 	for (int j = 0; j < 6; j++)
	// 		print(a[i].s.f[j], ' ');
	// 	putchar('\n');
	// }
	for (int i = 1; i <= cnt; i++) 
		ans = (ans + (ll)s[i].val % p * f[i]) % p;
	print(ans - 1, '\n');
}

} signed main() { return ringo::main(), 0; }
