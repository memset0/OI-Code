#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;
int n, m, f[maxn], t[maxn], v[maxn];
int main() {
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &v[i], &t[i]); 
		for (int j = t[i]; j <= m; j++)
			f[j] = max(f[j - t[i]] + v[i], f[j]);
	}
	printf("%d\n", f[m]);
	return 0;
}
