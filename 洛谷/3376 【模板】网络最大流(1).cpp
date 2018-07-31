#include <bits/stdc++.h>
using namespace std;
int read() {
	int x = 0; bool m = 0; char c = getchar();
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') m = 1, c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (m) return -x; else return x;
}
const int maxn = 210, INF = 1e9 + 10;
int n, m, s, t, i, tu, tv, tw, ans, flow, tmp, minn, adv;
int p[maxn], d[maxn], w[maxn], pre[maxn], hsh[maxn], G[maxn][maxn];
bool flag;
int main() {
	// freopen("INPUT", "r", stdin);
	n = read(), m = read(), s = read(), t = read();
	for (int i = 1; i <= m; i++) {
		tu = read(), tv = read(), tw = read();
		G[tu][tv] = tw;
	}
	for (int i = 1; i <= n; i++)
		p[i] = 1;
	hsh[0] = n, ans = 0, flow = INF, i = s;
	while (d[s] < n) {
		w[i] = flow, flag = 0;
		for (int j = p[i]; j <= n; j++)
			if (G[i][j] > 0 && d[i] == d[j] + 1) {
				flag = 1, p[i] = j;
				flow = min(flow, G[i][j]);
				pre[j] = i;
				i = j;
				if (i == t) {
					ans += flow;
					while (i != s) {
						tmp = i;
						i = pre[i];
						G[i][tmp] -= flow;
						G[tmp][i] += flow;
					}
					flow = INF;
				}
				break;
			}
		if (!flag) {
			minn = n - 1;
			for (int j = 1; j <= n; j++)
				if (G[i][j] && d[j] < minn)
					adv = j, minn = d[j];
			p[i] = adv, hsh[d[i]]--;
			if (!hsh[d[i]]) break;
			d[i] = minn + 1, hsh[d[i]]++;
			if (i != s) i = pre[i], flow = w[i];
		}
	}
	printf("%d\n", ans);
	return 0;
}