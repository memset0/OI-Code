#include <bits/stdc++.h>
#define lowbit(x) (x & (-x))
#define M 123456789
using namespace std;

int read(void) {
	int x = 0; char c = getchar(); bool m = 0;
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') c = getchar(), m = 1;
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (m) return -x; else return x;
}

const int maxn = 100010;
int n, type, g[maxn], cnt[maxn];
struct Node {
	int i, v;
} a[maxn];

int Max(int a, int b) {
	if (a > b) return a;
	else return b;
}
bool cmp(Node a, Node b) {
	if (a.v == b.v) return a.i > b.i;
	return a.v < b.v; 
} 

class tree {
	private:
		struct Child {
			int l, r, mid, max, cnt, lmax, lcnt;
		} p[maxn << 3];
	public:
		struct pr {
			int max, cnt;
		};
		void pushup(int u, int max, int cnt) {
			if (max > p[u].lmax) p[u].lmax = max, p[u].lcnt = cnt;
			else if (max == p[u].lmax) p[u].lcnt = (p[u].lcnt + cnt) % M; 
		}
		void pushdown(int u) {
			if (p[u].lmax) {
				if (p[u].lmax > p[u].max) p[u].max = p[u].lmax, p[u].cnt = p[u].lcnt;
				else if (p[u].lmax == p[u].max) p[u].cnt = (p[u].lcnt + p[u].cnt) % M;
				pushup(u << 1, p[u].lmax, p[u].lcnt);
				pushup(u << 1 | 1, p[u].lmax, p[u].lcnt);
				p[u].lmax = p[u].lcnt = 0;
			}
		}
		void create(int u, int l, int r) {
			p[u].l = l, p[u].r = r, p[u].mid = (l + r) >> 1;
			p[u].max = p[u].cnt = 0;
			if (p[u].l == p[u].r) return;
			create(u << 1, l, p[u].mid);
			create(u << 1 | 1, p[u].mid + 1, r);
		}
		void update(int u, int l, int r, int max, int cnt) {
			if (l > r) return ;
//			printf("U u=%d pl=%d pr=%d l=%d r=%d max=%d cnt=%d pmax=%d pcnt=%d\n", u, p[u].l, p[u].r, l, r, max, cnt, p[u].max, p[u].cnt);
			pushdown(u);
			if (l == p[u].l && r == p[u].r) {
				pushup(u, max, cnt);
				return ;
			}
			if (max > p[u].max) p[u].max = max, p[u].cnt = cnt;
			else if (max == p[u].max) p[u].cnt = (p[u].cnt + cnt) % M;
//			else return;
			if (r <= p[u].mid) update(u << 1, l, r, max, cnt);
			else if (l > p[u].mid) update(u << 1 | 1, l, r, max, cnt);
			else {
				update(u << 1, l, p[u].mid, max, cnt);
				update(u << 1 | 1, p[u].mid + 1, r, max, cnt);
			}
		}
		pr query(int u, int l, int r) {
			if (l > r) return (pr){0, 0};
//			printf("Q u=%d pl=%d pr=%d l=%d r=%d max=%d cnt=%d\n", u, p[u].l, p[u].r, l, r, p[u].max, p[u].cnt);
			pushdown(u);
			if (l == p[u].l && r == p[u].r) return (pr){p[u].max, p[u].cnt};
			if (r <= p[u].mid) return query(u << 1, l, r);
			else if (l > p[u].mid) return query(u << 1 | 1, l, r);
			else {
				pr a = query(u << 1, l, p[u].mid);
				pr b = query(u << 1 | 1, p[u].mid + 1, r);
				if (a.max > b.max) return a;
				else if (b.max > a.max) return b;
				else return {a.max, (a.cnt + b.cnt) % M};
			}
		}
		void print() {
			for (int i = 1; i <= n << 3; i++)
				if (p[i].mid)
					printf("p[%d] = {l = %d r = %d mid = %d max = %d cnt = %d lmax = %d lcnt = %d}\n", i, p[i].l, p[i].r, p[i].mid, p[i].max, p[i].cnt, p[i].lmax, p[i].lcnt);
		}
} f;

int main() {
//	freopen("INPUT", "r", stdin);
	
	n = read(), type = read();
	f.create(1, 1, n);
	for (int i = 1; i <= n; i++)
		a[i] = {i, read()};
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n; i++) {
//		printf("=== %d ===\n", i);
		tree::pr ret = f.query(1, a[i].i, a[i].i);
		if (!ret.cnt) ret.cnt = 1;
//		cout << a[i].i << " " << a[i].v << " " << ret.max << " " << ret.cnt << endl;
		f.update(1, a[i].i, n, ret.max + 1, ret.cnt);
//		for (int i = 1; i <= n; i++) {
//			tree::pr ret = f.query(1, i, i);
//			printf("%d %d\n", ret.max, ret.cnt);
//		}
//		f.print();
	}
//	for (int i = 1; i <= n; i++) {
//		tree::pr ret = f.query(1, i, i);
//		printf("%d %d\n", ret.max, ret.cnt);
//	}
	tree::pr ret = f.query(1, n, n);
//	f.print();
	printf("%d\n", ret.max);
	if (type) printf("%d\n", ret.cnt);
	
	return 0;
}
