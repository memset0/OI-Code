#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
bool dis[maxn];
int main() {
	int n, m;
	cin >> n >> m;
	int i, j = 0, t;
	for (i = 1; i <= n; i++) {
		for (t = 1; t <= m;) {
			j = j % n + 1;
			if (!dis[j]) t++;
		}
		dis[j] = 1;
		printf("%d ", j);
	}
	puts("");
	return 0;
}
