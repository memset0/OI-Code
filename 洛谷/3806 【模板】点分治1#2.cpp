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

const int maxn = 10010, maxm = 110, maxk = 10000010, max_edge = 40010;
int n, m, u, v, w;
int full_size, root;
int ans[maxn], query[maxn];
int siz[maxn], maxp[maxn], vis[maxn], dis[maxn], mrk[maxk];
int tot = 2, hed[maxn], nxt[max_edge], to[max_edge], val[max_edge];
vector < int > rem, que;

void add_edge(int u, int v, int w) {
	nxt[tot] = hed[u], to[tot] = v, val[tot] = w, hed[u] = tot++;
}

void getroot(int u, int father = 0) {
	siz[u] = 1, maxp[u] = 0;
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (!vis[v] && v != father) {
			getroot(v, u);
			siz[u] += siz[v] ;
			maxp[u] = max(maxp[u], siz[v]);
		}
	maxp[u] = max(maxp[u], full_size - siz[u]);
	if (maxp[u] < maxp[root]) root = u;
}

void getdis(int u, int father) {
	rem.push_back(dis[u]);
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (!vis[v] && v != father) {
			dis[v] = dis[u] + val[i];
			getdis(v, u);
		}
}

void solve(int u) {
	vis[u] = 1, mrk[0] = 1, que.clear(), que.push_back(0);
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (!vis[v]) {
			rem.clear(), dis[v] = val[i], getdis(v, u);
			for (auto it = rem.begin(); it != rem.end(); it++)
				for (int t = 1; t <= m; t++)
					if (query[t] - *it >= 0 && query[t] - *it <= 10000000)
						ans[t] |= mrk[query[t] - *it];
			for (auto it = rem.begin(); it != rem.end(); it++)
				mrk[*it] = 1;
			que.insert(que.end(), rem.begin(), rem.end());
		}
	for (auto it = que.begin(); it != que.end(); it++)
		mrk[*it] = 0;
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (!vis[v]) {
			root = 0, full_size = maxp[root] = siz[v];
			getroot(v), solve(v);
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
	
	root = 0, full_size = maxp[root] = n, getroot(1);
	
	solve(root);
	
	for (int i = 1; i <= m; i++)
		if (ans[i]) printf("AYE\n");
		else printf("NAY\n");

	return 0;
}
