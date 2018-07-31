#include <bits/stdc++.h> 
using namespace std;
const int maxn = 100010;
int n, m, ans, f[maxn];
int main() {
	scanf("%d%d", &n, &m);
	int x, y;
	for (int i = 1; i <= m; i++) {
		scanf("%d", &x);
		if (x == 0) {
			scanf("%d%d", &x, &y);
			for (int i = x; i <= y; i++)
				 f[i] ^= 1;
		} else {
			scanf("%d%d", &x, &y);
			ans = 0;
			for (int i = x; i <= y; i++)
				if (f[i]) ans++;
			printf("%d\n", ans);
		}
	}
	return 0;
}
