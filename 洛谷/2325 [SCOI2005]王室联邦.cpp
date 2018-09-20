// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long

int read() {
	int x = 0; bool m = 0; char c = getchar();
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') m = 1, c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (m) return -x; else return x;
}

const int maxn = 1010;

int n, m, u, v, pos, top;
int ans[maxn], stk[maxn], center[maxn];

int tot = 2, hed[maxn], nxt[maxn << 1], to[maxn << 1];
void add_edge(int u, int v) { nxt[tot] = hed[u], to[tot] = v, hed[u] = tot++; }

void dfs(int u, int father) {
	int bottom = top;
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (v != father) {
			dfs(v, u);
			if (top - bottom >= m) {
				++pos, center[pos] = u;
//				printf(">>> %d %d %d %d\n", pos, u, top, center[pos]);
				while (top > bottom) {
					int v = stk[top--];
					ans[v] = pos;
				}
			}
		}
	stk[++top] = u;
}

int main() {

	n = read(), m = read();
	for (int i = 1; i < n; i++) {
		u = read(), v = read();
		add_edge(u, v);
		add_edge(v, u);
	}
	
	dfs(1, 0);
	if (top) {
		while (top) {
			int v = stk[top--];
			ans[v] = pos;
		}
	} 
	
	printf("%d\n", pos);
	for (int i = 1; i <= n; i++)
		printf("%d ", ans[i]);
	puts("");
	for (int i = 1; i <= pos; i++)
		printf("%d ", center[i]);
	puts("");
	
	return 0;
}
