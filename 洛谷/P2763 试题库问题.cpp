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

const int maxn = 1030, maxm = 20100, inf = 1e9;
int k, n, m, x, p;
int u, s, e, en, flow, flag, max_flow, dep[maxn], gap[maxn], pre[maxn], cur[maxn];
int tot, hed[maxn], nxt[maxm << 1], to[maxm << 1], val[maxm << 1], pri[maxm << 1];
void add_edge(int u, int v, int w) {
	nxt[tot] = hed[u], to[tot] = v, pri[tot] = val[tot] = w, hed[u] = tot++;
	nxt[tot] = hed[v], to[tot] = u, pri[tot] = val[tot] = w, hed[v] = tot++;
}
int main() {
	memset(hed, -1, sizeof(hed));
	k = read(), n = read();
	s = k + n + 1, e = k + n + 2, en = e;
	for (int i = 1; i <= k; i++)
		x = read(), m += x, add_edge(s, i, x);
	for (int i = 1; i <= n; i++) {
		p = read();
		for (int j = 1; j <= p; j++)
			x = read(), add_edge(x, i + k, 1);
		add_edge(i + k, e, 1);
	}
	for (int i = 1; i <= en; i++)
		cur[i] = hed[i];
	u = s, pre[u] = -1, gap[0] = en;
	while (dep[u] < en) {
//		printf(">>> %d\n", u);
		flag = 0;
		for (int &i = cur[u]; ~i; i = nxt[i])
			if (val[i] && dep[u] == dep[to[i]] + 1) {
				pre[to[i]] = i;
				u = to[i];
				flag = 1;
				break;
			}
		if (!flag) {
			if (!--gap[dep[u]]) break;
//			printf("REFRESH DEPTH\n");
			dep[u] = en;
			for (int i = hed[u]; ~i; i = nxt[i]) {
//				printf("[%d]", i);
				if (val[i] && dep[to[i]] + 1 < dep[u]) {
					dep[u] = dep[to[i]] + 1;
					cur[u] = i;
				}
			}
			++gap[dep[u]];
			if (u != s) u = to[pre[u] ^ 1];
		}
		if (u == e) {
//			printf("FIND ANSWER\n");
			flow = inf;
			for (int i = pre[u]; ~i; i = pre[to[i ^ 1]])
				flow = min(flow, val[i]);
			for (int i = pre[u]; ~i; i = pre[to[i ^ 1]])
				val[i] -= flow, val[i ^ 1] += flow;
			max_flow += flow, u = s;
		}
	}
//	printf("%d\n", max_flow);
	if (max_flow < m) printf("No Solution!\n");
	else {
		for (int i = 1; i <= k; i++) {
			printf("%d: ", i);
			for (int j = hed[i]; ~j; j = nxt[j])
				if (to[j] != s && !val[j])
					printf("%d ", to[j] - k);
			putchar('\n');
		}
	}
	return 0;
}
