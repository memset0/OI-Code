#include <bits/stdc++.h>
#define isnum(x) ('0' <= x && x <= '9')
#define read(x) do { \
	x = 0, R::c = getchar(), R::m = 1; \
	while (!isnum(R::c) && R::c != '-') R::c = getchar(); \
	if (R::c == '-') R::c = getchar(), R::m = -1; \
	while (isnum(R::c)) x = x * 10 + R::c - '0', R::c = getchar(); \
	x *= R::m; \
} while (false) 
namespace R { char c; int m; }
using namespace std;

#define sqr(x) ( (x) * (x) )
const int maxn = 1000010;
int n, m, p, s, e, x, y, z, l, r, u, v, cst;
int a[maxn], b[maxn], dis[maxn], q[maxn];
bool inq[maxn];
struct Edge {
	int e, v;
};
vector < Edge > G[maxn];

int main() {
	
	read(n); read(m);
	for (int i = 1; i <= m; i++) {
		read(x); read(y); read(z);
		G[x].push_back( {y, z} );
		G[y].push_back( {x, z} );
	}
	read(p);
	for (int i = 1; i <= p; i++) {
		read(s); read(e);
		memset(dis, -1, sizeof(dis));
		l = r = 1, q[1] = s, inq[s] = 1, dis[s] = 100001;
		while (l <= r) {
			u = q[l++];
			inq[u] = 0;
			for (int i = 0; i < G[u].size(); i++) {
				v = G[u][i].e;
				cst = G[u][i].v;
				if (min(dis[u], cst) > dis[v]) {
					dis[v] = min(dis[u], cst); 
					if (!inq[v]) {
						inq[v] = 1;
						q[++r] = v;
					}
				}
			}
		}
		printf("%d\n", dis[e]);
	}
	
	return 0;
}
