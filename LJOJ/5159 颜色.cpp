// =================================
//   author: memset0
//   date: 2018.12.25 12:02:14
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
#pragma GCC target("avx")
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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

const int N = 1e5 + 10, M = 59, L = 8;
int n, m, l, r, p, sqn, cnt, p_flag, lastans;
int a[N], bln[N], fst[M + 10], id[M + 10][M + 10];
std::bitset <N> ans, f[478];

void main() {
	read(n), read(m), read(p_flag), sqn = n / M + 1;
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int i = 1; i <= n; i++) {
		bln[i] = (i - 1) / sqn + 1;
		if (!fst[bln[i]]) fst[bln[i]] = i;
	}
	fst[bln[n] + 1] = n + 1;
	for (int i = 1; i <= bln[n]; i++) {
		for (int j = i; j < i + L && j <= bln[n]; j++)
			id[i][j] = cnt++;
		for (int j = fst[i]; j < fst[i + 1]; j++)
			f[id[i][i]].set(a[j]);
	}
	for (int i = 1; i <= bln[n]; i++)
		for (int j = i + 1; j < i + L && j <= bln[n]; j++)
			f[id[i][j]] = f[id[i][j - 1]] | f[id[j][j]];
	for (int i = 1; i <= m; i++) {
		ans.reset(), read(p);
		for (int j = 1; j <= p; j++) {
			read(l), read(r);
			if (p_flag && i != 1) {
				l = (l ^ lastans) % n + 1;
				r = (r ^ lastans) % n + 1;
				if (l > r) std::swap(l, r);
			}
			if (bln[l] == bln[r]) {
				for (int i = l; i <= r; i++) ans.set(a[i]);
			} else {
				for (int i = l; i < fst[bln[l] + 1]; i++) ans.set(a[i]);
				for (int i = fst[bln[r]]; i <= r; i++) ans.set(a[i]);
				int bl = bln[l] + 1, br = bln[r] - 1;
				while (bl + L - 1 <= br) ans |= f[id[bl][bl + L - 1]], bl += L;
				if (bl <= br) ans |= f[id[bl][br]];
			}
		}
		print(lastans = ans.count(), '\n');
	}
}

} signed main() { return ringo::main(), 0; }
