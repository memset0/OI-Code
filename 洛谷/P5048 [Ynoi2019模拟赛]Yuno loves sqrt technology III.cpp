// luogu-judger-enable-o2
// =================================
//   author: memset0
//   date: 2018.12.25 19:46:03
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

const int N = 5e5 + 10, sqn = 610, M = N / sqn + 10;
// const int N = 1e3 + 10, sqn = 15, M = N / sqn + 10;
int n, m, l, r, tn, ans;
int a[N], b[N], id[N], pos[N], cnt[N], fst[M], bln[N], pre[M][M];
std::vector <int> vet[N];

inline bool checkL(int k, int v) {
	if (pos[k] + v - 1 >= (int)vet[a[k]].size()) return false;
	return vet[a[k]][pos[k] + v - 1] <= r;
}

inline bool checkR(int k, int v) {
	// printf("checkR %d %d : %d\n", k, v, pos[k] - v + 1);
	if (pos[k] - v + 1 < 0) return false;
	return vet[a[k]][pos[k] - v + 1] >= l;
}

void main() {
	read(n), read(m);
	for (int i = 1; i <= n; i++) {
		read(a[i]), b[i] = a[i], bln[i] = (i - 1) / sqn + 1;
		if (!fst[bln[i]]) fst[bln[i]] = i;
	}
	std::sort(b + 1, b + n + 1), tn = std::unique(b + 1, b + n + 1) - b - 1;
	for (int i = 1; i <= n; i++) a[i] = std::lower_bound(b + 1, b + tn + 1, a[i]) - b;
	fst[bln[n] + 1] = n + 1;
	for (int l = 1; l <= bln[n]; l++) {
		for (int r = l; r <= bln[n]; r++) {
			for (int i = fst[r]; i < fst[r + 1]; i++) ++cnt[a[i]], maxd(pre[l][r], cnt[a[i]]);
			if (l != r) maxd(pre[l][r], pre[l][r - 1]);
		}
		for (int i = fst[l]; i < fst[bln[n] + 1]; i++) --cnt[a[i]];
	}
	for (int i = 1; i <= n; i++) vet[a[i]].push_back(i), pos[i] = vet[a[i]].size() - 1;
	// for (int i = 1; i <= n; i++) print(pos[i], " \n"[i == n]);
	// for (int i = 1; i <= tn; i++) { printf("=> "); for (int j : vet[i]) print(j, ' '); puts(""); }
	for (int i = 1; i <= m; i++) {
		read(l), read(r), l ^= ans, r ^= ans, ans = 0;
		if (bln[l] == bln[r]) {
			for (int i = l; i <= r; i++) ++cnt[a[i]];
			for (int i = l; i <= r; i++) if (cnt[a[i]] > ans) ans = cnt[a[i]];
			for (int i = l; i <= r; i++) --cnt[a[i]];
		} else {
			if (bln[l] + 1 <= bln[r] - 1) ans = pre[bln[l] + 1][bln[r] - 1];
			// printf("%d %d %d %d %d\n", l, r, bln[l], bln[r], ans);
			// printf(">>> %d\n", ans);
			for (int i = l; i < fst[bln[l] + 1]; i++)
				while (1) { if (checkL(i, ans + 1)) ++ans; else break; }
			// printf(">>> %d\n", ans);
			for (int i = fst[bln[r]]; i <= r; i++) 
				while (1) { if (checkR(i, ans + 1)) ++ans; else break; }
			// printf(">>> %d\n", ans);
		}
		print(ans, '\n');
	}
}

} signed main() { return ringo::main(), 0; }