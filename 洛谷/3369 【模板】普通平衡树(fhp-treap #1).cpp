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
int n, opt, a, x, y, z, root;
double x1, x2, y1, y2;

namespace FhqTreap {
	int tot = 0;
	int val[maxn], rnd[maxn], siz[maxn], ch[maxn][2];
	void update(int x) {
		siz[x] = siz[ch[x][0]] + siz[ch[x][1]] + 1;
	}
	int newnode(int value) {
		++tot, siz[tot] = 1, val[tot] = value, rnd[tot] = rand();
		return tot;
	}
	int merge(int x, int y) { // ±£Ö¤ val[x] < val[y]
		if (!x) return y;
		if (!y) return x;
		update(x), update(y);
		if (rnd[x] < rnd[y]) {
			ch[x][1] = merge(ch[x][1], y);
			update(x);
			return x;
		} else {
			ch[y][0] = merge(x, ch[y][0]);
			update(y);
			return y;
		}
	}
	void split(int u, int k, int &x, int &y) {
		if (!u) return (void)(x = y = 0);
		if (val[u] <= k) x = u, split(ch[u][1], k, ch[u][1], y);
		else y = u, split(ch[u][0], k, x, ch[u][0]);
		update(u);
	}
	int kth(int u, int k) {
		while (u) {
			if (k <= siz[ch[u][0]]) u = ch[u][0];
			else if (k == siz[ch[u][0]] + 1) return u;
			else k -= siz[ch[u][0]] + 1, u = ch[u][1];
		}
	}
}
using namespace FhqTreap;

int main() {
//	freopen("INPUT", "r", stdin);
	srand(time(NULL));
	
	n = read();
	while (n--) {
		opt = read(), a = read();
		int x, y, z;
		switch(opt) {
			case 1:
				split(root, a, x, y);
				root = merge(merge(x, newnode(a)), y);
				break;
			case 2:
				split(root, a, x, z);
				split(x, a - 1, x, y);
				y = merge(ch[y][0], ch[y][1]);
				root = merge(merge(x, y), z);
				break;
			case 3:
				split(root, a - 1, x, y);
				printf("%d\n", siz[x] + 1);
				root = merge(x, y);
				break;
			case 4:
				printf("%d\n", val[kth(root, a)]);
				break;
			case 5:
				split(root, a - 1, x, y);
				printf("%d\n", val[kth(x, siz[x])]);
				root = merge(x, y);
				break;
			case 6:
				split(root, a, x, y);
				printf("%d\n", val[kth(y, 1)]);
				root = merge(x, y);
				break;
		}
	}
	
	return 0;
}
