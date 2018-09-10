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

const int maxn = 510, maxm = 5010;

int n, m, st, ed;

struct edge {
	int u, v, w;
} g[maxm];

struct answer {
	int x, y;
	answer () {}
	answer (int a, int b) { x = a, y = b; }
} ans;

bool operator < (answer a, answer b) {
	if (!a.y) return 0;
	if (!b.y) return 1;
	return a.x / (double)a.y < b.x / (double)b.y;
}

int cnt, now;
int fa[maxn]; 

bool cmp(edge a, edge b) {
	return a.w < b.w;
}

int find(int x) {
	if (x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}
 
int main() {
	n = read(), m = read();
	for (int i = 1; i <= m; i++) {
		g[i].u = read();
		g[i].v = read();
		g[i].w = read();
	}
	st = read(), ed = read();
	sort(g + 1, g + m + 1, cmp);
	
	ans = answer(0, 0);
	for (int i = 1; i <= m; i++) {
		for (int i = 1; i <= n; i++)
			fa[i] = i;
		cnt = now = 0;
		for (int j = i; j <= m; j++)
			if (find(g[j].u) != find(g[j].v)) {
				fa[find(g[j].u)] = find(g[j].v);
//				printf(">> %d %d\n", find(st), find(ed));
				if (find(st) == find(ed)) {
					if (answer(g[j].w, g[i].w) < ans)
						ans = answer(g[j].w, g[i].w);
				}
			}
	}
	if (!ans.y) {
		printf("IMPOSSIBLE\n");
		return 0;
	}
	int tmp = __gcd(ans.x, ans.y);
	ans.x /= tmp, ans.y /= tmp;
	if (ans.y ^ 1) printf("%d/%d\n", ans.x, ans.y);
	else printf("%d\n", ans.x);
	return 0;
}

