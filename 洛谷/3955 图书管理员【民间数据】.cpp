#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
int n, m, k, t, a[maxn];
int cge[10] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
bool mark;
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &k, &t);
		mark = false;
		for (int i = 1; i <= n; i++)
			if (a[i] % cge[k] == t) {
				printf("%d\n", a[i]);
				mark = true;
				break;
			}
		if (!mark) printf("-1\n");
	}
	return 0;
}

