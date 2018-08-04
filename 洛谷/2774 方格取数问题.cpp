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

#define locate(i,j) (((i) - 1) * m + (j))
const int maxn = 10010, maxm = 30100, inf = 1e9;
const int mov[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int n, m, sum, vi, vj, a[110][110];
int u, s, e, en, flow, flag, max_flow, dep[maxn], gap[maxn], pre[maxn], cur[maxn];
int tot, hed[maxn], nxt[maxm << 1], to[maxm << 1], val[maxm << 1], pri[maxm << 1];

void add_edge(int u, int v, int w) {
//	printf("%d => %d : %d\n", u, v, w);
	nxt[tot] = hed[u], to[tot] = v, pri[tot] = val[tot] = w, hed[u] = tot++;
	nxt[tot] = hed[v], to[tot] = u, pri[tot] = val[tot] = 0, hed[v] = tot++;
}

int main() {
	memset(hed, -1, sizeof(hed));
	n = read(), m = read();
	s = n * m + 1, e = n * m + 2, en = e;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			a[i][j] = read(), sum += a[i][j];
			if ((i + j) & 1) add_edge(s, locate(i, j), a[i][j]);
			else add_edge(locate(i, j), e, a[i][j]);
			for (int t = 0; t < 4; t++) {
				vi = i + mov[t][0];
				vj = j + mov[t][1];
				if (vi < 1 || vj < 1 || vi > n || vj > m) continue;
				if ((i + j) & 1) add_edge(locate(i, j), locate(vi, vj), inf);
				else add_edge(locate(vi, vj), locate(i, j), inf);
			}
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
	printf("%d\n", sum - max_flow);
	return 0;
}
