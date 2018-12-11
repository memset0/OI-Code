// =================================
//   author: memset0
//   date: 2018.12.11 08:35:07
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
#define pb push_back
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

const int N = 1e5 + 10, M = 1e3 + 10, inf = 1e9;
int n, m, p, k, v, w, op;
int a[N], b[N], f[N];

struct query {
	int op, k, v;
} q[N];

inline void maxd(int &a, int b) { if (b > a) a = b; }

namespace S1 {
	void main(int n, int p) {
		int m = 0;
		for (int i = 1; i <= p; i++) {
			if (q[i].op == 1) {
				k = q[i].k, v = q[i].v, v -= i;
				a[k] = v, b[++m] = k;
			} else {
				k = q[i].k;
				std::swap(b[k], b[m]), --m;
			}
			if (m == 0) {
				print(0, '\n');
				continue;
			}
			std::sort(b + 1, b + m + 1);
			for (int i = 1; i <= m; i++) f[i] = inf;
			for (int i = 1; i <= m; i++)
				*std::lower_bound(f + 1, f + m + 1, a[b[i]]) = a[b[i]];
			print(std::lower_bound(f + 1, f + m + 1, inf) - f - 1, '\n');
		}
	}
}

namespace S2 {
	const int L = 15;
	int newv[N], que[L], tmp[L];
	std::set < int > set;
	std::set < int > ::iterator it;
	std::multiset < int > ans;

	void modify(int k, int w) {
		f[k] += w;
	}

	int query(int l, int r, int w) {
		int ans = 0;
		for (int i = l; i <= r; i++)
			if (a[i] > w) maxd(ans, f[i]);
		return ans;
	}

	void update(int i) {
		// printf("--- update %d ---\n", i);
		int k = q[i].k, w = newv[i], now = query(k + 1, n, w) + 1;
		// printf("> %d %d %d\n", k, w, now);
		if (now != f[k]) {
			ans.erase(ans.find(f[k]));
			modify(k, now - f[k]), f[k] = now;
			ans.insert(f[k]);
		}
	}

	void init() {
		static int tn = 0;
		for (int i = 1; i <= n; i++) ans.insert(0);
		for (int i = 1; i <= m; i++) if (q[i].op == 1)
			b[++tn] = q[i].k;
		std::sort(b + 1, b + tn + 1);
		tn = std::unique(b + 1, b + tn + 1) - b - 1;
		for (int i = 1; i <= m; i++) if (q[i].op == 1)
			q[i].k = std::lower_bound(b + 1, b + tn + 1, q[i].k) - b;
		tn = 0;
		for (int i = 1; i <= m; i++) if (q[i].op == 1)
			b[++tn] = q[i].v - i;
		std::sort(b + 1, b + tn + 1);
		tn = std::unique(b + 1, b + tn + 1) - b - 1;
		for (int i = 1; i <= m; i++) if (q[i].op == 1)
			a[q[i].k] = newv[i] = std::lower_bound(b + 1, b + tn + 1, q[i].v - i) - b;
	}

	void main(int n, int m) {
		init();
		for (int i = 1; i <= m; i++) {
			// if (q[i].op == 1) printf(">>> %d %d %d %d\n", q[i].op, q[i].k, q[i].v, newv[i]);
			// else printf(">>> %d %d\n", q[i].op, q[i].k);
			if (q[i].op == 1) {
				k = q[i].k, v = q[i].v;
				que[v] = i;
				for (int i = v; i >= 1; i--)
					if (que[i] && ~a[que[i]])
						update(que[i]);
				set.insert(k);
			} else {
				k = q[i].k;
				it = set.begin();
				for (int i = 1; i <= k; i++)
					tmp[i] = *it++;
				set.erase(tmp[k]);
				ans.erase(ans.find(f[tmp[k]]));
				modify(tmp[k], -f[tmp[k]]);
				f[tmp[k]] = 0, a[tmp[k]] = -1;
				ans.insert(0);
				for (int i = k - 1; i >= 1; i--)
					update(tmp[i]);
			}
			for (int i = 10; i >= 1; i--)
				que[i] = que[i - 1];
			// for (int i = 1; i <= n; i++)
			// 	print(f[i], " \n"[i == n]);
			// for (auto i : ans) print(i, ' '); puts("");
			print(*ans.rbegin(), '\n');
		}
	}
}

void main() {
	read(n), read(m);
	for (int i = 1; i <= m; i++) {
		read(q[i].op), read(q[i].k);
		if (q[i].op == 1) read(q[i].v);
	}
	int max = 0, cnt = 0;
	for (int i = 1; i <= m; i++) {
		cnt += (q[i].op == 1 ? 1 : -1);
		maxd(max, cnt);
	}
	if (max <= 1000) return S1::main(n, m);
}

} signed main() { return ringo::main(), 0; }