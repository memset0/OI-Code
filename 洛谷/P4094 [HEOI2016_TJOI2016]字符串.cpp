// luogu-judger-enable-o2
// =================================
//   author: memset0
//   date: 2019.01.04 08:29:48
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
#define ll long long
namespace ringo {
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
template <class T> inline void print(T x, char c) { print(x), putchar(c); }

const int N = 2e5 + 10;
int n, m, a, b, c, d, ans, siz, len, cnt;
int rt[N], sa[N], rnk[N], log[N], height[N], tax[N], tmp[N], st[N][20];
char s[N];

struct node {
	int lc, rc, sum;
} p[N * 30];

inline int ask(int l, int r) {
	int t = log[r - l + 1];
	// printf("ask %d %d => %d\n", l, r, std::min(st[l][t], st[r - (1 << t) + 1][t]));
	return std::min(st[l][t], st[r - (1 << t) + 1][t]); 
}

void SA_sort() {
	for (int i = 1; i <= siz; i++) tax[i] = 0;
	for (int i = 1; i <= len; i++) tax[rnk[i]]++;
	for (int i = 1; i <= siz; i++) tax[i] += tax[i - 1];
	for (int i = len; i >= 1; i--) sa[tax[rnk[tmp[i]]]--] = tmp[i];
}

void SA() {
	len = n, siz = 300;
	for (int i = 1; i <= len; i++) rnk[i] = s[i], tmp[i] = i;
	SA_sort();
	for (int now = 1, cnt = 0; cnt < len; siz = cnt, now <<= 1) {
		cnt = 0;
		for (int i = len; i >= len - now + 1; i--) tmp[++cnt] = i;
		for (int i = 1; i <= len; i++) if (sa[i] > now) tmp[++cnt] = sa[i] - now;
		SA_sort(), std::swap(rnk, tmp), rnk[sa[1]] = cnt = 1;
		for (int i = 2; i <= len; i++) rnk[sa[i]] = (tmp[sa[i]] == tmp[sa[i - 1]] && tmp[sa[i] + now] == tmp[sa[i - 1] + now]) ? cnt : ++cnt;
	}
	for (int i = 1, j, ans = 0; i <= len; i++) {
		j = sa[rnk[i] - 1]; if (ans) --ans;
		while (s[i + ans] == s[j + ans]) ++ans;
		height[rnk[i]] = ans;
	}
	for (int i = 1; i <= len; i++) st[i][0] = height[i];
	for (int i = 1; i < 20; i++)
		for (int j = 1; j + (1 << i) - 1 <= len; j++)
			st[j][i] = std::min(st[j][i - 1], st[j + (1 << (i - 1))][i - 1]);
}

void seg_build(int &u, int l, int r) {
	u = ++cnt;
	if (l == r) return;
	int mid = (l + r) >> 1;
	seg_build(p[u].lc, l, mid);
	seg_build(p[u].rc, mid + 1, r);
}

void seg_modify(int &u, int v, int k, int l = 1, int r = n) {
	p[u = ++cnt] = p[v];
	if (l == r) return (void)(++p[u].sum);
	int mid = (l + r) >> 1;
	if (k <= mid) seg_modify(p[u].lc, p[v].lc, k, l, mid);
	else seg_modify(p[u].rc, p[v].rc, k, mid + 1, r);
	p[u].sum = p[p[u].lc].sum + p[p[u].rc].sum;
}

bool seg_query(int u, int v, int ql, int qr, int l = 1, int r = n) {
	if (ql == l && qr == r) return p[u].sum - p[v].sum;
	int mid = (l + r) >> 1;
	if (qr <= mid) return seg_query(p[u].lc, p[v].lc, ql, qr, l, mid);
	if (ql > mid) return seg_query(p[u].rc, p[v].rc, ql, qr, mid + 1, r);
	if (seg_query(p[u].lc, p[v].lc, ql, mid, l, mid)) return true;
	return seg_query(p[u].rc, p[v].rc, mid + 1, qr, mid + 1, r);
}

bool check(int x) {
	int pos = rnk[c], lans = pos, rans = pos;
	for (int l = 1, r = pos - 1, mid; l <= r; )
		if (ask((mid = l + r >> 1) + 1, pos) >= x) lans = mid, r = mid - 1;
		else l = mid + 1;
	for (int l = pos + 1, r = n, mid; l <= r; )
		if (ask(pos + 1, (mid = l + r >> 1)) >= x) rans = mid, l = mid + 1;
		else r = mid - 1;
	// printf("> check %d => %d %d\n", x, lans, rans);
	return seg_query(rt[b - x + 1], rt[a - 1], lans, rans);
}

void main() {
	read(n), read(m), scanf("%s", s + 1), SA(), log[0] = -1;
	for (int i = 1; i <= n; i++) log[i] = log[i >> 1] + 1;
	seg_build(rt[0], 1, n);
	for (int i = 1; i <= n; i++)
		seg_modify(rt[i], rt[i - 1], rnk[i]);
	for (int i = 1; i <= m; i++) {
		read(a), read(b), read(c), read(d), ans = 0;
		for (int l = 1, r = std::min(b - a + 1, d - c + 1), mid; l <= r; )
			if (check(mid = l + r >> 1)) ans = mid, l = mid + 1;
			else r = mid - 1;
		print(ans, '\n');
	}
}

} signed main() { return ringo::main(), 0; }