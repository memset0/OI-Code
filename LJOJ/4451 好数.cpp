	#include <bits/stdc++.h>
	#define ll long long
	using namespace std;
	int read() {
		int x = 0; bool m = 0; char c = getchar();
		while (!isdigit(c) && c != '-') c = getchar();
		if (c == '-') m = 1, c = getchar();
		while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
		if (m) return -x; else return x;
	}
	
	const int maxn = 100010;
	int n, m, l, r, x, opt, a[maxn], pr[maxn];
	bool f[1000001];
	struct Tree {
		int l, r, mid, cnt, max;
	} p[maxn << 3];
	
	void init(int N) {
		for (int i = 1; i <= N; i++)
			f[i] = 1;
		for (int i = 2; i <= N; i++) {
			if (f[i]) pr[++pr[0]] = i;
			for (int j = 1; j <= pr[pr[0]] && i * pr[j] <= N; j++) {
				f[i * pr[j]] = 0;
				if (i % pr[j] == 0) break;
			}
		}
		for (int i = 1; i <= N; i <<= 1)
			f[i] = 1;
		f[0] = f[1] = f[6] = 1;
	}
	
	void build(int u, int l, int r) {
	//	printf("BUILD %d %d %d\n", u, l, r);
		p[u].l = l, p[u].r = r, p[u].mid = (l + r) >> 1;
		if (l == r) {
			p[u].max = a[l];
			p[u].cnt = f[a[l]];
			return;
		}
		build(u << 1, l, p[u].mid);
		build(u << 1 | 1, p[u].mid + 1, r);
		p[u].cnt = p[u << 1].cnt + p[u << 1 | 1].cnt;
		p[u].max = max(p[u << 1].max, p[u << 1 | 1].max);
	}
	int query(int u, int l, int r) {
	//	printf("QUERY %d %d %d\n", u, l, r);
		if (p[u].l == l && p[u].r == r) return p[u].cnt;
		if (r <= p[u].mid) return query(u << 1, l, r);
		else if (l > p[u].mid) return query(u << 1 | 1, l, r);
		else return (query(u << 1, l, p[u].mid) + query(u << 1 | 1, p[u].mid + 1, r));
	}
	void update(int u, int k, int x) {
	//	printf("UPDATE %d %d %d %d %d\n", u, k, p[u].l, p[u].r, x);
		if (p[u].l == k && p[u].r == k) {
			p[u].max = x;
			p[u].cnt = f[x];
			return;
		}
		if (k <= p[u].mid) update(u << 1, k, x);
		else if (k > p[u].mid) update(u << 1 | 1, k, x);
		p[u].cnt = p[u << 1].cnt + p[u << 1 | 1].cnt;
		p[u].max = max(p[u << 1].max, p[u << 1 | 1].max);
	}
	void modify(int u, int l, int r, int x) {
	//	printf("MODIFY %d %d %d %d\n", u, l, r, x);
		if (p[u].l == l && p[u].r == r && x > p[u].max)
			return;
		if (p[u].l == p[u].r) {
			p[u].max = p[u].max % x;
			p[u].cnt = f[p[u].max];
			return ;
		}
		if (r <= p[u].mid) modify(u << 1, l, r, x);
		else if (l > p[u].mid) modify(u << 1 | 1, l, r, x);
		else modify(u << 1, l, p[u].mid, x), modify(u << 1 | 1, p[u].mid + 1, r, x);
		p[u].cnt = p[u << 1].cnt + p[u << 1 | 1].cnt;
		p[u].max = max(p[u << 1].max, p[u << 1 | 1].max);
	}
	
	int main() {
		n = read(), m = read();
		for (int i = 1; i <= n; i++)
			a[i] = read();
		init(1000000);
		build(1, 1, n);
	//	for (int u = 1; u <= (n << 2); u++)
	//		if (p[u].mid)
	//			printf(">>> %d %d %d %d\n", u, p[u].l, p[u].r, p[u].cnt);
		for (int i = 1; i <= m; i++) {
			opt = read();
			if (opt == 1) {
				l = read(), r = read();
	//			printf(">>> %d %d %d\n", opt, l, r);
				printf("%d\n", query(1, l, r));
			} else if (opt == 2) {
				l = read(), r = read(), x = read();
	//			printf(">>> %d %d %d %d\n", opt, l , r, x);
				modify(1, l, r, x);
			} else if (opt == 3) {
				l = read(), x = read();
	//			printf(">>> %d %d %d\n", opt, l, x);
				update(1, l, x);
			}
		}
		return 0;
	}
