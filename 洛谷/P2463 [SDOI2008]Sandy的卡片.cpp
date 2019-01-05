// luogu-judger-enable-o2
// =================================
//   author: memset0
//   date: 2018.12.30 15:45:07
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

const int N = 1e3 + 10, M = 1e6 + 10;
int t, n, siz, top, max, cnt, ans, m[N], a[N], stk[N];
int s[M], bln[M], rnk[M], tax[M], sa[M], tmp[M], height[M];
bool vis[N];
	
void SA_sort() {
	for (int i = 1; i <= siz; i++) tax[i] = 0;
	for (int i = 1; i <= n; i++) ++tax[rnk[i]];
	for (int i = 1; i <= siz; i++) tax[i] += tax[i - 1];
	for (int i = n; i >= 1; i--) sa[tax[rnk[tmp[i]]]--] = tmp[i];
}
 
void SA() {
	for (int i = 1; i <= n; i++) rnk[i] = s[i], tmp[i] = i;
	SA_sort();
	for (int len = 1, cnt = 0; cnt < n; len <<= 1, siz = cnt) {
		cnt = 0;
		for (int i = n; i >= n - len + 1; i--) tmp[++cnt] = i;
		for (int i = 1; i <= n; i++) if (sa[i] > len) tmp[++cnt] = sa[i] - len;
		SA_sort(), std::swap(rnk, tmp), rnk[sa[1]] = cnt = 1;
		for (int i = 2; i <= n; i++) rnk[sa[i]] = (tmp[sa[i - 1]] == tmp[sa[i]] && tmp[sa[i - 1] + len] == tmp[sa[i] + len]) ? cnt : ++cnt;
	}
}

void SA_height() {
	for (int i = 1, j, ans = 0; i <= n; i++) {
		j = sa[rnk[i] - 1]; if (ans) --ans;
		while (s[i + ans] == s[j + ans]) ++ans;
		height[rnk[i]] = ans;
	}
}

bool check(int x) {
	// printf("=== check %d ===\n", x);
	while (top) vis[stk[top--]] = 0;
	for (int i = 1; i <= n; i++) {
		if (height[i] < x) {
			while (top) vis[stk[top--]] = 0;
		}
		int belong = bln[sa[i]];
		if (belong && !vis[belong]) {
			vis[belong] = 1;
			stk[++top] = belong;
			if (top == t) return true;
		}
	}
	return false;
}

void main() {
	read(t), siz = 100000, max = 10000;
	for (int i = 1; i <= t; i++) {
		read(m[i]), s[++n] = ++siz, max = std::min(max, m[i] - 1);
		for (int j = 1; j <= m[i]; j++) read(a[j]);
		for (int j = 2; j <= m[i]; j++) s[++n] = a[j] - a[j - 1], bln[n] = i;
	}
	SA(), SA_height();
	// for (int i = 1; i <= n; i++) print(s[i], " \n"[i == n]);
	// for (int i = 1; i <= n; i++) print(sa[i], " \n"[i == n]);
	// for (int i = 1; i <= n; i++) print(rnk[i], " \n"[i == n]);
	// for (int i = 1; i <= n; i++) print(bln[i], " \n"[i == n]);
	// for (int i = 1; i <= n; i++) print(height[i], " \n"[i == n]);
	// for (int i = 1; i <= n; i++) printf("%d %d\n", bln[i], height[rnk[i]]);
	for (int l = 0, r = max, mid; l <= r; )
		if (check(mid = ((l + r) >> 1))) ans = mid, l = mid + 1;
		else r = mid - 1;
	print(ans + 1, '\n');
}

} signed main() { return ringo::main(), 0; }