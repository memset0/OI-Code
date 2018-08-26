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

const int maxn = 1010, maxm = 20010;

int n, m, k;
int tot = 2, hed[maxn], nxt[maxm], to[maxm], siz[maxm], cst[maxm];

struct edge {
	int u, v, c, w;
} g[5010];

void add_edge(int u, int v, int w, int c) {
	nxt[tot] = hed[u];
	to[tot] = v;
	siz[tot] = w;
	cst[tot] = c;
	hed[u] = tot++;
}

void isap() {
	for (int i = 1; i <= n; i++)
		cur[i] = hed[i];
	u = 1, gap[0] = n;
	while (dep[u] < n) {
		flag = 1;
		for (int &i = cur[u]; i; i = nxt[i])
			if (val[i] && dep[u] == dep[to[i]] + 1) {
				u = to[i];
				flag = 0;
				break;
			}
		if (!flag) {
			for (int i = hed[u]; i; i = nxt[i])
		}
	}
}

int main() {
	// freopen("INPUT", "r", stdin);
	// freopen("OUTPUT", "w", stdout);

	n = read(), m = read(), k = read();
	for (int i = 1; i <= m; i++) {
		g[i].u = read();
		g[i].v = read();
		g[i].c = read();
		g[i].w = read();
	}

	for (int i = 1; i <= m; i++) {
		add_edge(u, v, c, 0);
		add_edge(v, u, c, 0);
	}




	return 0;
}