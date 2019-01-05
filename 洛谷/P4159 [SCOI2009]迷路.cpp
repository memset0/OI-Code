// luogu-judger-enable-o2
// =================================
//   author: memset0
//   date: 2018.12.28 13:21:48
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

const int N = 110;
int n, m, lim;
int a[N][N], id[N][10];

struct matrix {
	int a[N][N];
	matrix () {}
	matrix (int u) { memset(a, u, sizeof(a)); }
	void output() {
		for (int i = 0; i < lim; i++)
			for (int j = 0; j < lim; j++)
				print(a[i][j], " \n"[j == lim - 1]);
	}
} start, base, answer;

inline matrix operator * (const matrix &a, const matrix &b) {
	matrix c(0);
	for (int i = 0; i < lim; i++)
		for (int k = 0; k < lim; k++)
			for (int j = 0; j < lim; j++)
				c.a[i][j] += a.a[i][k] * b.a[k][j];
	for (int i = 0; i < lim; i++)
		for (int j = 0; j < lim; j++)
			c.a[i][j] %= 2009;
	return c;
}

inline matrix fpow(matrix a, int b) {
	matrix s(0);
	for (int i = 0; i < lim; i++) s.a[i][i] = 1;
	for (; b; b >>= 1, a = a * a)
		if (b & 1) s = s * a;
	return s;
}

inline void add(int i, int j) {
	++base.a[i][j];
}

void main() {
	read(n), read(m);
	for (int i = 1, c; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			while (c = getchar(), !isdigit(c));
			a[i][j] = c - '0';
		}
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < 9; j++)
			id[i][j] = lim++;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (a[i][j])
				add(id[i][0], id[j][a[i][j] - 1]);
	for (int i = 1; i <= n; i++)
		for (int j = 8; j; j--)
			add(id[i][j], id[i][j - 1]);
	start.a[0][id[1][0]] = 1;
	answer = start * fpow(base, m);
	print(answer.a[0][id[n][0]], '\n');
}

} signed main() { return ringo::main(), 0; }