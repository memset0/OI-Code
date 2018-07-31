#include <bits/stdc++.h>
using namespace std;
int read() {
	int x = 0; char c = getchar(); bool m = 0;
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') c = getchar(), m = 1;
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (m) return -x; else return x;
}
const int maxn = 200010;
int n, u, v, cnt, i, pos, ans, dis[maxn], id[maxn], nxt[maxn];
int main() {
	n = read(), ans = n;
	for (i = 1; i <= n; ++i)
		nxt[i] = read();
	for (i = 1; i <= n; ++i)
		if (!id[i]) {
			++pos, u = i;
			while (!id[u])
				id[u] = pos, u = nxt[u];
			if (id[u] == pos) {
				v = nxt[u], cnt = 0;
				while (v != u) v = nxt[v], ++cnt;
				if (cnt < ans) ans = cnt;
			}
		}
	printf("%d\n", ++ans);
	return 0;
}
