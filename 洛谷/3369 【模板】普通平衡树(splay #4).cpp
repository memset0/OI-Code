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
int n, opt;

struct Splay {
	#define root (e[0].ch[1])
	#define inf (1e9+10)
	struct node {
		int val, sum, cnt;
		int father, ch[2];
	} e[maxn];
	int pos = 0, points = 0;
	inline void update(int x) {
		e[x].sum = e[e[x].ch[0]].sum + e[e[x].ch[1]].sum + e[x].cnt;
	}
	inline int identify(int x) {
		return e[e[x].father].ch[0] == x ? 0 : 1;
	}
	inline void connect(int x, int f, int son) {
		e[x].father = f;
		e[f].ch[son] = x;
	}
	inline void rotate(int x) {
		int f = e[x].father, fson = identify(x);
		int ff = e[f].father, ffson = identify(f);
		int y = e[x].ch[fson ^ 1];
		connect(y, f, fson);
		connect(f, x, fson ^ 1);
		connect(x, ff, ffson);
		update(f);
		update(x);
	}
	inline void splay(int at, int to) {
		if (!at) return;
		to = e[to].father;
		while (e[at].father != to) {
			int up = e[at].father;
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
	inline void crepoint(int val, int father) {
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
			if (val == e[u].val) return u;
			u = e[u].ch[val < e[u].val ? 0 : 1];
		}
	}
	int build(int val) {
		points++;
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
		points--;
		splay(u, root);
		if (e[u].cnt > 1) {
			e[u].cnt--;
			e[u].sum--;
			return;
		}
		if (!e[u].ch[0]) {
			root = e[u].ch[1];
			e[root].father = 0;
		} else {
			int lft = e[u].ch[0], rit = e[u].ch[1];
			while (e[lft].ch[1]) lft = e[lft].ch[1];
			splay(lft, e[u].ch[0]);
			connect(rit, lft, 1);
			connect(lft, 0, 1);
			update(lft);
		}
		delpoint(u);
	}
	int rank(int val) {
		int u = root, ans = 0;
		while (u) {
			if (e[u].val == val) {
				ans += e[e[u].ch[0]].sum + 1;
				splay(u, root);
				return ans;
			}
			if (val > e[u].val) ans += e[e[u].ch[0]].sum + e[u].cnt;
			u = e[u].ch[val < e[u].val ? 0 : 1];
		}
	}
	int atrank(int x) {
		int u = root;
		while (u) {
			int minused = e[e[u].ch[0]].sum + e[u].cnt;
			if (e[e[u].ch[0]].sum < x && x <= minused) {
				splay(u, root);
				return e[u].val;
			}
			if (x > minused) x -= minused, u = e[u].ch[1];
			else u = e[u].ch[0];
		}
	}
	int lower(int val) {
		int u = root, cho = 0, ans = -inf;
		while (u) {
			if (e[u].val < val && e[u].val > ans) ans = e[u].val, cho = u;
			u = e[u].ch[val <= e[u].val ? 0 : 1];
		}
		splay(cho, root);
		return ans;
	}
	int upper(int val) {
		int u = root, cho = 0, ans = inf;
		while (u) {
			if (e[u].val > val && e[u].val < ans) ans = e[u].val, cho = u;
			u = e[u].ch[val >= e[u].val ? 1 : 0];
		}
		splay(cho, root);
		return ans;
	}
	#undef root
	#undef inf
} s;

int main() {
//	freopen("INPUT", "r", stdin);
//	freopen("OUTPUT", "w", stdout);

	n = read();
	for (int i = 1; i <= n; i++) {
		opt = read();
//		printf(">>> %d\n", opt);
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
