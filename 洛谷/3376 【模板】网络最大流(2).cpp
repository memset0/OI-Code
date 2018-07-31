#include <bits/stdc++.h>
using namespace std;
int read() {
	int x = 0; bool m = 0; char c = getchar();
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') m = 1, c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (m) return -x; else return x;
}
const int maxn = 10010, maxm = 100010, INF = 1e9 + 10;
int n, m, s, t, i, tu, tv, tw, ans, flow, tmp, minn, adv;
int cur[maxn], d[maxn], w[maxn], pre[maxn], hsh[maxn];
int pos = -1, hed[maxn], nxt[maxm << 1];
struct Edge {
	int to, dis;
} g[maxm << 1];
bool flag;
void link(int u, int v, int w) {
	nxt[++pos] = hed[u];
	hed[u] = pos;
	g[pos] = {v, w};
}
int main() {
	freopen("INPUT", "r", stdin)
	n = read(), m = read(), s = read(), t = read();
	for (int i = 1; i <= m; i++) {
		tu = read(), tv = read(), tw = read();
		link(tu, tv, tw);
		link(tv, tu, 0);
	}
	for (int i = 1; i <= n; i++)
		cur[i] = hed[i];
	hsh[0] = n, ans = 0, flow = INF, i = s;
	while (d[s] < n) {
		cout << ">>> " << i << endl;
		w[i] = flow, flag = 0;
		for (int j = cur[i]; j; j = nxt[j])
			if (g[j].dis > 0 && d[i] == d[g[j].to] + 1) {
				cout << i << " " << j << endl;
				flag = 1, cur[i] = j;
				flow = min(flow, g[j].dis);
				pre[g[j].to] = j ^ 1;
				i = g[j].to;
				if (i == t) {
					ans += flow;
					while (i != s) {
						g[pre[i]].dis += flow;
						g[pre[i] ^ 1].dis -= flow;
						i = g[pre[i]].to;
					}
					cout << "ans" << i << endl;
					flow = INF;
				}
				break;
			}
		if (!flag) {
			cout << i << " " << "Flag!" << endl;
			minn = n - 1;
			for (int j = hed[i]; j; j = nxt[j])
				if (g[j].dis && d[g[j].to] < minn)
					cur[i] = j, minn = d[g[j].to];
			hsh[d[i]]--;
			if (!hsh[d[i]]) break;
			hsh[d[i]]++;
			d[i] = minn + 1;
			if (i != s) i = g[pre[i]].to, flow = w[i];
		}
	}
	printf("%d\n", ans);
	return 0;
}
