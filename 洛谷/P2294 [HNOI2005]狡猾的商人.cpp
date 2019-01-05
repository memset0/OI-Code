#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
const int maxm = 1010;
int n, m, w, x, y, z, l, r, u, v, cst, q[maxn * 100], dis[maxn];
bool mrk;
struct Edge {
	int e, v;
};
vector < Edge > g[maxn];
int main() {
//	freopen("trader.in", "r", stdin);
//	freopen("trader.out", "w", stdout);
	
	scanf("%d", &w);
	while(w--) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n + 1; i++)
			g[i].clear();
		for (int i = 1; i <= m; i++) {
			scanf("%d%d%d", &x, &y, &z);
			g[min(x, y)].push_back({max(x, y) + 1, z});
			//保证边是从小连到大的 
		}
		
		mrk = true;
		for (int i = 0; i < n && mrk; i++) {
			memset(dis, -1, sizeof(dis));
			dis[i] = 0, l = r = 1, q[1] = i;
			while (l <= r) {
				u = q[l++];
//				cout << u << " " << l << " " << r << endl;
				for (int i = 0; i < g[u].size(); i++) {
//					cout << "!";
					v = g[u][i].e;
					cst = g[u][i].v;
					if (dis[v] == -1)  {
						dis[v] = dis[u] + cst;
//						printf("%d ==> %d (%d)\n", u, v, cst);
						if (v <= n) q[++r] = v;
					} else if (dis[u] + cst != dis[v]) {
						mrk = false;
						break;
					} 
				}
			}
		}
		
		if (mrk) printf("true\n");
		else printf("false\n");
	}
	return 0;
}