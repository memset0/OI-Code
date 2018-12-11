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
	int limit, que[L], tmp[L];
	std::set < int > set;
	std::set < int > ::iterator it;
	std::multiset < int > ans;

	void modify(int &u, int k, int w, int l, int r) {
		if (!u) u = ++cnt; maxd(max[u], w;
		int mid = (l + r) >> 1;
		if (k <= mid) modify(lc[u], k, w, l, mid);
		else modify(rc[u], k, w, mid + 1, r);
	}

	int query(int u, int ql, int qr, int l, int r) {
		if (!u) return 0;
		if (ql == l && qr == r) return sum[u];
		int mid = (l + r) >> 1;
		if (qr <= mid) return query(lc[u], ql, qr, l, mid);
		else if (ql > mid) return query(rc[u], ql, qr, mid + 1, r);
		else return query(lc[u], ql, mid, l, mid + 1) +
			query(rc[u], mid + 1, qr, mid + 1, r);
	}

	void modify(int k, int w) {
		k = limit - k + 1;
		for (int i = k; i <= n; i += i & -i)
			modify(rt[i], a[k], w, l, r);
	}

	int query(int k, int w) {
		k = limit - k + 1;

	}

	void update(int k) {
		// printf("--- update %d ---\n", k);
		int now = query(k + 1, a[k]) + 1;
		if (now != f[k]) {
			ans.erase(ans.find(f[k]));
			modify(k, now - f[k]), f[k] = now;
			ans.insert(f[k]);
		}
	}

	void init() {
		static int tn = 0;
		for (int i = 1; i <= m; i++) if (q[i].op == 1)
			b[++tn] = q[i].k;
		std::sort(b + 1, b + tn + 1);
		tn = std::unique(b + 1, b + tn + 1) - b - 1;
		for (int i = 1; i <= m; i++) if (q[i].op == 1)
			q[i].k = std::lower_bound(b + 1, b + tn + 1, q[i].k) - b;
		limit = tn, tn = 0;
		for (int i = 1; i <= m; i++) if (q[i].op == 1)
			b[++tn] = q[i].v - i;
		std::sort(b + 1, b + tn + 1);
		tn = std::unique(b + 1, b + tn + 1) - b - 1;
		for (int i = 1; i <= m; i++) if (q[i].op == 1)
			a[q[i].k] = std::lower_bound(b + 1, b + tn + 1, q[i].v - i) - b;
		for (int i = 1; i <= limit; i++) ans.insert(0);
	}

	void main(int n, int m) {
		init();
		for (int i = 1; i <= m; i++) {
			// if (q[i].op == 1) printf(">>> %d %d %d %d\n", q[i].op, q[i].k, q[i].v, a[q[i].k]);
			// else printf(">>> %d %d\n", q[i].op, q[i].k);
			if (q[i].op == 1) {
				k = q[i].k, v = q[i].v, que[v] = i;
				for (int i = v; i >= 1; i--)
					if (que[i] && ~a[q[que[i]].k])
						update(q[que[i]].k);
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
			// for (int i = 1; i <= limit; i++) print(a[i], " \n"[i == limit]);
			// for (int i = 1; i <= limit; i++) print(f[i], " \n"[i == limit]);
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
	// if (max <= 1000) return S1::main(n, m);
	S2::main(n, m);
}

} signed main() { return ringo::main(), 0; }