#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int n, m, a[maxn], b, t;
char s[maxn][20];
int way(int x, int y) {
	if ((x + y) % 2) return 1;
	return -1;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d%s", &a[i], s[i]);
	long long ans = 0;
	while (m--) {
		scanf("%d%d", &b, &t);
		ans = ans + way(a[ans], b) * t;
		if (ans >= 0) ans = ans % n;
		else ans = n - (-ans % n);
	}
	printf("%s\n", s[ans]);
	return 0;
}
