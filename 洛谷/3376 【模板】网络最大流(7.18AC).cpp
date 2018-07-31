#include <bits/stdc++.h>
using namespace std;
int read() {
	int x = 0; bool m = 0; char c = getchar();
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') m = 1, c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (m) return -x; else return x;
}

const int maxn = 10010, maxm = 200010, INF = 2e9 + 10;
int n, m, s, e, u, v, w, flow, ans, minn, pre[maxn], cur[maxn], dep[maxn], gap[maxn];
int tot = -1, nxt[maxm], hed[maxn], to[maxm], val[maxm];
bool flag;

void add_edge(int u, int v, int w) {
	// printf("ADD EDGE %d => %d : %d\n", u, v, w);
	nxt[++tot] = hed[u];
	to[tot] = v;
	val[tot] = w;
	hed[u] = tot;
}

inline void print(string s, int *a, int n) {
    cout << s;
    for (int i = 1; i <= n; i++)
        printf("%3d", a[i]);
    putchar('\n');
}

int main() {

	// freopen("INPUT", "r", stdin);
	memset(hed, -1, sizeof(hed));

	n = read(), m = read(), s = read(), e = read();
	for (int i = 1; i <= m; i++) {
		u = read(), v = read(), w = read();
		add_edge(u, v, w);
		add_edge(v, u, 0);
	}

	// for (int i = 0; i <= tot; i++)
	// 	cout << to[i] << " ";
	// cout << endl;

	u = s, pre[u] = -1, gap[0] = n;
	for (int i = 1; i <= n; i++)
		cur[i] = hed[i];

	while (dep[u] < n) {

		// cout << u << endl;

		if (u == e) {

			// printf("FIND A WAY OUT\n");
			// for (int i = 0; i <= tot; i++)
			// 	cout << val[i] << ' ';
			// cout << endl;
			flow = INF;
			for (int i = pre[u]; ~i; i = pre[to[i ^ 1]])
				if (val[i] < flow) flow = val[i];
			for (int i = pre[u]; ~i; i = pre[to[i ^ 1]])
				val[i] -= flow, val[i ^ 1] += flow;
			// for (int i = 0; i <= tot; i++)
			// 	cout << val[i] << ' ';
			// cout << endl;
			u = s, ans += flow;

		} else {

			flag = false;
			for (int i = cur[u]; ~i; i = nxt[i]) 
				if (val[i] > 0 && dep[u] == dep[to[i]] + 1) {
					pre[to[i]] = i;
					flag = true;
					// printf("MOVE %d => %d\n", u, to[i]);
					u = to[i];
					break;
				}

			if (!flag) {
				// printf("REFRESH DEPTH\n");
				minn = n;
				for (int i = hed[u]; ~i; i = nxt[i]) {
					// printf("FINDING id=%d to=%d val=%d\n", i, to[i], val[i]);
					if (val[i] > 0 && dep[to[i]] < minn)
						minn = dep[to[i]], cur[u] = i;
				}
				// cout << u << " " << dep[u] << endl;
				// for (int i = 0; i <= n; i++)
				// 	cout << dep[i] << " ";
				// cout << endl;
				// for (int i = 0; i <= n; i++)
				// 	cout << gap[i] << " ";
				// cout << endl;
				if (!--gap[dep[u]]) break;
				++gap[dep[u] = ++minn];
				if (u != s) u = to[pre[u] ^ 1];
			}

		}
	}

	printf("%d\n", ans);

	return 0;
}