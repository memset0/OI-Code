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
	struct node {
		int val, sum, cnt, tag;
		int father, ch[2];
	} e[maxn];
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
			l
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
};

int main() {

	return 0;
}

