#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int n, ans, a[maxn], f[maxn], g[maxn];
int main() {
	while (scanf("%d", &a[n + 1]) != EOF)
		n++;
	for (int i = 1; i <= n; i++) {
		f[i] = 1;
		for (int j = 1; j < i; j++)
			 if (a[i] <= a[j])
			 	f[i] = max(f[i], f[j] + 1);	
		ans = max(ans, f[i]);
	}
	printf("%d\n", ans);
	memset(f, 0, sizeof(f));
	ans = 0;
	for (int i = 1; i <= n; i++) {
		f[i] = 1;
		for (int j = 1; j < i; j++)
			if (a[i] > a[j])
				f[i] = max(f[i], f[j] + 1);
		ans = max(ans, f[i]);
	}
	printf("%d\n", ans);
	return 0;
}