// ==============================
//  author: memset0
//  website: https://memset0.cn
//  date: 2018.08.07 07:17:41
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
	#define root e[0].ch[1]
	#define inf (1e9+10)
	struct node {
		int val, cnt, sum;
		int father, ch[2];
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
	void crepoint(int val, int father) {
		pos++;
		e[pos].val = val;
		e[pos].father = father;
		e[pos].cnt = e[pos].sum = 1;
		e[pos].ch[0] = e[pos].ch[1] = 0;
		// printf("CREATE %d %d %d\n", pos, val, father);
	}
	void delpoint(int pos) {
		e[pos].val = 0;
		e[pos].father = 0;
		e[pos].sum = e[pos].cnt = 0;
		e[pos].ch[0] = e[pos].ch[1] = 0;
	}
	int find(int val) {
		int u = root, cho = 0;
		while (u) {
			if (e[u].val == val) {
				cho = u;
				break;
			}
			u = e[u].ch[val < e[u].val ? 0 : 1];
		}
		if (cho) splay(cho, root);
		return cho;
	}
	int build(int val) {
		points++;
		if (points == 1) {
			crepoint(val, 0);
			root = pos;
			return pos;
		} else {
			int u = root;
			while (u) {
				// printf("--> %d\n", u);
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
	}
	int insert(int val) {
		int add = build(val);
		splay(add, root);
	}
	void erase(int val) {
		int u = find(val);
		points--;
		if (e[u].cnt > 1) {
			e[u].cnt--;
			e[u].sum--;
		} else {
			if (!e[u].ch[0]) {
				root = e[u].ch[1];
				e[root].father = 0;
			} else {
				int left = e[u].ch[0], right = e[u].ch[1];
				while (e[left].ch[1]) left = e[left].ch[1];
				splay(left, e[u].ch[0]);
				connect(right, left, 1);
				connect(left, 0, 1);
				update(left);
			}
			delpoint(u);
		}
	}
	int rank(int val) {
		int u = root, ans = 0, cho = 0;
		while (u) {
			if (e[u].val == val) {
				ans += e[e[u].ch[0]].sum + 1;
				cho = u;
				break;
			}
			if (val < e[u].val) {
				u = e[u].ch[0];
			} else {
				ans += e[e[u].ch[0]].sum + e[u].cnt;
				u = e[u].ch[1];
			}
		}
		if (cho) splay(cho, root);
		return ans;
	}
	int atrank(int x) {
		int u = root, cho = 0;
		while (u) {
			if (e[e[u].ch[0]].sum < x && x <= e[e[u].ch[0]].sum + e[u].cnt) {
				cho = u;
				break;
			}
			if (e[e[u].ch[0]].sum >= x) {
				u = e[u].ch[0];
			} else {
				x -= e[e[u].ch[0]].sum + e[u].cnt;
				u = e[u].ch[1];
			}
		}
		if (cho) splay(cho, root);
		return e[cho].val;
	}
	int lower(int val) {
		int u = root, ret = -inf, cho = 0;
		while (u) {
			if (e[u].val < val && e[u].val > ret) ret = e[u].val, cho = u;
			u = e[u].ch[val <= e[u].val ? 0 : 1];
		}
		if (cho) splay(cho, root);
		return e[cho].val;
	}
	int upper(int val) {
		int u = root, ret = inf, cho = 0;
		while (u) {
			if (e[u].val > val && e[u].val < ret) ret = e[u].val, cho = u;
			u = e[u].ch[val >= e[u].val ? 1 : 0];
		}
		if (cho) splay(cho, root);
		return e[cho].val;
	}
	void print_dfs(int u, int father) {
		printf("%d(%d) => %d(%d)\n", father, e[father].val, u, e[u].val);
		if (e[u].ch[0]) print_dfs(e[u].ch[0], u);
		if (e[u].ch[1]) print_dfs(e[u].ch[1], u);
	}
	void print() {
		printf("=== START ===\n");
		print_dfs(root, 0);
		printf("===  END  ===\n");
	}
	#undef inf
	#undef root
} s;

int main() {
	freopen("INPUT", "r", stdin);

	n = read();
	while (n--) {
		opt = read();
		// printf(">>> %d | %d\n", opt, s.e[0].ch[1]);
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
		// s.print();
	}
	return 0;
}