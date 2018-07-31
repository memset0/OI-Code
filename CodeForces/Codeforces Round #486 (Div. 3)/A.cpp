#include <bits/stdc++.h>

const int maxn = 110;
int n, m, a[maxn], b[maxn], c[maxn];

int main() {
	
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		 scanf("%d", &a[i]);
		 
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		if (!b[a[i]]) {
			c[++cnt] = i;
			b[a[i]] = 1;
		}
	
	if (cnt >= m) {
		printf("YES\n");
		for (int i = 1; i <= m; i++)
			printf("%d ", c[i]);
	} else {
		printf("NO");
	}
	
	return 0;
}
