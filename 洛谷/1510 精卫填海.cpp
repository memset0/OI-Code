#include <bits/stdc++.h> 
using namespace std;
const int maxn = 10010;
int a[maxn], v[maxn], f[maxn];
int main() {
	int x, n, m;
	scanf("%d%d%d", &x, &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &a[i], &v[i]);
	f[0] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = m; j >= v[i]; j--)
			f[j] = max(f[j], f[j - v[i]] + a[i]);
	for (int i = 0; i <= m; i++)
		if (f[i] >= x) {
			printf("%d", m - i);
			return 0;
		}
	printf("Impossible\n");
	return 0;
}
