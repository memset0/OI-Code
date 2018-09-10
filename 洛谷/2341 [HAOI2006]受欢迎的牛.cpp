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

const int maxn = 10010, maxm = 50010;

int n, m, u, v;
int ans, tim, top;
int outd[maxn], low[maxn], dfn[maxn], stk[maxn], ins[maxn], siz[maxn], fa[maxn], ff[maxn];
int tot = 2, hed[maxn], nxt[maxm], to[maxm];

struct edge {
	int u, v;
	edge () {}
	edge (int a, int b) { u = a, v = b; }
} e[maxm];

void add_edge(int u, int v) {
	nxt[tot] = hed[u], to[tot] = v;
	hed[u] = tot++;
}

void tarjan(int u) {
	dfn[u] = low[u] = ++tim;
	ins[u] = 1, stk[++top] = u;
	for (int i = hed[u]; i; i = nxt[i]) {
		int v = to[i];
		if (!dfn[v]) {
			tarjan(v);
			low[u] = min(low[u], low[v]);
		} else {
			low[u] = min(low[u], dfn[v]);
		}
	}
	if (dfn[u] == low[u]) {
		while (top) {
			int v = stk[top--];
			fa[v] = u;
			siz[u]++;
			ins[v] = 0;
			if (u == v) break;
		}
	}
}

int find(int x) {
	if (x == ff[x]) return x;
	return ff[x] = find(ff[x]);
}

int main() {
	
	n = read(), m = read();
	for (int i = 1; i <= m; i++) {
		u = read(), v = read();
		add_edge(u, v);
		e[i] = edge(u, v);
	}
	
	for (int i = 1; i <= n; i++)
		if (!dfn[i])
			tarjan(i);
	
	tot = 2, memset(hed, 0, sizeof(hed));
	for (int i = 1; i <= n; i++)
		ff[i] = i;
	
	for (int i = 1; i <= m; i++) {
		u = e[i].u, v = e[i].v;
		if (fa[u] != fa[v]) {
			ff[find(fa[u])] = find(fa[v]);
			outd[fa[u]]++;
		}
	}

//	for (int i = 1; i <= n; i++)
//		printf("%d ", find(i));
//	puts("");
//	for (int i = 1; i <= n; i++)
//		printf("%d ", fa[i]);
//	puts("");
	
	for (int i = 1; i <= n; i++)
		if (fa[i] == i) {
			ans = find(i);
			break;
		}
	for (int i = 1; i <= n; i++)
		if (fa[i] == i) {
			if (find(i) != ans) {
				puts("0");
				return 0;
			}
		}
	
	ans = 0;
	for (int i = 1; i <= n; i++)
		if (fa[i] == i && !outd[i])
			ans = i;
	for (int i = 1; i <= n; i++)
		if (fa[i] == i && !outd[i] && i != ans) {
			puts("0");
			return 0;
		}
			
	printf("%d\n", siz[ans]);
		
	return 0;
}
