// ==============================
//  author: memset0
//  website: https://memset0.cn
//  date: 2018.08.07 18:12:23
// ==============================
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int read() {
	int x = 0; char c = getchar(); bool m = 0;
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') c = getchar(), m = 1;
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (m) return -x; else return x;
}

const int maxn = 100010;
int n, opt;

struct Splay {
	#define root (e[0].ch[1])
	#define inf (1e9 + 10)
	struct node {
		int val, cnt, sum;
		int father, ch[2];
	} e[maxn];
	int points = 0, pos = 0;
	void update(int u) {
		e[u].sum = e[e[u].ch[0]].sum + e[e[u].ch[1]].sum + e[u].cnt;
	}
	int identify(int u) {
		return e[e[u].father].ch[0] == u ? 0 : 1;
	}
	void connect(int u, int f, int son) {
		e[u].father = f;
		e[f].ch[son] = u;
	}
	void rotate(int x) {
		int f = e[x].father;
		int fson = identify(x);
		int ff = e[f].father;
		int ffson = identify(f);
		int y = e[x].ch[fson ^ 1];
		connect(y, f, fson);
		connect(f, x, fson ^ 1);
		connect(x, ff, ffson);
		update(f), update(x);
	}
	void splay(int at, int to) {
		if (!at) return;
		to = e[to].father;
		while (e[at].father != to) {
			printf("%d %d\n", at, to);
			int up = e[at].father;
			if (e[up].father == to) {
				rotate(at);
			} else if (identify(at) == identify(to)) {
				rotate(up);
				rotate(at);
			} else {
				rotate(at);
				rotate(at);
			}
		}
	}
	void crepoint(int val, int father) {
		pos++;
		e[pos].val = val;
		e[pos].father = father;
		e[pos].ch[0] = e[pos].ch[1] = 0;
		e[pos].sum = e[pos].cnt = 1;
	}
	void delpoint(int x) {
		e[x].val = 0;
		e[x].father = 0;
		e[x].ch[0] = e[x].ch[1] = 0;
		e[x].sum = e[x].cnt = 0;
	}
	int find(int val) {
		int u = root;
		while (u) {
			if (val == e[u].val) {
				splay(u, root);
				return u;
			}
			u = e[u].ch[val < e[u].val ? 0 : 1];
		}
	}
	int build(int val) {
		++points;
		if (points == 1) {
			crepoint(val, 0);
			root = pos;
			return pos;
		}
		int u = root;
		while (u) {
			e[u].sum++;
			if (val == e[u].val) {
				e[u].cnt++;
				return u;
			}
			int son = val < e[u].val ? 0 : 1;
			if (!e[u].ch[son]) {
				crepoint(val, u);
				e[u].ch[son] = pos;
				return pos;
			}
			u = e[u].ch[son];
		}
	}
	void insert(int val) {
		int add = build(val);
		splay(add, root);
	}
	void erase(int val) {
		int u = find(val);
		--points;
		if (e[u].cnt > 1) {
			e[u].cnt--;
			e[u].sum--;
			return;
		}
		if (!e[u].ch[0]) {
			root = e[u].ch[1];
			e[root].father = 0;
			delpoint(u);
		} else {
			int lft = e[u].ch[0], rit = e[u].ch[1];
			while(e[lft].ch[1]) lft = e[lft].ch[1];
			splay(lft, e[u].ch[0]);
			connect(rit, lft, 1);
			connect(lft, 0, 1);
			update(lft);
			delpoint(u);
		}
	}
	int rank(int val) {
		int u = root, result = 0;
		while (u) {
			if (val == e[u].val) {
				result += e[e[u].ch[0]].sum + 1;
				splay(u, root);
				return result;
			}
			if (val > e[u].val) result += e[e[u].ch[0]].sum + e[u].cnt;
			u = e[u].ch[val < e[u].val ? 0 : 1];
		}
	}
	int atrank(int x) {
		int u = root;
		while (u) {
			int mincost = e[e[u].ch[0]].sum + e[u].cnt;
			if (e[e[u].ch[0]].sum < x && x <= mincost) {
				splay(u, root);
				return e[u].val;
			}
			if (x > mincost) x -= mincost, u = e[u].ch[1];
			else u = e[u].ch[0];
		}
	}
	int lower(int val) {
		int u = root, result = -inf, cho = 0;
		while (u) {
			if (val < e[u].val && e[u].val > result) result = e[u].val, cho = u;
			u = e[u].ch[val <= e[u].val ? 0 : 1];
		}
		splay(cho, root);
		return result;
	}
	int upper(int val) {
		int u = root, result = inf, cho = 0;
		while (u) {
			if (val > e[u].val && e[u].val < result) result = e[u].val, cho = u;
			u = e[u].ch[val >= e[u].val ? 1 : 0];
		}
		splay(cho, root);
		return result;
	}
	#undef root
	#undef inf
} s;

int main() {
	freopen("INPUT", "r", stdin);
	n = read();
	for (int i = 1; i <= n; i++) {
		opt = read();
		printf(">>> %d\n", opt);
		switch (opt) {
			case 1:
				s.insert(read());
				break;
			case 2:
				s.erase(read());
				break;
			case 3:
				printf("%d\n", s.rank(read()));
				break;
			case 4:
				printf("%d\n", s.atrank(read()));
				break;
			case 5:
				printf("%d\n", s.lower(read()));
				break;
			case 6:
				printf("%d\n", s.upper(read()));
				break;
		}
	}
	return 0;
}