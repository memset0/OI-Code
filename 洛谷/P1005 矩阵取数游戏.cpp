#include <bits/stdc++.h>
using namespace std;
const int maxn = 90;
long long n, m, a[maxn][maxn];
__int128 sum, ans, _2[maxn], f[maxn][maxn];
int ptt[100];
void print(__int128 x, char t) {
	if (x == 0) putchar('0');
	ptt[0] = 0;
	while (x > 0) {
		ptt[++ptt[0]] = x % 10;
		x /= 10;
	}
	for (int i = ptt[0]; i > 0; i--)
		putchar(ptt[i] + '0');
	putchar(t);
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &a[i][j]);
			
	_2[0] = 1;
	for (int i = 1; i <= m; i++)
		_2[i] = _2[i - 1] * 2;
//	for (int i = 1; i <= m; i++)
//		print(_2[i], ' ');
//	puts("");
		
	for (int k = 1; k <= n; k++) {
		memset(f, 0, sizeof(f));
		for (int i = 1; i < m; i++)
			for (int l = 1, r = m - i; r <= m; l++, r++) {
//				cout << l << " " << r << endl;
				if (l > 1) f[l][r] = max(f[l][r], f[l - 1][r] + a[k][l - 1] * _2[i]);
				if (r < m) f[l][r] = max(f[l][r], f[l][r + 1] + a[k][r + 1] * _2[i]);
			}
			
//		for (int i = 1; i <= m; i++) {
//			for (int j = 1; j <= m; j++)
//				print(f[i][j], ' ');
//			puts("");
//		}
		
		sum = f[1][1];
		for (int i = 1; i <= m; i++)
			sum = max(sum, f[i][i] + a[k][i] * _2[m]);
		ans += sum;
//		print(sum, '\n');
	}
	print(ans, '\n');
	return 0;
}