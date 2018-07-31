#include <bits/stdc++.h>
using namespace std;
int n = 10, a[11], m, f[110];
int main() {
	memset(f, 63, sizeof(f));
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	scanf("%d", &m);
	f[0] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= m; j++)
			f[j] = min(f[j], f[j - i] + a[i]);
	printf("%d", f[m]);
	return 0;
}

