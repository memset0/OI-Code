#include <bits/stdc++.h>
using namespace std;
const int maxn = 50 + 10, maxm = 3010, maxk = 3010, maxt = 3010;
struct Plant {
	int x, y, t;
} a[maxm];
int n, m, t, k, x, q, l = 0, b[maxk], c[maxt];
long long f[maxm];
int main() {
	memset(f, 0, sizeof(f));
	cin >> n >> m >> t >> k;
	a[0].x = 0; a[0].t = 0; a[0].y = 0;
	for (int i = 1; i <= m; i++) scanf("%d%d%d", &a[i].x, &a[i].t, &a[i].y);
	for (int i = 1; i <= k; i++) scanf("%d", &b[i]), c[b[i]] = 1;
	for (int i = 0; i < t; i++) if (c[i]) b[++l] = i;

	for (int i = 1; i <= k; i++) {
		f[b[i]] = f[b[i-1]];
		for (int j = 1; j <= m; j++) {
			q = b[i] - a[j].t;
			while (q >= 0 && c[q] == 0) q--;
			if (q < 0) continue;
			x = f[q] + a[j].y - a[j].x;
			if (x > f[b[i]]) f[b[i]] = x;
		}
	}
//	for (int i = 1; i <= k; i++) printf("f[%d] = %d\n", i,f[b[i]]);
	cout << n * f[b[k]];
 	return 0;
}
