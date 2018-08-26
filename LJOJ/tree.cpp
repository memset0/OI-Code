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

const int maxn = 1e6 + 10;

int n, u, v;
int dep[maxn], fa[maxn];

int ans;
ll  ans_sum;

int siz[maxn], psiz[maxn];
ll  sum[maxn], psum[maxn];

int tot = 2, hed[maxn], nxt[maxn << 1], to[maxn << 1];

void add_edge(int u, int v) {
	nxt[tot] = hed[u];
	to[tot] = v;
	hed[u] = tot++;
}

void dfs1(int u) {
	siz[u] = 1;
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i]) 
		if (v != fa[u]) {
			fa[v] = u;
			dep[v] = dep[u] + 1;
			dfs1(v);
			siz[u] += siz[v];
			sum[u] += siz[v] + sum[v];
		}
}

void dfs2(int u) {
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (v != fa[u]) {
			psum[v] = psum[u] + sum[u] - sum[v] - siz[v] + psiz[u] + siz[u] - siz[v];
			psiz[v] = psiz[u] + siz[u] - siz[v];
			dfs2(v);
		}
}

//void pa(int *w) {
//	for (int i = 1; i <= n; i++)
//		printf("%d ", w[i]);
//	puts("");
//}
//
//void pa(ll *w) {
//	for (int i = 1; i <= n; i++)
//		printf("%d ", w[i]);
//	puts("");
//}

int main() {
//	freopen("tree.in", "r", stdin);
//	freopen("tree.out", "w", stdout);
	
	n = read();
	for (int i = 1; i < n; i++) {
		u = read(), v = read();
		add_edge(u, v);
		add_edge(v, u);
	}
	
	dfs1(1);
	dfs2(1);
	
//	pa(siz);pa(sum);pa(psum);pa(psiz);
//	for (int i = 1; i <= n; i++)
//		printf("%d ", sum[i] + psum[i]);
//	puts("");
	
	for (int i = 1; i <= n; i++)
		if (psum[i] + sum[i] > ans_sum) {
			ans = i;
			ans_sum = psum[i] + sum[i];
		}
		
	printf("%d\n", ans);

	return 0;
}
