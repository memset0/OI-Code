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
int n, m, k, cnt1, cnt0, chose;
int need[maxm];

struct edge {
	int u, v, w;
	bool operator < (const edge &b) const {
		return w < b.w;
	}
} g[maxm];

int fa[maxn];

int find(int x) {
	if (fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}

void merge(int a, int b) {
	fa[find(a)] = find(b);
}

int main() {
	// freopen("INPUT", "r", stdin);
	// freopen("OUTPUT", "w", stdout);

	n = read(), m = read(), k = read();
	for (int i = 1; i <= m; i++)
		g[i].u = read(), g[i].v = read(), g[i].w = read();

	for (int i = 1; i <= n; i++)
		fa[i] = i;
	for (int i = 1; i <= m; i++)
		if (g[i].w) cnt1++;
		else cnt0++;
	sort(g + 1, g + m + 1);

	for (int i = cnt0 + 1; i <= m; i++)
		merge(g[i].u, g[i].v);
	for (int i = 1; i <= cnt0; i++)
		if (find(g[i].u) != find(g[i].v)) {
			merge(g[i].u, g[i].v);
			need[i] = 1;
		}

	for (int i = 1; i <= n; i++)
		fa[i] = i;

	for (int i = 1; i <= m; i++)
		if (need[i]) {
			merge(g[i].u, g[i].v);
			if (!g[i].w) chose++;
		}

	if (chose > k) {
		printf("no solution\n");
		return 0;
	}

	for (int i = 1; i <= m; i++)
		if (find(g[i].u) != find(g[i].v) && !need[i])
			if ((!g[i].w && chose < k) || g[i].w) {
				merge(g[i].u, g[i].v);
				if (!g[i].w) chose++;
				need[i] = 1;
			}

	if (chose != k) {
		printf("no solution\n");
		return 0;
	}

	chose = 0;
	for (int i = 1; i <= m; i++)
		if (need[i])
			chose++;
	if (chose != (n - 1)) {
		printf("no solution\n");
		return 0;
	}

	for (int i = 1; i <= m; i++)
		if (need[i])
			printf("%d %d %d\n", g[i].u, g[i].v, g[i].w);

	return 0;
}