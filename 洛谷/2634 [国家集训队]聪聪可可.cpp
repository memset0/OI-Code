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

const int maxn = 20010;
int n, u, v, w, ans;
int root, full_size;
int size[maxn], maxp[maxn], vis[maxn], rem[3], mrk[3], dis[maxn];
int tot = 2, hed[maxn], nxt[maxn << 1], to[maxn << 1], val[maxn << 1];

void add_edge(int u, int v, int w) {
	nxt[tot] = hed[u], to[tot] = v, val[tot] = w, hed[u] = tot++;
}

void getroot(int u, int father = 0) {
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

void getdis(int u, int father = 0) {
	rem[dis[u] % 3]++;
//	printf("getdis %d -> %d : %d\n", father, u, dis[u]);
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (!vis[v] && v != father) {
			dis[v] = dis[u] + val[i];
			getdis(v, u);
		}
}

void solve(int u) {
//	printf("=== solve %d ===\n", u);
	vis[u] = 1, mrk[0] = 1, mrk[1] = mrk[2] = 0;
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (!vis[v]) {
			rem[0] = rem[1] = rem[2] = 0, dis[v] = val[i];
			getdis(v);
//			printf(">>>%4d%4d%4d\n   %4d%4d%4d\n", mrk[0], mrk[1], mrk[2], rem[0], rem[1], rem[2]);
			ans += mrk[0] * rem[0] + mrk[1] * rem[2] + mrk[2] * rem[1];
			mrk[0] += rem[0], mrk[1] += rem[1], mrk[2] += rem[2];
		}
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (!vis[v]) {	
			root = 0, full_size = maxp[root] = size[v];
			getroot(v), solve(root);
		}
}

void print(int a, int b) {
	int gcd = __gcd(a, b);
	a /= gcd, b /= gcd;
	printf("%d/%d\n", a, b);
}

int main() {
//	freopen("INPUT", "r", stdin);
	
	n = read();
	for (int i = 1; i < n; i++) {
		u = read(), v = read(), w = read();
		add_edge(u, v, w), add_edge(v, u, w);
	}
	
	root = 0, full_size = maxp[root] = n;
	getroot(1), solve(root);
	
	print(n + (ans << 1), n * n);

	return 0;
}

