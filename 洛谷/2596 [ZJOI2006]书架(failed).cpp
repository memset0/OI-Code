// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define y1 this_is_not_y1
#define y2 this_is_not_y2
#define ll long long
using namespace std;

int read() {
    int x = 0; bool m = 0; char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') m = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (m) return -x; else return x;
}

char readc() {
	char c = getchar();
	while (c != 'T' && c != 'B' && c != 'I' && c != 'A' && c != 'Q')
		c = getchar(), putchar(c);
	return c;
}

const int maxn = 80010;
int n, m, x, a[maxn], b[maxn];
char opt;

struct Splay {
	
	int tot, points;
	int pos[maxn];
	struct node {
		int val, siz;
		int father, ch[2];
	} e[maxn];
	#define root (e[0].ch[1])
	
	void update(int x) {
		e[x].siz = e[e[x].ch[0]].siz + e[e[x].ch[1]].siz + 1;
	}
	int identify(int x) {
		return e[e[x].father].ch[1] == x;
	}
	void connect(int x, int f, int son) {
		e[x].father = f;
		e[f].ch[son] = x;
	}
	void setroot(int x) {
		root = x;
	}
	void rotate(int x) {
		int f = e[x].father, ff = e[f].father;
		int fson = identify(x), ffson = identify(f);
		int y = e[x].ch[fson ^ 1];
		connect(y, f, fson);
		connect(f, x, fson ^ 1);
		connect(x, ff, ffson);
		update(f), update(x);
	}
	void splay(int at, int to) {
		to = e[to].father;
		while (e[at].father != to) {
			int up = e[at].father;
//			printf("SPLAY %d %d %d\n", at, up, to);
			if (e[up].father == to) rotate(at);
			else if (identify(at) == identify(up)) rotate(up), rotate(at);
			else rotate(at), rotate(at);
		}
	}
	void crepoint(int val, int father, int son) {
		tot++;
		pos[val] = tot;
		e[tot].siz = 1;
		e[tot].val = val;
		e[tot].ch[0] = e[tot].ch[1] = 0;
		if (tot > 1) {
			e[tot - 1].ch[1] = tot;
			e[tot].father = tot - 1;
			splay(tot, root);
		}
	}
	int findkth(int u, int k) {
//		printf("FIND KTH %d %d\n", u, k);
		if (k <= e[e[u].ch[0]].siz) return findkth(e[u].ch[0], k);
		if (k <= e[e[u].ch[0]].siz + 1) return u;
		return findkth(e[u].ch[1], k - e[e[u].ch[0]].siz - 1);
	}
	void change(int &u, int &v) {
		swap(e[u].father, e[v].father);
		swap(u, v);
	}
	
	void Top(int x) {
		int u = pos[x], v = 0;
		splay(u, root);
		if (!e[u].ch[0]) return;
		if (!e[u].ch[1]) {
			change(e[u].ch[0], e[u].ch[1]);
			return;
		}
		v = findkth(root, e[e[u].ch[0]].siz + 2);
//		printf("TOP %d %d\n", u, v);
		e[e[u].ch[0]].father = v;
		e[v].ch[0] = e[u].ch[0];
		e[u].ch[0] = 0;
		splay(v, root);
	}
	void Bottom(int x) {
		int u = pos[x], v;
		splay(u, root);
		if (!e[u].ch[1]) return;
		if (!e[u].ch[0]) {
			change(e[u].ch[0], e[u].ch[1]);
			return;
		}
		v = findkth(root, e[e[u].ch[0]].siz);
		change(e[u].ch[1], e[v].ch[0]);
		splay(v, root);
	}
	void Insert(int x, int d) {
		if (!d) return;
		int u = pos[x], v = 0;
//		printf("INSERT %d %d\n", u, v);
		splay(u, root);
		v = findkth(root, e[e[u].ch[0]].siz + 1 + d);
		swap(e[u].val, e[v].val);
		swap(pos[e[u].val], pos[e[v].val]);
	}
	int Ask(int x) {
		int u = pos[x];
		splay(u, root);
		return e[e[u].ch[0]].siz;
	}
	int Query(int x) {
		int ret = findkth(root, x);
		splay(ret, root);
		return e[ret].val;
	}
	
	void print_dfs(int u, int father) {
//		printf("%d(%d) -> %d(%d)\n", father, e[father].val, u, e[u].val);
		if (e[u].ch[0]) print_dfs(e[u].ch[0], u);
		if (e[u].ch[1]) print_dfs(e[u].ch[1], u);
	}
	void print() {
		puts("=========");
		for (int i = 1; i <= n; i++)
			printf("%d ", pos[i]);
		putchar('\n');
		for (int i = 1; i <= n; i++)
			printf("%d ", e[i].val);
		putchar('\n');
		for (int i = 1; i <= n; i++)
			printf("%d ", e[i].siz);
		putchar('\n');
		for (int i = 1; i <= n; i++)
			printf("%d ", e[i].father);
		putchar('\n');
		for (int i = 1; i <= n; i++)
			printf("%d ", e[i].ch[0]);
		putchar('\n');
		for (int i = 1; i <= n; i++)
			printf("%d ", e[i].ch[1]);
		putchar('\n');
//		print_dfs(root, 0);
	}
	
} s;

int main() {
	freopen("INPUT", "r", stdin);
	
	n = read(), m = read();
	s.setroot(1);
	for (int i = 1; i <= n; i++)
		s.crepoint(read(), i - 1, 1);
			
	while (m--) {
		opt = readc(), x = read();
//		printf(">>> %c %d\n", opt, x);
//		s.print();
		switch(opt) {
			case 'T': s.Top(x); break;
			case 'B': s.Bottom(x); break;
			case 'I': s.Insert(x, read()); break;
			case 'A': printf("%d\n", s.Ask(x)); break;
			case 'Q': printf("%d\n", s.Query(x)); break;
		}
	}
	
	return 0;
}
