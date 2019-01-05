#include <bits/stdc++.h>
#define isnum(c) ('0' <= c && c <= '9')
#define read(x) do {\
	char c = getchar(); bool m = 0; x = 0;\
	while (!isnum(c) && c != '-') c = getchar();\
	if (c == '-') c = getchar(), m = 1;\
	while (isnum(c)) x = x * 10 + c - '0', c = getchar();\
	if (m) x = -x;\
} while(false)
using namespace std;

const int maxn = 50010;
int n, tx, ty, a[maxn], tag[maxn], f[maxn][2];
vector < int > G[maxn];

void DFS(int u) {
//	cout << u << endl;
	tag[u] = 1;
	f[u][1] = 1;
	for (int i = 0; i < G[u].size(); i++)
		if (!tag[G[u][i]]) {
			DFS(G[u][i]);
			f[u][0] += max(f[G[u][i]][0], f[G[u][i]][1]);
			f[u][1] += f[G[u][i]][0];
		} 
}

int main() {
	
//	freopen("vacation.in", "r", stdin);
//	freopen("vacation.out", "w", stdout);
	
	read(n);
//	cout << n <<endl;
	for (int i = 1; i < n; i++) {
		read(tx);
		read(ty);
		G[tx].push_back(ty);
		G[ty].push_back(tx);
	}
	
	DFS(1);
	printf("%d\n", max(f[1][0], f[1][1]));
	
	return 0;
} 