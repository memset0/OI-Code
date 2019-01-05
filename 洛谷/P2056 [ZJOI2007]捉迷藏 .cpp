// luogu-judger-enable-o2
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
	while (c != 'G' && c != 'C') c = getchar();
	return c;
}

const int maxn = 500010, maxm = 500010;
const int inf = 1e9;

int n, m, u, v, k, w, cnt, a[maxn];
int core, root, from, full;
int max[maxn], siz[maxn], vis[maxn], pre[maxn], old[maxm];
std::vector < int > vec[maxn], dis[maxn];

struct Heap {
	std::priority_queue < int > ins, del;
	void update() {
		while (ins.size() && del.size())
			if (ins.top() == del.top()) {
				ins.pop(), del.pop();
			} else break;
	}
	void push(int x) { ins.push(x); }
	void pop(int x) { del.push(x); }
	int top() { update(); return ins.size() ? ins.top() : -inf; }
	int size() { return ins.size() - del.size(); }
	int query() {
		if (size() < 2) return 0; 
		int tmp1 = top();
		pop(tmp1);
		int tmp2 = top();
		push(tmp1);
		return std::max(tmp1 + tmp2, 0); 
	}
} ans, hep[maxn], son[maxm];

int tot = 2, hed[maxn], nxt[maxm], to[maxm], val[maxm];

void add_edge(int u, int v, int w)  {
	nxt[tot] = hed[u], to[tot] = v, val[tot] = w;
	hed[u] = tot++;
}

void dfs(int u, int father, int udis) {
	max[u] = 0, siz[u] = 1;
	if (~from) {
		vec[u].push_back(from);
		dis[u].push_back(udis);
		son[from].push(udis);
	}
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (v != father && !vis[v]) {
			dfs(v, u, udis + val[i]);
			siz[u] += siz[v];
			max[u] = std::max(max[u], siz[v]);
		}
	max[u] = std::max(max[u], full - siz[u]);
	if (max[core] > max[u]) core = u;
}

void solve(int u, int father) {
	vis[u] = true;
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (v != father && !vis[v]) {
			core = 0, full = siz[v], from = i, max[core] = inf;
			dfs(v, u, 0);
			pre[core] = i;
			solve(core, u);
			hep[u].push(son[i].top() + val[i]);
			old[i] = son[i].top();
		}
	hep[u].push(0);
	ans.push(hep[u].query());
}

void insert(int u) {
	ans.pop(hep[u].query());
	hep[u].push(0);
	ans.push(hep[u].query());
	for (int i = 0; i < (int)vec[u].size(); i++)
		son[vec[u][i]].push(dis[u][i]);
	for (int i = pre[u]; ~i; i = pre[u]) {
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
	for (int i = pre[u]; ~i; i = pre[u]) {
		u = to[i ^ 1];
//		printf("%d %d %d %d %d %d\n", u, i, old[i], old[i ^ 1], son[i].top(), son[i ^ 1].top());
		if (old[i] ^ son[i].top()) {
			ans.pop(hep[u].query());
			hep[u].pop(old[i] + val[i]);
			hep[u].push(son[i].top() + val[i]);
//			printf("%d -> %d\n", old[i] + val[i], son[i].top() + val[i]);
			ans.push(hep[u].query());
			old[i] = son[i].top();
		}
	} 
}

int main() {
//	freopen("INPUT", "r", stdin);
	
	n = read();
	for (int i = 1; i < n; i++) {
		u = read(), v = read(), w = 1;
		add_edge(u, v, w);
		add_edge(v, u, w);
	}
	
	max[0] = inf, full = n, from = -1;
	dfs(1, 0, 0);
	pre[core] = -1;
	solve(core, 0);

	m = read();
	cnt = n;	
	for (int i = 1; i <= m; i++) {
		if (readc() == 'G') {
//			printf(">>> G\n");
			if (cnt) printf("%d\n", (cnt - 1) && ans.size() ? ans.top() : 0);
			else printf("-1\n");
		} else {
			k = read();
//			printf(">>> C %d\n", k);
			if (a[k]) {
				cnt++, a[k] = 0;
				insert(k);
			} else {
				cnt--, a[k] = 1;
				erase(k);
			}
		}
	}
	
	return 0;
}
