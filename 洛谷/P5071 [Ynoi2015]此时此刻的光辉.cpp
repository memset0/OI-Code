// luogu-judger-enable-o2
// =================================
//   author: memset0
//   date: 2018.12.09 20:57:04
//   website: https://memset0.cn/
//   problem: 5071 [Ynoi2015]此时此刻的光辉
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

const int N = 1e5 + 10, M = sqrt(1e9) + 10, L = 300, p = 19260817;
int n, m, ul, ur, ql, qr, now = 1, pos, max, sqn, limit;
int a[N], b[N], c[N], ans[N], bln[N], pri[N << 1], lazy[N], cnt[N << 1];
bool vis[M];
std::map < int, int > map;
int inv[N * 20], sum[N][L + 1];

struct pair {
	int first, second;
	pair () {}
	pair (int _first, int _second) { first = _first, second = _second; }
};
std::vector < pair > v[N];

struct query {
	int l, r, i;
	inline bool operator < (const query &other) const {
		if (bln[l] == bln[other.l]) return bln[l] & 1 ? r > other.r : r < other.r;
		return l < other.l;
	}
} q[N];

inline void push_back(int k, int first, int second) {
	// printf("%d(%d) > %d\n", first, pri[first], second);
	if (first <= L) sum[k][first] += second;
	else v[k].push_back(pair(first, second));
}

inline void pre(int a, int k) {
	int cnt = 0;
	for (int i = 1; pri[i] * pri[i] <= a && i <= pri[0]; i++)
		if (!(a % pri[i])) {
			cnt = 0;
			while (!(a % pri[i])) ++cnt, a /= pri[i];
			push_back(k, i, cnt);
		}
	if (a != 1) {
		auto it = map.find(a);
		if (it == map.end()) map[a] = ++pos, pri[pos] = a, a = pos;
		else a = it->second;
		push_back(k, a, 1);
	}
}

inline void add(int x) {
	for (auto u : v[x]) {
		now = (ll)now * inv[cnt[u.first] % p] % p;
		cnt[u.first] += u.second;
		now = (ll)now * cnt[u.first] % p;
	}
}

inline void del(int x) {
	for (auto u : v[x]) {
		now = (ll)now * inv[cnt[u.first] % p] % p;
		cnt[u.first] -= u.second;
		now = (ll)now * cnt[u.first] % p;
	}
}

void main() {
	read(n), read(m), sqn = n / sqrt(m * 2.0 / 3);
	for (int i = 1; i <= n; i++) {
		read(a[i]), b[i] = a[i];
		max = std::max(max, a[i]);
		bln[i] = (i - 1) / sqn;
	}
	std::sort(b + 1, b + n + 1);
	int tn = std::unique(b + 1, b + n + 1) - b - 1;
	for (int i = 1; i <= n; i++)
		c[i] = std::lower_bound(b + 1, b + tn + 1, a[i]) - b;
 	limit = sqrt(max);
	for (int i = 2; i <= limit; i++) {
		if (!vis[i]) pri[++pri[0]] = i, map[i] = pri[0];
		for (int j = 1; j <= pri[0] && i * pri[j] <= limit; j++) {
			vis[i * pri[j]] = 1;
			if (i % pri[j] == 0) break;
		}
	}
	pos = pri[0], max = 0;
	for (int i = 1; i <= n; i++) {
		// printf("--- %d %d ---\n", i, a[i]);
		for (int j = 1; j <= L; j++) sum[i][j] = sum[i - 1][j];
		pre(a[i], i);
		for (auto u : v[i]) cnt[u.first] += u.second;
	}
	for (int i = 1; i <= pos; i++) max = std::max(max, cnt[i]);
	inv[0] = inv[1] = 1, limit = max + 1;
	for (int i = 2; i <= std::min(limit, p - 1); i++) inv[i] = (ll)(p - p / i) * inv[p % i] % p;
	for (int i = 1; i <= pos; i++) cnt[i] = 1;
	for (int i = 1; i <= m; i++) read(q[i].l), read(q[i].r), q[i].i = i;
	std::sort(q + 1, q + m + 1);
	ul = 1, ur = 0;
	for (int i = 1; i <= m; i++) {
		ql = q[i].l, qr = q[i].r;
		while (ul > ql) add(--ul);
		while (ur < qr) add(++ur);
		while (ul < ql) del(ul++);
		while (ur > qr) del(ur--);
		ans[q[i].i] = now;
		// printf("==== [%d] %d %d -> %d ===\n", q[i].i, ql, qr, now);
		for (int j = 1; j <= L; j++) {
			ans[q[i].i] = (ll)ans[q[i].i] * (sum[qr][j] - sum[ql - 1][j] + 1) % p;
			// if (sum[qr][j] - sum[ql - 1][j]) printf("%d %d\n", j, sum[qr][j] - sum[ql - 1][j]);
		}
		// printf(">> %d\n", ans[q[i].i]);
	}
	for (int i = 1; i <= m; i++) print(ans[i], '\n');
}

} signed main() { return ringo::main(), 0; }