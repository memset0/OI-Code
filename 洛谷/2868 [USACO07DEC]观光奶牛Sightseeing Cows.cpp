#include <bits/stdc++.h>
using namespace std;

const int maxn = 1010;
struct Edge {
	int e;
	double s;
};
vector < Edge > g[maxn];
int n, m, l, r, t1, t2, t3, v[maxn], cnt[maxn], q[maxn * maxn];
bool inq[maxn], vis[maxn];
double dis[maxn];

bool Check(double X) {
	printf("%.2lf\n", X);
	memset(vis, 0, sizeof(vis));
	for (int sd = 1; sd <= n; sd++) 
		if (!vis[sd]) {
			for (int i = 1; i <= n; i++)
				cnt[i] = 0, inq[i] = 0, dis[i] = 1000000000;
			l = r = inq[sd] = cnt[sd] = 1, q[1] = sd, dis[sd] = 0;
			int u, e, s;
			while (l <= r) {
				u = q[l++], inq[u] = 0, vis[u] = 1;
	//			printf("[%d]", u);
				for (int i = 0; i < g[u].size(); i++) {
					e = g[u][i].e, s = (g[u][i].s * X) - v[e];
	//				cout << s << " ";
					if (dis[u] + s < dis[e]) {
						dis[e] = dis[u] + s;
						if (!inq[e]) {
							inq[e] = 1;
							q[++r] = e;
							cnt[e] += 1;
							if (cnt[e] == n) {
								return true;
							}
						}
					}
				}
			}
	}
	return false;
}

int main() {
	freopen("TESTDATA1.in", "r", stdin);
//	freopen("INPUT", "r", stdin);
		
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &v[i]);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &t1, &t2, &t3);
		g[t1].push_back({t2, t3});
	}
	
	double L = 0, R, Mid, Ans;
	for (int i = 1; i <= n; i++)
		if (v[i] > R)
			R = v[i];
//	cout << n << endl;
	while (L + 0.00000001 < R) {
		Mid = (L + R) / 2;
		if (Check(Mid)) Ans = Mid, L = Mid;
		else R = Mid;
	}
	
	printf("%.2lf\n", Ans);
	
	return 0;
}
