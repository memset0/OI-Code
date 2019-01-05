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
	#define inf (1e9 + 10)
	#define lson(x) (e[x].ch[0])
	#define rson(x) (e[x].ch[1])
	struct node {
		int val, cnt, sum;
		int father, ch[2];
		bool tag;
	} e[maxn];
	int pos = 0, points = 0;
	void update(int x) {
		e[x].sum = e[lson(x)].sum + e[rson(x)].sum + e[x].cnt;
	}
	void setroot(int x) {
		root = x;
	}
	int getroot() {
		return root;
	}
	int identify(int x) {
		return e[e[x].father].ch[1] == x;
	}
	void pushdown(int x) {
		if (e[x].tag) {
			e[lson(x)].tag ^= 1;
			e[rson(x)].tag ^= 1;
			e[x].tag = 0;
			swap(lson(x), rson(x));
		}
	}
	void connect(int x, int f, int son) {
		e[x].father = f;
		e[f].ch[son] = x;
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
//			printf("%d %d\n", at, up);
			if (e[up].father == to) {
				rotate(at);
			} else if (identify(at) == identify(up)) {
				rotate(up);
				rotate(at);
			} else {
				rotate(at);
				rotate(at);
			}
		}
	}
	int find(int x) {
		int u = root;
		while (u) {
//			printf("%d\n", u);
			pushdown(u);
			int mincost = e[e[u].ch[0]].sum + e[u].cnt;
			if (e[e[u].ch[0]].sum < x && x <= mincost) {
				splay(u, root);
				return u;
			}
			if (x < mincost) u = e[u].ch[0];
			else x -= mincost, u = e[u].ch[1];
		}
	}
	void build(int l, int r, int f) {
		if (l > r) return;
		int mid = (l + r) >> 1;
		if (mid < f) e[f].ch[0] = mid;
		else e[f].ch[1] = mid;
		e[mid].father = f;
		e[mid].val = mid;
		e[mid].tag = 0;
		e[mid].cnt = e[mid].sum = 1;
		if (l == r) return;
		build(l, mid - 1, mid);
		build(mid + 1, r, mid);
		update(mid);
	}
	void reverse(int l, int r) {
		int x = find(l - 1), y = find(r + 1);
//		printf("==> find(%d) = %d; find(%d) = %d;\n", l - 1, x, r + 1, y);
		splay(x, root);
		splay(y, e[x].ch[1]);
		e[e[y].ch[0]].tag ^= 1;
	}
	void print_dfs(int u, int father) {
		printf("%d(%d,%d,%d,%d) <= %d(%d)\n", u, e[u].val, e[u].cnt, e[u].sum, e[u].father, father, e[father].val);
		if (e[u].ch[0]) print_dfs(e[u].ch[0], u);
		if (e[u].ch[1]) print_dfs(e[u].ch[1], u);
	}
	void print() {
		puts("=== START ===");
		print_dfs(root, 0);
		puts("===  END  ===");
	}
	#undef root
	#undef inf
	#undef lson
	#undef rson
} s;

int main() {
//	freopen("INPUT", "r", stdin);
	n = read(), m = read();
	s.setroot((n + 3) >> 1);
	s.build(1, n + 2, 0);
//	s.print();
	while (m--) {
		l = read(), r = read();
//		printf(">>> %d %d\n", l, r);
		s.reverse(l + 1, r + 1);
	}
	for (int i = 1; i <= n; i++)
		printf("%d ", s.find(i + 1) - 1);
	putchar('\n');
	return 0;
}
