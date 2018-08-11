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

const int maxn = 100010;
int n, opt;

class FhqTheap {
	
private:
	
	struct node {
		int val, rnd;
		int siz, ch[2];
	} e[maxn];
	int tot, root, x, y, z;
	
	void update(int x) {
		e[x].siz = e[e[x].ch[0]].siz + e[e[x].ch[1]].siz + 1;
	}
	
	int newnode(int val) {
		tot++;
		e[tot].siz = 1;
		e[tot].ch[0] = e[tot].ch[1] = 0;
		e[tot].val = val, e[tot].rnd = rand();
		return tot;
	}
	
	int merge(int x, int y) {
		if (!x || !y) return x + y;
		if (e[x].rnd < e[y].rnd) {
			e[x].ch[1] = merge(e[x].ch[1], y);
			update(x);
			return x;
		} else {
			e[y].ch[0] = merge(x, e[y].ch[0]);
			update(y);
			return y;
		}
	}
	
	void split(int u, int k, int &x, int &y) {
		if (!u) return (void)(x = y = 0);
		if (e[u].val <= k)
			x = u, split(e[x].ch[1], k, e[x].ch[1], y);
		else
			y = u, split(e[y].ch[0], k, x, e[y].ch[0]);
		update(u);
	}
	
	int kth(int u, int k) {
		if (k <= e[e[u].ch[0]].siz) return kth(e[u].ch[0], k);
		if (k == e[e[u].ch[0]].siz + 1) return u;
		return kth(e[u].ch[1], k - e[e[u].ch[0]].siz - 1);
	}
	
public:
	
	void insert(int val) {
		split(root, val, x, y);
		root = merge(merge(x, newnode(val)), y);
	}
	
	void erase(int val) {
		split(root, val, x, z);
		split(x, val - 1, x, y);
		y = merge(e[y].ch[0], e[y].ch[1]);
		root = merge(merge(x, y), z);
	}
	
	int rank(int val) {
		split(root, val - 1, x, y);
		int ret = e[x].siz + 1;
		merge(x, y);
		return ret;
	}
	
	int atrank(int k) {
		return e[kth(root, k)].val;
	}
	
	int lower_bound(int val) {
		split(root, val - 1, x, y);
		int ret = e[kth(x, e[x].siz)].val;
		merge(x, y);
		return ret;
	}
	
	int upper_bound(int val) {
		split(root, val, x, y);
		int ret = e[kth(y, 1)].val;
		merge(x, y);
		return ret;
	}
	
} s;

int main() {
//	freopen("INPUT", "r", stdin);
	
	n = read();
	while (n--) {
		opt = read();
		switch(opt) {
			case 1: s.insert(read()); break;
			case 2: s.erase(read()); break;
			case 3: printf("%d\n", s.rank(read())); break;
			case 4: printf("%d\n", s.atrank(read())); break;
			case 5: printf("%d\n", s.lower_bound(read())); break;
			case 6: printf("%d\n", s.upper_bound(read())); break;
		}
	}
	
	return 0;
}
