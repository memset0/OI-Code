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

const int maxn = 310;

int n, s;
int tot = 2, hed[maxn], nxt[maxn << 1], to[maxn << 1], val[maxn << 1];

void add_edge(int u, int v, int w)  {
	nxt[tot] = hed[u], to[tot] = v, val[tot] = w;
	hed[u] = tot++;
}

void bfs(int s) {
	l = r = 1, q[1] = s, 
}

int main() {
	n = read(), m = read();
	for (int i = 1; i < n; i++) {
		u = read(), v = read(), w = read();
		add_edge(u, v, w), add_edge(v, u, w);
	}
	bfs(1);
	return 0;
}
