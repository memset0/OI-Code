#include <bits/stdc++.h>
#define MOV 1000
#define INF 10089400
using namespace std;
int n, s, t, m, f[MOV + 10];
set < int > stn;
int main() {
	int tmp;
	scanf("%d%d%d%d", &n, &s, &t, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d", &tmp);
		stn.insert(tmp); 
	}
	f[0] = 0;
	int i, j;
	for (i = 1; i <= n + t; i++) {
		f[i % MOV] = INF;
		if (stn.count(i)) 
			for (j = s; j <= t; j++) {
				if (i - j < 0) continue;
//				printf("%d -> %d\n", i - j, i);
				f[i % MOV] = min(f[i % MOV], f[i - j % MOV] + 1);
			}
		else 
			for (j = s; j <= t; j++) {
				if (i - j < 0) continue;
//				printf("%d -> %d\n", i - j, i);
				f[i % MOV] = min(f[i % MOV], f[i - j % MOV]);
			}
//		printf("%d\n====\n", f[i % MOV]);
	}
	int ans = INF;
	for (i = n; i <= n + t; i++)
		ans = min(ans, f[i % MOV]);
	printf("%d", ans);
	return 0;
}

