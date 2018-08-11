// ==============================
//  author: memset0
//  website: https://memset0.cn
//  date: 2018.08.06 19:56:22
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

#define root e[0].ch[1]
#define inf (1e9+10)
const int maxn = 100010;
int n, opt;

struct Splay {
	struct node {
		int father, val, sum, cnt, ch[2];
	} e[maxn];
	int pos = 0, points = 0;
	void update(int x) {
		e[x].sum = e[e[x].ch[0]].sum + e[e[x].ch[1]].sum + e[x].cnt;
	}
	int identify(int x) {
		return e[e[x].father].ch[0] == x ? 0 : 1;
	}
	void connect(int x, int f, int son) {
		e[x].father = f;
		e[f].ch[son] = x;
	}
	void rotate(int x) {
		int f = e[x].father;
		int fson = identify(x);
		int ff = e[f].father;
		int ffson = identify(f);
		int bro = e[x].ch[fson ^ 1];
		connect(bro, f, fson);
		connect(f, x, fson ^ 1);
		connect(x, ff, ffson);
		update(f);
		update(x);
	}
	void splay(int at, int to) {
		if (at == to) return;
//		printf("%d => %d\n", at, to);
		to = e[to].father;
		while (e[at].father != to) {
//			printf("%d %d %d\n", at, e[at].father, to);
			int up = e[at].father;
			if (e[up].father == to) {
				// 当前节点的父亲即目标节点，旋转一次即可
				rotate(at);
			}
			else if (identify(up) == identify(at)) {
				// 当前节点和其父亲在同一侧，分别旋转维护平衡
				rotate(up);
				rotate(at);
			} else {
				// 当前节点和其父亲在不同侧，直接旋转两次
				rotate(at);
				rotate(at);
			}
		}
	}
	void crepoint(int val, int father) {
		++pos;
		e[pos].val = val;
		e[pos].father = father;
		e[pos].sum = e[pos].cnt = 1;
		e[pos].ch[0] = e[pos].ch[1] = 0;
	}
	void delpoint(int x) {
		e[x].val = 0;
		e[x].father = 0;
		e[x].sum = e[x].cnt = 0;
		e[x].ch[0] = e[x].ch[1] = 0;
		if (x == pos) pos--;
	}
	int find(int val) {
		int u = root;
		while (true) {
			if (e[u].val == val) {
				splay(u, root);
				return u;
			}
			int son = val < e[u].val ? 0 : 1;
			if (!e[u].ch[son]) return 0;
			u = e[u].ch[son];
		}
	}
	int build(int val) {
		++points;
//		printf("POINTS %d\n", points);
		if (points == 1) {
			//���е�ǰ�ڵ��ǵ�һ���ڵ㡣 
			crepoint(val, 0);
			root = pos;
		} else {
			int u = root;
			while (1) {
//				printf("%d\n", u);
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
		return 0;
	}
	void push(int val) {
		int x = build(val);
		splay(x, root);
	}
	void pop(int val) {
		int x = find(val); //查找后自动将当前节点旋转到根
		if (!x) return;
		--points;
		if (e[x].cnt > 1) {
			e[x].cnt--;
			e[x].sum--;
			return;
		}
		if (!e[x].ch[0]) {
			root = e[x].ch[1];
			e[root].father = 0;
		} else {
			int l = e[x].ch[0], r = e[x].ch[1];
			while (e[l].ch[1]) l = e[l].ch[1];
			splay(l, e[x].ch[0]);
			connect(r, l, 1);
			connect(l, 0, 1);
			update(l);
		}
		delpoint(x);
	}
	int rank(int val) {
		int ans = 0, u = root;
		while (u) {
			if (e[u].val == val) {
				ans += e[e[u].ch[0]].sum + 1; 
				break;
			}
			if (val < e[u].val) u = e[u].ch[0];
			else {
				ans += e[e[u].ch[0]].sum + e[u].cnt;
				u = e[u].ch[1];
			}
		}
		if (u) splay(u, root);
		return ans;
	}
	int atrank(int x) {
		if (x > points) return -inf;
		int u = root;
		while (u) {
			if ((x > e[e[u].ch[0]].sum) && (x <= e[e[u].ch[0]].sum + e[u].cnt)) break;
			if (x <= e[e[u].ch[0]].sum) u = e[u].ch[0];
			else {
				x -= e[e[u].ch[0]].sum + e[u].cnt;
				u = e[u].ch[1];
			}
		}
		splay(u, root);
		return e[u].val;
	}
	int lower(int val) {
		int u = root, result = -inf, cho = 0;
		while (u) {
			if (e[u].val < val && e[u].val > result) result = e[u].val, cho = u;
			if (val > e[u].val) u = e[u].ch[1];
			else u = e[u].ch[0];
		}
		if (cho) splay(cho, root);
		return result;
	}
	int upper(int val) {
		int u = root, result = inf, cho = 0;
		while (u) {
			if (e[u].val > val && e[u].val < result) result = e[u].val, cho = u;
			if (val < e[u].val) u = e[u].ch[0];
			else u = e[u].ch[1];
		}
		if (cho) splay(cho, root);
		return result;
	}
	void print_dfs(int u, int father, int son) {
		printf("%d => %d(%d)\n", father, e[u].val, son);
		if (e[u].ch[0]) print_dfs(e[u].ch[0], e[u].val, 0);
		if (e[u].ch[1]) print_dfs(e[u].ch[1], e[u].val, 1);
	}
	void print() {
		printf("== START ==\n");
		print_dfs(root, 0, 1);
		printf("==  END  ==\n");
	}
} s;

int main() {
	freopen("INPUT", "r", stdin);
//	freopen("OUTPUT", "w", stdout);
	n = read();
	while (n--) {
		opt = read();
//		printf(">>> %d\n", opt);
		switch(opt) {
			case 1:
				s.push(read());
				break;
			case 2:
				s.pop(read());
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
//		s.print();
	}
	return 0;
}
