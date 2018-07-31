#include <bits/stdc++.h>
using namespace std;
const int maxn = 360, maxm = 41;
int n, m, t, a, b, c, d, v[maxn], cnt[5], f[maxm][maxm][maxm][maxm];
int main() {
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> v[i];
	for (int i = 1; i <= m; i++)
		cin >> t, cnt[t]++;
	f[0][0][0][0] = v[1];
	for (a = 0; a <= cnt[1]; a++)
		for (b = 0; b <= cnt[2]; b++)
			for (c = 0; c <= cnt[3]; c++)
				for (d = 0; d <= cnt[4]; d++) {
					if (a) f[a][b][c][d] = max(f[a][b][c][d], f[a - 1][b][c][d] + v[1 + a + b * 2 + c * 3 + d * 4]);
					if (b) f[a][b][c][d] = max(f[a][b][c][d], f[a][b - 1][c][d] + v[1 + a + b * 2 + c * 3 + d * 4]);
					if (c) f[a][b][c][d] = max(f[a][b][c][d], f[a][b][c - 1][d] + v[1 + a + b * 2 + c * 3 + d * 4]);
					if (d) f[a][b][c][d] = max(f[a][b][c][d], f[a][b][c][d - 1] + v[1 + a + b * 2 + c * 3 + d * 4]);
				}
	cout << f[cnt[1]][cnt[2]][cnt[3]][cnt[4]] << endl;
	return 0;
}
