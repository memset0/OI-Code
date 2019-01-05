#include <bits/stdc++.h>
#define isnum(x) ('0' <= x && x <= '9')
#define read(x) do { \
	x = 0, R::c = getchar(), R::m = false; \
	while (!isnum(R::c) && R::c != '-') R::c = getchar(); \
	if (R::c == '-') R::m = true, R::c = getchar(); \
	while (isnum(R::c)) x = x * 10 + R::c - '0', R::c = getchar(); \
	if (R::m) x = -x; \
} while (false)
using namespace std;
namespace R {
	char c;
	bool m;
}

const int maxn = 10010;
int n, m, s, e, u, v, l, r, dis[maxn];
short q[maxn * 20];
bool inq[maxn], vis[maxn], able[maxn];
vector < int > G[maxn], F[maxn];
int main() {
	
	read(n); read(m);
	int tx, ty;
	for (int i = 1; i <= m; i++) {
		read(tx); read(ty);
		G[tx].push_back(ty);
		F[ty].push_back(tx);
	}
	read(s); read(e);
	
	//删除所有不与终点相连的点
	l = r = 1, q[1] = e, vis[e] = 1;
	while (l <= r) {
		u = q[l++];
		for (int i = 0; i < F[u].size(); i++) {
			v = F[u][i];
			if (!vis[v]) {
				vis[v] = 1;
				q[++r] = v;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		able[i] = 1;
		for (int j = 0; j < G[i].size(); j++)
			if (!vis[G[i][j]]) {
				able[i] = false;
				break;
			};
	}
//	for (int i = 1; i <= n; i++)
//		printf("%d", dis[i]);
//	puts("");
//	for (int i = 1; i <= n; i++)
//		printf("%d", able[i]);
//	puts("");

	memset(dis, 63, sizeof(dis));
	l = r = 1, q[1] = s, inq[s] = 1, dis[s] = 0;
	while (l <= r) {
		u = q[l++], inq[u] = false;
		for (int i = 0; i < G[u].size(); i++) {
			v = G[u][i];
			if (dis[u] + 1 < dis[v] && able[v]) {
				dis[v] = dis[u] + 1;
				if (!inq[v]) {
					q[++r] = v;
					inq[v] = 1;
				}
			}
		}
	}
	if (dis[e] == dis[0]) printf("-1\n");
	else printf("%d\n", dis[e]);
	
	return 0;
}