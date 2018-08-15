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

const int maxn = 40010;
int n, m, k, u, v, w, ans;
int root, full_size;
int maxp[maxn], rem[maxn], size[maxn], dep[maxn], vis[maxn];
int tot = 2, hed[maxn], nxt[maxn << 1], to[maxn << 1], val[maxn << 1];

void add_edge(int u, int v, int w) {
	nxt[tot] = hed[u], to[tot] = v, val[tot] = w, hed[u] = tot++;
}

void getroot(int u, int father = 0) {
//	printf("getroot %d %d : %d\n", u, father, root);
	size[u] = 1, maxp[u] = 0;
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (!vis[v] && v != father) {
			getroot(v, u);
			size[u] += size[v];
			maxp[u] = max(maxp[u], size[v]);
		}
	maxp[u] = max(maxp[u], full_size - size[u]);
	if (maxp[u] < maxp[root]) root = u;
}

void getdeep(int u, int father = 0) {
	rem[++rem[0]] = dep[u];
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (!vis[v] && v != father) {
			dep[v] = dep[u] + val[i];
			getdeep(v, u);
		}
}

int calc(int u, int pri_val) {
	rem[0] = 0, dep[u] = pri_val;
	getdeep(u);
	sort(rem + 1, rem + rem[0] + 1);
	int l = 1, r = rem[0], ret = 0;
	while (l < r) {
		if (rem[l] + rem[r] <= k) ret += r - l, l++;
		else r--;
	}
//	printf("ret = %d\n", ret);
//	for (int i = 1; i <= rem[0]; i++)
//		printf("%d ", rem[i]);
//	puts("");
	return ret;
}

void solve(int u) {
//	printf("=== solve %d ===\n", u);
//	printf("ans = %d\n", ans);
	vis[u] = 1, ans += calc(u, 0);
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (!vis[v]) {
			ans -= calc(v, val[i]);
		}
//	printf("ans = %d\n", ans);
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (!vis[v]) {
			root = 0, full_size = maxp[root] = size[v];
			getroot(v), solve(root);
		}
}

int main() {
//	freopen("INPUT", "r", stdin);
	
	n = read();
	for (int i = 1; i < n; i++) {
		u = read(), v = read(), w = read();
		add_edge(u, v, w), add_edge(v, u, w);
	}
	k = read();
	
	root = 0, full_size = maxp[root] = n;
	getroot(1), solve(root);
	
	printf("%d\n", ans);

	return 0;
}
