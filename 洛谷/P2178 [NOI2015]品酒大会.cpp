// luogu-judger-enable-o2
// =================================
//   author: memset0
//   date: 2018.12.29 12:15:25
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#define pb push_back
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

const int N = 6e5 + 10, int_inf = 1e9 + 7;
const ll ll_inf = 1e18 + 10;
int n, m, limit;
int a[N], sa[N], fa[N], max[N], min[N], siz[N], rnk[N], tax[N], tmp[N], height[N];
ll sum[N], ans[N];
char s[N];

struct info {
	int id, height;
	inline bool operator < (const info &other) const {
		return height > other.height;
	}
} q[N];

void SA_sort() {
	for (int i = 1; i <= m; i++) tax[i] = 0;
	for (int i = 1; i <= n; i++) tax[rnk[i]]++;
	for (int i = 1; i <= m; i++) tax[i] += tax[i - 1];
	for (int i = n; i >= 1; i--) sa[tax[rnk[tmp[i]]]--] = tmp[i];
}

void SA() {
	m = 128;
	for (int i = 1; i <= n; i++) rnk[i] = s[i], tmp[i] = i;
	SA_sort();
	for (int len = 1, cnt = 0; cnt < n; len <<= 1, m = cnt) {
		cnt = 0;
		for (int i = n; i >= n - len + 1; i--) tmp[++cnt] = i;
		for (int i = 1; i <= n; i++) if (sa[i] > len) tmp[++cnt] = sa[i] - len;
		SA_sort(), std::swap(rnk, tmp);
		rnk[sa[1]] = cnt = 1;
		for (int i = 2; i <= n; i++) rnk[sa[i]] = (tmp[sa[i - 1]] == tmp[sa[i]] && tmp[sa[i - 1] + len] == tmp[sa[i] + len]) ? cnt : ++cnt;
	}
}

void SA_height() {
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (ans) ans--;
		int j = sa[rnk[i] - 1];
		while (s[i + ans] == s[j + ans]) ans++;
		height[rnk[i]] = ans;
	}
}

int find(int x) { return fa[x] = x == fa[x] ? x : find(fa[x]); }

void link(int u, int v) {
	// printf("link %d %d\n", u, v);
	int find_u = find(u), find_v = find(v);
	fa[find_u] = find_v;
	maxd(ans[limit], (ll)max[find_u] * max[find_v]);
	maxd(ans[limit], (ll)min[find_u] * min[find_v]);
	maxd(max[find_v], max[find_u]), mind(min[find_v], min[find_u]);
	sum[limit] += (ll)siz[find_u] * siz[find_v], siz[find_v] += siz[find_u];
}

void main() {
	read(n), scanf("%s", s + 1);
	for (int i = 1; i <= n; i++) read(a[i]);
	SA(), SA_height();
	for (int i = 2; i <= n; i++) q[i].height = height[i], q[i].id = i;
	// for (int i = 1; i <= n; i++) print(height[i], " \n"[i == n]);
	std::sort(q + 2, q + n + 1);
	for (int i = 1; i <= n; i++) fa[i] = i, max[i] = min[i] = a[i], siz[i] = 1;
	limit = q[2].height;
	// for (int i = 2; i <= n; i++) printf("[%d %d] ", q[i].height, q[i].id); putchar('\n');
	for (int i = limit + 1; i >= 0; i--) ans[i] = -ll_inf;
	for (int i = 2; i <= n && limit >= 0; limit--) {
		// printf(">>> %d %d %d : %d %d\n", i, q[i].id, q[i].id + 1, sa[q[i].id], sa[q[i].id - 1]);
		while (i <= n && q[i].height >= limit) link(sa[q[i].id], sa[q[i].id - 1]), ++i;
		sum[limit] += sum[limit + 1], ans[limit] = std::max(ans[limit], ans[limit + 1]);
	}
	ans[q[2].height + 1] = 0;
	for (int i = 1; i <= n; i++) print(sum[i - 1], ' '), print(ans[i - 1], '\n');
}

} signed main() { return ringo::main(), 0; }