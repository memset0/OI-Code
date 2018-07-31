#include <bits/stdc++.h>
using namespace std;
const int maxn = 100;
const int maxm = 32010;
int n, m, a[maxn], v[maxn], q[maxn], p[maxn][3], f[maxm];
int main() {
	cin >> m >> n;
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d", &a[i], &v[i], &q[i]);
		v[i] *= a[i];
		if (q[i] != 0) p[q[i]][++p[q[i]][0]] = i;
	}
	for (int i = 1; i <= n; i++) 
		if (q[i] == 0) {
			for (int j = m; j >= a[i]; j--) {
				f[j] = max(f[j], f[j - a[i]] + v[i]);
				if (p[i][0] >= 1 && j - a[i] >= a[p[i][1]]) f[j] = max(f[j], f[j - a[i] - a[p[i][1]]] + v[i] + v[p[i][1]]);
				if (p[i][0] == 2 && j - a[i] >= a[p[i][2]]) f[j] = max(f[j], f[j - a[i] - a[p[i][2]]] + v[i] + v[p[i][2]]);
				if (p[i][0] == 2 && j - a[i] >= a[p[i][1]] + a[p[i][2]]) f[j] = max(f[j], f[j - a[i] - a[p[i][1]] - a[p[i][2]]] + v[i] + v[p[i][1]] + v[p[i][2]]);
			}
		}
	cout << f[m] << endl;
	return 0;
}
