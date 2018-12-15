// =================================
//   author: memset0
//   date: 2018.12.14 09:48:30
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
namespace ringo {
typedef long long ll;

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

const int N = 3e3 + 10;
int n, t, u, v, l, r;
int a[N], b[N], c[N], d[N], f[N], dis[110][110];
int way, wnt, oldv, newv, ansv, chance;

inline int move(int u, int v) {
	if (n <= 100) return dis[u][v];
	else {
		if (u < v) return b[u] + a[v] + (v - u) * t;
		return d[u] + c[v] + (u - v) * t;
	}
}

inline int calc() {
	way = 1; int sum = 0;
	for (int i = 1; i <= n + 1; i++)
		sum += move(f[i - 1], f[i]);
	return sum;
}

inline int swap(int l, int r) {
	int ret = 0;
	// printf(">> swap %d %d\n", l, r);
	if (l + 1 == r) {
		ret -= move(f[l - 1], f[l]) + move(f[l], f[r]) + move(f[r], f[r + 1]);
		std::swap(f[l], f[r]);
		ret += move(f[l - 1], f[l]) + move(f[l], f[r]) + move(f[r], f[r + 1]);
	} else {
		ret -= move(f[l - 1], f[l]) + move(f[l], f[l + 1]);
		ret -= move(f[r - 1], f[r]) + move(f[r], f[r + 1]);
		std::swap(f[l], f[r]);
		ret += move(f[l - 1], f[l]) + move(f[l], f[l + 1]);
		ret += move(f[r - 1], f[r]) + move(f[r], f[r + 1]);
	}
	return ret;
}

void sa() {
	oldv = calc();
	for (register double temp = 2e4; temp >= 1e-15; temp *= 0.9999) {
		l = rand() % n + 1, r = rand() % n + 1;
		if (l == r) continue;
		if (l > r) std::swap(l, r);
		newv = oldv + swap(l, r);
		// std::swap(f[l], f[r]), newv = calc();
		mind(ansv, newv);
		if (newv < oldv) {
			oldv = newv;
		} else if (exp((oldv - newv) / temp) * RAND_MAX > rand()) {
			oldv = newv;
		} else {
			std::swap(f[l], f[r]);
		}
		// printf("%d %d %lf %lf\n", oldv, newv, temp, exp((oldv - newv) / temp));
		// for (int i = 1; i <= n; i++) print(f[i], " \n"[i == n]);
	}
	mind(ansv, oldv);
}

void main() {
	srand(20040725);
	read(n), read(t);
	for (int i = 1; i <= n; i++)
		read(a[i]), read(b[i]), read(c[i]), read(d[i]);
	if (n <= 100) {
		for (int i = 0; i <= n + 1; i++) {
			for (int j = 0; j < i; j++)
				dis[i][j] = d[i] + c[j] + (i - j) * t;
			dis[i][i] = 0;
			for (int j = i + 1; j <= n + 1; j++)
				dis[i][j] = b[i] + a[j] + (j - i) * t;
		}
		for (int k = 0; k <= n + 1; k++)
			for (int i = 0; i <= n + 1; i++)
				for (int j = 0; j <= n + 1; j++)
					mind(dis[i][j], dis[i][k] + dis[k][j]);
	}
	for (int i = 0; i <= n + 1; i++) f[i] = i;
	ansv = calc();
	sa();
	for (int i = 1; i <= 6; i++) {
		sa();
	}
	print(ansv, '\n');
}

} signed main() { return ringo::main(), 0; }	