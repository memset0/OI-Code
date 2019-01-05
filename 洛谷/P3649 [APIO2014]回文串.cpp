// luogu-judger-enable-o2
// =================================
//   author: memset0
//   date: 2019.01.03 20:16:19
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

const int N = 6e5 + 10;
int n, len, siz, max, mid;
ll ans;
int f[N], sa[N], rnk[N], height[N], tmp[N], tax[N], log[N], st[N][20];
char s[N];

void SA_sort() {
	for (int i = 1; i <= siz; i++) tax[i] = 0;
	for (int i = 1; i <= len; i++) tax[rnk[i]]++;
	for (int i = 1; i <= siz; i++) tax[i] += tax[i - 1];
	for (int i = len; i >= 1; i--) sa[tax[rnk[tmp[i]]]--] = tmp[i];
}

void SA() {
	siz = 200, len = n;
	for (int i = 1; i <= len; i++) rnk[i] = s[i], tmp[i] = i;
	SA_sort();
	for (int now = 1, cnt = 0; cnt < len; siz = cnt, now <<= 1) {
		cnt = 0;
		for (int i = len; i >= len - now + 1; i--) tmp[++cnt] = i;
		for (int i = 1; i <= len; i++) if (sa[i] > now) tmp[++cnt] = sa[i] - now;
		SA_sort(), std::swap(rnk, tmp), rnk[sa[1]] = cnt = 1;
		for (int i = 2; i <= len; i++) rnk[sa[i]] = (tmp[sa[i]] == tmp[sa[i - 1]] && tmp[sa[i] + now] == tmp[sa[i - 1] + now]) ? cnt : ++cnt;
	}
	for (int i = 1, j, ans = 0; i <= n; i++) {
		j = sa[rnk[i] - 1]; if (ans) --ans;
		while (s[i + ans] == s[j + ans]) ++ans;
		height[rnk[i]] = ans;
	}
	for (int i = 1; i <= len; i++) st[i][0] = height[i];
	// for (int i = 1; i <= len; i++) print(sa[i], " \n"[i == len]);
	// for (int i = 1; i <= len; i++) print(rnk[i], " \n"[i == len]);
	// for (int i = 1; i <= len; i++) print(height[i], " \n"[i == len]);
	for (int i = 1; i < 20; i++)
		for (int j = 1; j + (1 << i) - 1 <= len; j++)
			st[j][i] = std::min(st[j][i - 1], st[j + (1 << (i - 1))][i - 1]);
}

inline int ask(int l, int r) {
	int t = log[r - l + 1];
	return std::min(st[l][t], st[r - (1 << t) + 1][t]);
}

inline int query(int u, int limit) {
	int lans = rnk[u], rans = rnk[u];
	for (int l = 1, r = rnk[u] - 1, mid; l <= r; )
		if (ask((mid = l + r >> 1) + 1, rnk[u]) >= limit) lans = mid, r = mid - 1;
		else l = mid + 1;
	for (int l = rnk[u] + 1, r = n, mid; l <= r; )
		if (ask(rnk[u] + 1, (mid = l + r >> 1)) >= limit) rans = mid, l = mid + 1;
		else r = mid - 1;
	return rans - lans + 1;
}

void main() {
	scanf("%s", s + 1), n = strlen(s + 1);
	log[0] = -1;
	for (int i = 1; i <= n; i++) log[i] = log[i >> 1] + 1;
	SA();
	for (int i = n; i >= 1; i--) s[i << 1] = s[i];
	for (int i = 0; i <= n; i++) s[i << 1 | 1] = '#';
	for (int i = 1, lim = n << 1 | 1, left, right, length; i <= lim; i++) {
		f[i] = i <= max ? std::min(f[mid * 2 - i], max - i + 1) : 1;
		while (i + f[i] <= lim && i - f[i] >= 1 && s[i - f[i]] == s[i + f[i]]) {
			if (s[i + f[i]] == '#') {
				left = (i - f[i] + 1) >> 1;
				right = (i + f[i] - 1) >> 1;
				length = right - left + 1;
				// for (int j = i - f[i]; j <= i + f[i]; j++) putchar(s[j]); puts("");
				int tmp = query(left, length);
				// printf(">> %d %d %d %d\n", left, right, length, tmp);
				ans = std::max(ans, (ll)length * tmp);
			}
			++f[i];
		}
		if (i + f[i] - 1 > max) max = i + f[i] - 1, mid = i;
	}
	// for (int i = 1, lim = n << 1 | 1; i <= lim; i++)
	// 	print(f[i], " \n"[i == lim]);
	print(ans, '\n');
}

} signed main() { return ringo::main(), 0; }