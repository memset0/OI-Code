#include <bits/stdc++.h>
#define Mod 1000000007
using namespace std;
const int maxn = 110;
const int maxm = 1010;
int n, k, a[maxn][maxn], b[maxm], f[maxm];
long long t;
long long cal(int x, int k) {
	if (k == 1) return x;
	t = cal(x, k / 2);
	if (k % 2) return ((((t * t) % Mod) * x) % Mod);
	else ((t * t) % Mod);
}
int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &a[i][j]), b[a[i][j]] = 1;
	for (int i = 1; i <= 1000; i++)
		if (b[i]) f[i] = cal(i, k);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) 
			printf("%d ", f[a[i][j]]);
		puts("");
	}
}
