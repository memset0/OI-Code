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

char readc() {
	char c = getchar();
	while (c != 'A' && c != 'C') c = getchar();
	return c;
}

const int maxn = 200010, maxm = 200010, inf = 1e9;

int n, m, k, u, v, w;
int cnt, core, full, from;
int max[maxn], vis[maxn], pre[maxn], old[maxn], siz[maxn], a[maxn];

std::vector < int > vec[maxn], dis[maxn];

struct Heap {
	std::priority_queue < int > ins, del;
	void update() {
		while (ins.size() && del.size())
			if (ins.top() == del.top()) ins.pop(), del.pop();
			else break;
	}
	void push(int x) { ins.push(x); }
	void pop(int x) { del.push(x); }
	int top() { update(); return ins.size() ? ins.top() : -inf; }
	int query() {
		if (ins.size() - del.size() < 2) return 0;
		int tmp1 = top(); pop(tmp1);
		int tmp2 = top(); push(tmp1);
		return std::max(tmp1 + tmp2, 0);
	}
} ans, hep[maxn],son[maxm];

int tot = 2, hed[maxn], nxt[maxm], to[maxm], val[maxm];
void add_edge(int u, int v, int w) {
	nxt[tot] = hed[u], to[tot] = v, val[tot] = w;
	hed[u] = tot++;
}

void dfs(int u, int father, int udis) {
	max[u] = 0, siz[u] = 1;
	if (~from) {
		dis[u].push_back(udis);
		vec[u].push_back(from);
		son[from].push(udis);
	}
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (v != father && !vis[v]) {
			dfs(v, u, udis + val[i]);
			siz[u] += siz[v];
			max[u] = std::max(max[u], siz[v]);
		}
	max[u] = std::max(max[u], full - siz[u]);
	if (max[u] < max[core]) core = u;
}

void solve(int u, int father = 0) {
	vis[u] = 1;
	hep[u].push(0);
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (!vis[v] && v != father) {
			from = i, core = 0, max[core] = inf, full = siz[v];
			dfs(v, u, 0);
			pre[core] = i;
			solve(core, u);
			old[i] = son[i].top();
			hep[u].push(old[i] + val[i]);
		}
	ans.push(hep[u].query());
}

void insert(int u) {
	ans.pop(hep[u].query());
	hep[u].push(0);
	ans.push(hep[u].query());
	for (int i = 0; i < (int)vec[u].size(); i++)
		son[vec[u][i]].push(dis[u][i]);
	for (int i = pre[u]; i; i = pre[u]) {
		u = to[i ^ 1];
		if (old[i] ^ son[i].top()) {
			ans.pop(hep[u].query());
			hep[u].pop(old[i] + val[i]);
			hep[u].push(son[i].top() + val[i]);
			ans.push(hep[u].query());
			old[i] = son[i].top();
		}
	}
}

void erase(int u) {
	ans.pop(hep[u].query());
	hep[u].pop(0);
	ans.push(hep[u].query());
	for (int i = 0; i < (int)vec[u].size(); i++)
		son[vec[u][i]].pop(dis[u][i]);
	for (int i = pre[u]; i; i = pre[u]) {
		u = to[i ^ 1];
		if (old[i] ^ son[i].top()) {
			ans.pop(hep[u].query());
			hep[u].pop(old[i] + val[i]);
			hep[u].push(son[i].top() + val[i]);
			ans.push(hep[u].query());
			old[i] = son[i].top();
		}
	}
}

int main() {

	n = read();
	for (int i = 1; i < n; i++)  {
		u = read(), v = read(), w = read();
		add_edge(u, v, w), add_edge(v, u, w);
	}
	
	full = cnt = n, from = -1, core = 0, max[core] = inf;
	dfs(1, 0, 0);
	solve(1); 
	
	m = read();
	for (int i = 1; i <= m; i++)
		if (readc() == 'A') {
			if (cnt) printf("%d\n", cnt == 1 ? 0 : ans.top());
			else printf("They have disappeared.\n");
		} else {
			k = read(), a[k] ^= 1;
			if (a[k]) cnt--, erase(k);
			else cnt++, insert(k);
		}

	return 0;
}

