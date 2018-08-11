// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
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
int n, m, l, r;

struct Splay {
	#define root (e[0].ch[1])
	struct node {
		int val, sum, cnt, tag;
		int father, ch[2];
	} e[maxn];
	void setroot(int x) {
		root = x;
	}
	void update(int x) {
		e[x].sum = e[e[x].ch[0]].sum + e[e[x].ch[1]].sum + e[x].cnt;
	}
	int identify(int x) {
		return e[e[x].father].ch[1] == x;
	}
	void connect(int u, int f, int son) {
		e[u].father = f;
		e[f].ch[son] = u;
	}
	void pushdown(int x) {
		if (e[x].tag) {
			swap(e[x].ch[0], e[x].ch[1]);
			e[e[x].ch[0]].tag ^= 1;
			e[e[x].ch[1]].tag ^= 1;
			e[x].tag = 0;
		}
	}
	void rotate(int x) {
		int f = e[x].father, ff = e[f].father;
		pushdown(f), pushdown(x);
		int fson = identify(x), ffson = identify(f);
		int y = e[x].ch[fson ^ 1];
		connect(y, f, fson);
		connect(f, x, fson ^ 1);
		connect(x, ff, ffson);
		update(f);
		update(x);
	}
	void splay(int at, int to) {
		to = e[to].father;
		while (e[at].father != to) {
			int up = e[at].father;
			pushdown(up), pushdown(at);
			if (e[up].father == to) rotate(at);
			else if (identify(at) == identify(up)) rotate(up), rotate(at);
			else rotate(at), rotate(at);
		}
	}
	int find(int x) {
		int u = root;
		while (u) {
			pushdown(u);
			int mincost = e[e[u].ch[0]].sum + e[u].cnt;
			if (e[e[u].ch[0]].sum < x && x <= mincost) return u;
			if (x < mincost) u = e[u].ch[0];
			else x -= mincost, u = e[u].ch[1];
		}
//		puts("WARNING");
	}
	void build(int l, int r, int f) {
		if (l > r) return;
		int m = (l + r) >> 1;
		e[m].val = m, e[m].father = f;
		e[m].cnt = e[m].sum = 1;
		e[m].ch[0] = e[m].ch[1] = 0;
		if (m < f) e[f].ch[0] = m;
		else e[f].ch[1] = m;
		if (l == r) return;
		build(l, m - 1, m);
		build(m + 1, r, m);
		update(m);
	}
	void reverse(int l, int r) {
		int x = find(l - 1), y = find(r + 1);
		splay(x, root);
		splay(y, e[x].ch[1]);
		e[e[y].ch[0]].tag ^= 1;
	}
	#undef root
} s;

int main() {
//	freopen("INPUT", "r", stdin);
	
	int n = read(), m = read();
	s.setroot((n + 3) >> 1);
	s.build(1, n + 2, 0);
	while (m--) {
		l = read(), r = read();
		s.reverse(l + 1, r + 1);
	}
	for (int i = 1; i <= n; i++)
		printf("%d ", s.find(i + 1) - 1);
	putchar('\n');
	
	return 0;
}

