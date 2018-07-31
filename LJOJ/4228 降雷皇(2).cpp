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
int n, type, lengthG, lengthC, a[maxn], g[maxn], c[maxn];
class discretizationClass {
	private:
		struct element{
			int i, value;
			bool operator < (const element &b) const {
				return value < b.value;
			}
		} b[maxn];
	public:
		void main(int *a, int length) {
			for (int i = 1; i <= length; i++)
				b[i] = (element){i, a[i]};
			sort(b + 1, b + length + 1);
//			for (int i = 1; i <= n; i++)
//				cout << b[i].i << " " << b[i].value << endl;
			for (int i = 1; i <= n; i++)
				if (b[i].value == b[i - 1].value) a[b[i].i] = a[b[i - 1].i];
				else a[b[i].i] = i;
		}
} discretization;

class tree {
	private:
		struct Child {
			int l, r, mid, max, cnt, lmax, lcnt;
		} p[maxn << 3];
	public:
		struct Pair {
			int max, cnt;
		};
		void pushup(int u, int max, int cnt) {
			if (max > p[u].lmax) p[u].lmax = max, p[u].lcnt = cnt;
			else if (max == p[u].lmax) p[u].cnt += cnt; 
		}
		void pushdown(int u) {
			if (p[u].lmax) {
				if (p[u].lmax > p[u].max) p[u].max = p[u].lmax, p[u].cnt = p[u].lcnt;
				else if (p[u].lmax == p[u].max) p[u].cnt += p[u].lcnt;
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
			printf("U u=%d pl=%d pr=%d l=%d r=%d max=%d cnt=%d pmax=%d pcnt=%d\n", u, p[u].l, p[u].r, l, r, max, cnt, p[u].max, p[u].cnt);
			pushdown(u);
			if (l == p[u].l && r == p[u].r) {
				pushup(u, max, cnt);
				return ;
			}
			if (max > p[u].max) p[u].max = max, p[u].cnt = cnt;
			else if (max == p[u].max) p[u].cnt += cnt;
			else return;
			if (r <= p[u].mid) update(u << 1, l, r, max, cnt);
			else if (l > p[u].mid) update(u << 1 | 1, l, r, max, cnt);
			else {
				update(u << 1, l, p[u].mid, max, cnt);
				update(u << 1 | 1, p[u].mid + 1, r, max, cnt);
			}
		}
		Pair query(int u, int l, int r) {
			if (l > r) return (Pair){0, 0};
			printf("Q u=%d pl=%d pr=%d l=%d r=%d max=%d cnt=%d\n", u, p[u].l, p[u].r, l, r, p[u].max, p[u].cnt);
			pushdown(u);
			if (l == p[u].l && r == p[u].r) return (Pair){p[u].max, p[u].cnt};
			if (r <= p[u].mid) return query(u << 1, l, r);
			else if (l > p[u].mid) return query(u << 1 | 1, l, r);
			else {
				Pair a = query(u << 1, l, p[u].mid);
				Pair b = query(u << 1 | 1, p[u].mid + 1, r);
				if (a.max > b.max) return a;
				else if (b.max > a.max) return b;
				else return {a.max, (a.cnt + b.cnt) % M};
			}
		}
		void print() {
			for (int i = 1; i <= n; i++)
				printf("p[%d] = {l = %d r = %d mid = %d max = %d cnt = %d lmax = %d lcnt = %d}\n", i, p[i].l, p[i].r, p[i].mid, p[i].max, p[i].cnt, p[i].lmax, p[i].lcnt);
		}
} f;

void print(int *a, int length) {
	for (int i = 1; i <= length; i++)
		cout << a[i] << " ";
	cout << endl;
}

int main() {
	freopen("INPUT", "r", stdin);
	n = read(), type = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	discretization.main(a, n);
	f.create(1, 1, n);
	f.update(1, 1, n, 1, 1);
	g[1] = c[1] = 1;
	f.print();
	for (int i = 2; i <= n; i++) {
		ret = f.query(1, i, i);
		cout << ret.max << " " << ret.cnt << endl;
		g[i] = ret.max, c[i] = ret.cnt;
		f.update(1, i + 1, n, g[i] + 1, c[i]);
		f.print();
	}
	
	print(g, n);
	print(c, n);
	int ans = 0;
	for (int i = 1; i <= n; i++)
		if (g[i] > ans)
			ans = g[i];
	printf("%d\n", ans);
	if (type) {
		int sum = 0;
		for (int i = 1; i <= n; i++)
			if (g[i] == ans)
				sum += c[i];
		printf("%d\n", sum);
	}	
	return 0;
}
