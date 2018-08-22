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

const int maxn = 200010, maxk = 1000010, inf = 1061109567;
int n, k, u, v, w;
int root, full_size, len, ans = inf;
int siz[maxn], maxp[maxn], mrk[maxk], vis[maxn], dis[maxn], stp[maxn], rem[maxn], cst[maxn], toc[maxn];
int tot = 2, hed[maxn], nxt[maxn << 1], to[maxn << 1], val[maxn << 1];

void add_edge(int u, int v, int w) {
	nxt[tot] = hed[u], to[tot] = v, val[tot] = w, hed[u] = tot++;
}

#define v to[i]

void getroot(int u, int father = 0) {
	siz[u] = 1, maxp[u] = 0;
	for (int i = hed[u]; i; i = nxt[i])
		if (!vis[v] && v != father) {
			getroot(v, u);
			siz[u] += siz[v];
			maxp[u] = max(maxp[u], siz[v]);
		}
	maxp[u] = max(maxp[u], full_size - siz[u]);
	if (maxp[u] < maxp[root]) root = u;
}

void getdis(int u, int father = 0) {
//	printf("getdis %d\n", u);
	if (dis[u] > k || stp[u] > ans) return;
	len++, rem[len] = dis[u], cst[len] = stp[u];
	for (int i = hed[u]; i; i = nxt[i])
		if (!vis[v] && v != father) {
			dis[v] = dis[u] + val[i], stp[v] = stp[u] + 1;
			getdis(v, u);
		}
}

void solve(int u) {
//	printf("=== solve %d ===\n", u);
	vis[u] = 1, mrk[0] = 0, toc[0] = 1, toc[1] = 0;
	for (int i = hed[u]; i; i = nxt[i])
		if (!vis[v]) {
			len = 0, stp[v] = 1, dis[v] = val[i], getdis(v);
			for (int i = 1; i <= len; i++)
				if (k - rem[i] >= 0 && k - rem[i] <= 1e6)
					ans = min(ans, mrk[k - rem[i]] + cst[i]);
			for (int i = 1; i <= len; i++)
				mrk[rem[i]] = min(mrk[rem[i]], cst[i]), toc[++toc[0]] = rem[i];
//			for (int i = 1; i <= len; i++)
//				printf("%d,%d ", rem[i], cst[i]);
//			puts("");
		}
	for (int i = 1; i <= toc[0]; i++)
		mrk[toc[i]] = inf;
	for (int i = hed[u]; i; i = nxt[i])
		if (!vis[v]) {
			root = 0, full_size = maxp[root] = siz[v];
			getroot(v), solve(root);
		}
}

#undef v

int main() {
	// freopen("INPUT", "r", stdin);
	memset(mrk, 63, sizeof(mrk));

	n = read(), k = read();
	for (int i = 1; i < n; i++) {
		u = read() + 1, v = read() + 1, w = read();
		add_edge(u, v, w), add_edge(v, u, w);
	}
	
	root = 0, full_size = maxp[root] = n;
	getroot(1), solve(root);
	
	if (ans == inf) printf("-1\n");
	else printf("%d\n", ans);
	
	return 0;
}

