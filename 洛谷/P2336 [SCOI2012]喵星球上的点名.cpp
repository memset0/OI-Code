// luogu-judger-enable-o2
// =================================
//   author: memset0
//   date: 2019.01.02 12:54:34
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
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

const int N = 1e6 + 8e3 + 10;
int n, m, t, x, ul, ur, ql, qr, now, tim, len, siz, st[N][20];
typedef int array[N];
array s, sa, id, col, tax, ned, tmp, rnk, bln, log, fst, cnt, ans1, ans2, height;
		struct struct_query {
	int l, r, id;
	inline bool operator < (const struct_query &other) const {
		return bln[l] == bln[other.l] ? r < other.r : l < other.l;
	}
} q[N];

inline int query_min(int l, int r) { int t = log[r - l + 1]; return std::min(st[l][t], st[r - (1 << t) + 1][t]); }

void SA_sort() {
	for (int i = 1; i <= siz; i++) tax[i] = 0;
	for (int i = 1; i <= len; i++) tax[rnk[i]]++;
	for (int i = 1; i <= siz; i++) tax[i] += tax[i - 1];
	for (int i = len; i >= 1; i--) sa[tax[rnk[tmp[i]]]--] = tmp[i];
}

void SA() {
	for (int i = 1; i <= len; i++) rnk[i] = s[i], tmp[i] = i;
	SA_sort();
	for (int now = 1, cnt = 0; cnt < len; now <<= 1, siz = cnt) {
		cnt = 0;
		for (int i = len; i >= len - now + 1; i--) tmp[++cnt] = i;
		for (int i = 1; i <= len; i++) if (sa[i] > now) tmp[++cnt] = sa[i] - now;
		SA_sort(), std::swap(rnk, tmp), rnk[sa[1]] = cnt = 1;
		for (int i = 2; i <= len; i++) rnk[sa[i]] = (tmp[sa[i]] == tmp[sa[i - 1]] && tmp[sa[i] + now] == tmp[sa[i - 1] + now]) ? cnt : ++cnt;
	}
	for (int i = 1, j, ans = 0; i <= len; i++) {
		j = sa[rnk[i] - 1]; if (ans) --ans;
		while (s[i + ans] == s[j + ans]) ans++;
		height[rnk[i]] = ans;
	}
}

inline void add(int x) {
	if (!col[x]) return;
	if (!cnt[col[x]]) {
		ans2[col[x]] -= tim;
		++now;
	}
	++cnt[col[x]];
}

inline void del(int x) {
	if (!col[x]) return;
	--cnt[col[x]];
	if (!cnt[col[x]]) {
		ans2[col[x]] += tim;
		--now;
	}
}

void main() {
	read(n), read(m), siz = 1e4;
	for (int i = 1; i <= n; i++) {
		read(t), s[++len] = ++siz;
		for (int j = 1; j <= t; j++) read(x), s[++len] = x, id[len] = i;
		read(t), s[++len] = ++siz;
		for (int j = 1; j <= t; j++) read(x), s[++len] = x, id[len] = i;
	}
	for (int i = 1; i <= m; i++) {
		read(t), s[++len] = ++siz, fst[i] = len + 1, ned[i] = t;
		for (int j = 1; j <= t; j++) read(x), s[++len] = x;
	}
	s[++len] = ++siz, SA(), log[0] = -1;
	for (int i = 1; i <= len; i++) log[i] = log[i >> 1] + 1;
	// for (int i = 1; i <= len; i++) print(s[i], " \n"[i == len]);
	// for (int i = 1; i <= len; i++) print(sa[i], " \n"[i == len]);
	for (int i = 1; i <= len; i++) st[i][0] = height[i];
	for (int i = 1; i < 20; i++)
		for (int j = 1; j + (1 << i) - 1 <= len; j++)
			st[j][i] = std::min(st[j][i - 1], st[j + (1 << (i - 1))][i - 1]);
	// for (int i = 1; i <= len; i++) print(height[i], " \n"[i == len]);
	for (int i = 1, l, r, mid; i <= m; i++) {
		int pos = rnk[fst[i]]; q[i].l = q[i].r = pos;
		for (l = 1, r = pos - 1; l <= r; ) {
			mid = (l + r) >> 1;
			if (query_min(mid + 1, pos) >= ned[i]) q[i].l = mid, r = mid - 1;
			else l = mid + 1;
		}
		for (l = pos + 1, r = len; l <= r; ) {
			mid = (l + r) >> 1;
			if (query_min(pos + 1, mid) >= ned[i]) q[i].r = mid, l = mid + 1;
			else r = mid - 1;
		}
		q[i].id = i;
	}
	// for (int i = 1; i <= m; i++) printf(">> %d %d %d\n", i, q[i].l, q[i].r);
	for (int i = 1; i <= len; i++) col[i] = id[sa[i]];
	std::sort(q + 1, q + m + 1);
	ul = 1, ur = 0;
	for (int i = 1; i <= m; i++) {
		ql = q[i].l, qr = q[i].r;
		++tim;
		while (ul > ql) add(--ul);
		while (ur < qr) add(++ur);
		while (ul < ql) del(ul++);
		while (ur > qr) del(ur--);
		ans1[q[i].id] = now;
	}
	++tim;
	while (ul <= ur) del(ur--);
	for (int i = 1; i <= m; i++) print(ans1[i], '\n');
	for (int i = 1; i <= n; i++) print(ans2[i], " \n"[i == n]);
}

} signed main() { return ringo::main(), 0; }