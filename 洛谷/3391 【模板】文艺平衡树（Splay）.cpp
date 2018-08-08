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
int opt, points;

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
	void update(int x) {
		e[x].sum = e[lson(x)].sum + e[rson(x)].son + e[x].cnt;
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
	void connnect(int x, int f, int son) {
		e[x].father = f;
		e[f].ch[son] = x;
	}
	void rotate(int x) {
		int f = e[x].father, fson = identify(x);
		int ff = e[f].father, ffson = identify(f);
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
			if (e[up].father == to) {
				rotate(at);
			} else if (identify(at) == identify(up)) {
				rotate(up);
				rotate(at);
			} else {
				rotate()
			}
		}
	}
};

int main() {

	return 0;
}

