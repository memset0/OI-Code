// luogu-judger-enable-o2
#include <bits/stdc++.h> 
#define isNum(c)  ('0'<=c&&c<='9')
using namespace std;
const int maxn = 100010, maxm = 500010;
int n, m;
int ret; char ch;
struct Tree {
	int l, r, val;
} p[maxn * 4];
int read() {
	ch = getchar(), ret = 0;
	while (!isNum(ch)) ch = getchar();
	while (isNum(ch)) ret = ret * 10 + ch - '0', ch = getchar();
	return ret;
}
void build(int u, int l, int r) {
//	cout << u << " " << l << " " << r << endl;
	p[u].l = l, p[u].r = r;
	p[u].val = 0;
	if (p[u].l == p[u].r) return ;
	int mid = (p[u].l + p[u].r) >> 1;
	build(u << 1, l, mid);
	build((u << 1) + 1, mid + 1, r);
}
void add(int u, int l, int r) {
//	cout << u << " " << l << " " << r << " " << p[u].l << " " << p[u].r << endl;
	if (p[u].l == l && p[u].r == r) {
		p[u].val++;
		return ;
	}
	int mid = (p[u].l + p[u].r) >> 1;
	if (r <= mid) add(u << 1, l, r);
	else if (l > mid) add((u << 1) + 1, l, r);
	else {
		add(u << 1, l, mid);
		add((u << 1) + 1, mid + 1, r);
	}
}
int ask(int u, int x) {
	if (p[u].l == p[u].r) return p[u].val;
	int mid = (p[u].l + p[u].r) >> 1;
	if (x <= mid) return p[u].val + ask(u << 1, x);
	return p[u].val + ask((u << 1) + 1, x);
}
int main() {
	n = read(), m = read();
	build(1, 1, n);
//	for (int i = 1; i <= 60; i++)
//		printf("%d: %d %d\n", i, p[i].l, p[i].r);
	int x, y, z;
	for (int i = 1; i <= m; i++) {
		x = read();
		if (x == 1) {
			y = read(), z = read();
			add(1, y, z);
		} else {
			y = read();
			printf("%d\n", ask(1, y) & 1);
		}
	}
//	for (int i = 1; i <= 60; i++)
//		printf("%d: %d %d %d\n", i, p[i].l, p[i].r, p[i].val);
	return 0;
}