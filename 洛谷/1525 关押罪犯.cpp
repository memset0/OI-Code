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

const int maxn = 20010, maxm = 100010;

int n, m, u, v, w;
int f[maxn], b[maxn];

struct edge {
	int u, v, w;
	edge () {}
	edge (int a, int b, int c) { u = a, v = b, w = c; }
	bool operator < (const edge &b) const {
		return w > b.w;
	}
} e[maxm];

int find(int x) {
	if (f[x] == x) return x;
	return f[x] = find(f[x]);
}

int main() {
	
	n = read(), m = read();
	for (int i = 1; i <= n; i++)
		f[i] = i;
	for (int i = 1; i <= m; i++) {
		u = read(), v = read(), w = read();
		e[i] = edge(u, v, w);
	}
	sort(e + 1, e + m + 1);
	for (int i = 1; i <= m; i++) {
		u = e[i].u, v = e[i].v, w = e[i].w;
		if (find(u) == find(v)) {
			printf("%d\n", w);
			return 0;
		}
//		printf("%d %d %d %d\n", u, v, b[u], b[v]);
		if (b[u]) f[find(b[u])] = find(v);
		if (b[v]) f[find(b[v])] = find(u);
		b[u] = v;
		b[v] = u;
	}
	puts("0");
	
	return 0;
}

