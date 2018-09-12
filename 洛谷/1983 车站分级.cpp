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

int n, m, t, max;
int a[maxn], b[maxn], ans[maxn], ind[maxn], G[maxn][maxn];

void dfs(int u) {
	for (int v = 1; v <= n; v++)
		if (G[u][v]) {
			ans[v] = std::max(ans[v], ans[u] + 1);
			ind[v]--;
			if (!ind[v]) {
				dfs(v);
			}
		}
}

int main() {
	
	n = read(), m = read();
	for (int i = 1; i <= m; i++) {
		t = read();
		for (int i = 1; i <= t; i++)
			b[i] = read(), a[b[i]] = 1;
		for (int i = b[1]; i <= b[t]; i++)
			if (a[i])
				for (int j = b[1]; j <= b[t]; j++)
					if (!a[j])
						G[j][i] = 1;
		for (int i = 1; i <= t; i++)
			a[b[i]] = 0;
	}
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (G[j][i])
				ind[i]++;
	for (int i = 1; i <= n; i++)
		if (!ind[i]) {
			ans[i] = 1;
			dfs(i);
		}
		
	for (int i = 1; i <= n; i++)
		max = std::max(max, ans[i]);
	printf("%d\n", max);
	
	return 0;
}
