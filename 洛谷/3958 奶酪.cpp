#include <bits/stdc++.h> 
#define isNum(c) ('0'<=c&&c<='9')
using namespace std;
const int maxn = 1010;
long long x[maxn], y[maxn], z[maxn], fa[maxn];
long long t, n, h, r;
bool mark, dis[maxn];
long long find(int x) {
	if (fa[x] == x) return x;
	else return fa[x] = find(fa[x]);
}
double dist(long long i, long long j) {
	return sqrt((x[i]-x[j])*(long long)(x[i]-x[j])+(y[i]-y[j])*(long long)(y[i]-y[j])+(z[i]-z[j])*(long long)(z[i]-z[j]));
}
int main() {
//	freopen("testdata.in", "r", stdin);
	scanf("%d", &t);
	while (t--) {
		scanf("%lld%lld%lld", &n, &h, &r);
		for (int i = 1; i <= n; i++)
			fa[i] = i; //初始化并查集 
		memset(dis, 0, sizeof(dis)) ;
		for (int i = 1; i <= n; i++) {
			scanf("%lld%lld%lld", &x[i], &y[i], &z[i]);
		}
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++)
				if (dist(i, j) <= 2 * r) {
//					if (find(j) == 1000) {
//						cout << dist(i, j) << " " << i << " " << j << endl;
//						printf("|%d %d\n|%d %d\n|%d %d\n", x[i], x[j], y[i], y[j], z[i], z[j]);
//					}
					fa[find(i)] = find(j); //合并
				}
		for (int i = 1; i <= n; i++)
			if (z[i] <= r) {
				dis[find(i)] = 1;
//				if (find(i) == 1000) cout << "|" << i << "|" << endl;
			}
		mark = false;
		for (int i = 1; i <= n; i++)
			if (z[i] + r >= h)
				if (dis[find(i)]) {
					mark = true;
//					cout << i << "**" <<  find(i) << endl << endl;
					break;
				}
		if (mark) puts("Yes");
		else puts("No");
		
//		vector < int > t[maxn];
//		for (int i = 1; i <= n; i++)
//			t[find(i)].push_back(i);
//		for (int i = 1; i <= n; i++)
//			if (t[i].size()) {
//				printf("%4d:", i);
//				for (int j = 0; j < t[i].size(); j++)
//					printf(" %d", t[i][j]);
//				puts("");
//			}
	}
	return 0;
}
	
