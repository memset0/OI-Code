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
int n, m, u, v, fu, fv, opt;
int fa[maxn], ch[maxn][2], val[maxn], dis[maxn];

int find(int x) {
	while (fa[x]) x = fa[x];
	return x;
}

int merge(int x, int y) {
	// printf("merge %d %d\n", x, y);
	if (!x || !y) return x | y;
	if (val[x] > val[y] || (val[x] == val[y] && x > y)) swap(x, y);
	ch[x][1] = merge(ch[x][1], y);
	fa[ch[x][1]] = x;
	if (dis[ch[x][1]] > dis[ch[x][0]])
		swap(ch[x][0], ch[x][1]);
	dis[x] = dis[ch[x][1]] + 1;
	return x;
}

int main() {
	// freopen("INPUT", "r", stdin);
	// freopen("OUTPUT", "w", stdout);

	n = read(), m = read();
	for (int i = 1; i <= n; i++)
		val[i] = read();
	dis[0] = -1;
	for (int i = 1; i <= m; i++) {
		opt = read();
		if (opt == 1) {
			u = read(), fu = find(u);
			v = read(), fv = find(v);
			if (val[u] != -1 && val[v] != -1 && fu != fv) {
				merge(fu, fv);
			}
		} else {
			u = read(), fu = find(u);
			if (~val[u]) {
				printf("%d\n", val[fu]);
				val[fu] = -1, fa[ch[fu][0]] = fa[ch[fu][1]] = 0;
				merge(ch[fu][0], ch[fu][1]);
			} else {
				printf("-1\n");
			}
		}
		// for (int i = 1; i <= n; i++)
		// 	printf("%d ", fa[i]);
		// puts("");
	}

	return 0;
}	