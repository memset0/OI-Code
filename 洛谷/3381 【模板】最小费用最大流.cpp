#include <bits/stdc++.h>
using namespace std;
int read() {
	int x = 0; bool m = 0; char c = getchar();
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') m = 1, c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (m) return -x; else return x;
}

void print_arr(string name, int *array, int length) {
	cout << name << " ";
	for (int i = 1; i <= length; i++)
		cout << array[i] << " ";
	cout << endl;
}

const int maxn = 5010, maxm = 100010, inf = 1e9;
int n, m, s, e, u, v, w, c, l, r;
int flow, cost, ans_flow, ans_cost;
int pre[maxn], dis[maxn], q[maxn];
int tot, hed[maxn], nxt[maxm], to[maxm], val[maxm], cst[maxm];
bool inq[maxn];

void add_edge(int u, int v, int w, int c) {
	nxt[tot] = hed[u];
	to[tot] = v;
	val[tot] = w;
	cst[tot] = c;
	hed[u] = tot;
	tot++;
}

bool spfa(void) {
	memset(dis, -1, sizeof(dis));
	memset(pre, 0, sizeof(pre));
	dis[s] = 0, pre[s] = -1, l = r = 0, inq[s] = inq[e] = 1, q[0] = s;
	while (l <= r) {
		u = q[(l++) % n], inq[u] = 0;
		// printf("u = %d, l = %d, r = %d;\n", u, l - 1, r);
		for (int i = hed[u]; ~i; i = nxt[i]) {
			if (val[i] && (dis[to[i]] > dis[u] + cst[i] || !~dis[to[i]])) {
				// printf("edge[%d] := %d => %d : %d, %d\n", i, to[i ^ 1], to[i], val[i], cst[i]);
				dis[to[i]] = dis[u] + cst[i];
				pre[to[i]] = i;
				// print_arr("pre", pre, n);
				if (!inq[to[i]]++) q[(++r) % n] = to[i];
			}
		}
	}
	return pre[e];
}

int main() {

	freopen("INPUT", "r", stdin);
	memset(hed, -1, sizeof(hed));

	n = read(), m = read(), s = read(), e = read();
	for (int i = 1; i <= m; i++) {
		u = read(), v = read(), w = read(), c = read();
		add_edge(u, v, w, c);
		add_edge(v, u, 0, -c);
	}

	// print_arr("hed", hed, n);

	while (spfa()) {
		// printf(">>> FIND A ANSWER WAY <<<\n");
		// print_arr("pre", pre, n);
		flow = inf, cost = 0;
		for (int i = pre[e]; ~i; i = pre[to[i ^ 1]])
			flow = flow < val[i] ? flow : val[i];
		for (int i = pre[e]; ~i; i = pre[to[i ^ 1]])
			val[i] -= flow, val[i ^ 1] += flow;
		for (int i = pre[e]; ~i; i = pre[to[i ^ 1]])
			cost += cst[i] * flow;
		ans_flow += flow, ans_cost += cost;
		// printf("flow: %d > %d, cost: %d > %d\n", flow, ans_flow, cost, ans_cost);
	}

	printf("%d %d\n", ans_flow, ans_cost);
	
	return 0;
}