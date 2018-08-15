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

const int maxn = 10010, maxm = 110, maxk = 10000010, max_edge = 20010;
int n, m, u, v, w, ans[maxm], query[maxm];
int root, len_rem, len_que, fullsize;
int siz[maxn], rem[maxn], que[maxn], dis[maxn], vis[maxn], maxp[maxn], mrk[maxk];
int tot = 2, hed[maxn], nxt[max_edge], to[max_edge], val[max_edge];

void add_edge(int u, int v, int w) {
	nxt[tot] = hed[u], to[tot] = v, val[tot] = w, hed[u] = tot++;
}

void getroot(int u, int father) {
	siz[u] = 1, maxp[u] = 0;
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (!vis[v] && v != father) {
			getroot(v, u);
			siz[u] += siz[v];
			maxp[u] = max(maxp[u], siz[v]); // 来自子树 
		}
	maxp[u] = max(maxp[u], fullsize - siz[u]); // 来自父亲 
	if (maxp[u] < maxp[root]) root = u;
}

void getdis(int u, int father) {
	rem[++len_rem] = dis[u];
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (!vis[v] && v != father) {
			dis[v] = dis[u] + val[i];
			getdis(v, u);
		}
}

void solve(int u) {
	vis[u] = mrk[0] = 1;
	len_que = 0;
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (!vis[v]) {
			len_rem = 0, dis[v] = val[i];
			getdis(v, u);
			for (int t = 1; t <= m; t++)
				for (int k = 1; k <= len_rem; k++)
					if (query[t] - rem[k] >= 0 && query[t] - rem[k] <= 10000000)
						ans[t] |= mrk[query[t] - rem[k]];
			for (int k = 1; k <= len_rem; k++)
				mrk[rem[k]] = 1, que[++len_que] = rem[k];
		}
	for (int i = 1; i <= len_que; i++)
		mrk[que[i]] = 0;
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (!vis[v]) {
			fullsize = siz[v], root = 0, maxp[root] = n;
			getroot(v, 0), solve(root);
		}
}

int main() {
//	freopen("INPUT", "r", stdin);
	
	n = read(), m = read();
	for (int i = 1; i < n; i++) {
		u = read(), v = read(), w = read();
		add_edge(u, v, w), add_edge(v, u, w);
	}
	for (int i = 1; i <= m; i++)
		query[i] = read();
	
	maxp[root] = fullsize = n;
	getroot(1, 0);
	
	solve(root);
	
	for (int i = 1; i <= m; i++)
		if (ans[i]) printf("AYE\n");
		else printf("NAY\n");
	
	return 0;
}

