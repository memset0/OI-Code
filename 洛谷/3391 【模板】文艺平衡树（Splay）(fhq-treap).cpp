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

int n, m, l, r, x, y, z, root;
int tag[maxn], rnd[maxn], ch[maxn][2], siz[maxn], val[maxn];

void update(int u) { siz[u] = siz[ch[u][0]] + siz[ch[u][1]] + 1; }

void pushdown(int u) {
	if (tag[u]) {
		std::swap(ch[u][0], ch[u][1]);
		tag[ch[u][0]] ^= 1;
		tag[ch[u][1]] ^= 1;
		tag[u] = 0;
	}
}

void split(int u, int k, int &l, int &r) {
	if (!u) return (void) (l = r = 0);
	pushdown(u);
	if (k <= siz[ch[u][0]])
		r = u, split(ch[u][0], k, l, ch[u][0]);
	else
		l = u, split(ch[u][1], k - siz[ch[u][0]] - 1, ch[u][1], r);
	update(u);
}

int merge(int u, int v) {
	if (!u || !v) return u + v;
	if (rnd[u] < rnd[v]) {
		pushdown(u);
		ch[u][1] = merge(ch[u][1], v);
		update(u);
		return u;
	} else {
		pushdown(v);
		ch[v][0] = merge(u, ch[v][0]);
		update(v);
		return v;
	}
}

void print(int u) {
	pushdown(u);
	if (ch[u][0]) print(ch[u][0]);
	printf("%d ", val[u]);
	if (ch[u][1]) print(ch[u][1]);
}

int main() {
	
	n = read(), m = read();
	for (int i = 1; i <= n; i++) {
		siz[i] = 1, rnd[i] = rand(), val[i] = i;
		root = merge(root, i);
	}
	
	for (int i = 1; i <= m; i++) {
		l = read(), r = read();
		split(root, l - 1, x, y);
		split(y, r - l + 1, y, z);
		tag[y] ^= 1;
		root = merge(x, merge(y, z));
	}
	
	print(root);
	putchar('\n');
	
	return 0;
}
