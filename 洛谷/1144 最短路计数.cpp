#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000010;
int ret, mrk; char chr;
int read() {
	ret = 0, chr = getchar(), mrk = 1;
	while (!isdigit(chr) && chr != '-') chr = getchar();
	if (chr == '-') chr = getchar(), mrk = -1;
	while (isdigit(chr)) ret = ret * 10 + chr - '0', chr = getchar();
	return ret * mrk;
}
int n, m, x, y, l, r, u, i, dis[maxn], cnt[maxn], q[maxn * 10];
vector < int > g[maxn];
int main() {
	memset(dis, 63, sizeof(dis));
	n = read(), m = read();
	for (int i = 1; i <= m; i++) {
		x = read(), y = read();
		g[x].push_back(y);
		g[y].push_back(x);
	}
	l = r = q[1] = cnt[1] = 1, dis[1] = 0;
	while (l <= r){
		u = q[l++];
		for (i = 0; i < g[u].size(); i++) 
			if (dis[u] + 1 < dis[g[u][i]]) {
				dis[g[u][i]] = dis[u] + 1;
				cnt[g[u][i]] = cnt[u];
				q[++r] = g[u][i];
			} else if (dis[u] + 1 == dis[g[u][i]]) cnt[g[u][i]] = (cnt[g[u][i]] + cnt[u]) % 100003;
	}
	for (int i = 1; i <= n; i++)
		printf("%d\n", cnt[i]);
	return 0;
}
