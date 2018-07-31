#include <bits/stdc++.h> 
#define lowbit(x) (x&-x)
using namespace std;
const int maxn = 500010;
int n, m, a, c[maxn], x, y, z;
void add(int k, int x) {
	while (k <= n) {
		c[k] += x;
		k += lowbit(k);
	}
}
int sum(int k) {
	int s = 0;
	while (k > 0) {
		s += c[k];
		k -= lowbit(k);
	}
	return s;
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a);
		add(i, a);
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &x, &y, &z);
		if (x == 1) {
			add(y, z);
		} else {
			printf("%d\n", sum(z) - sum(y - 1));
		}
	}
	return 0;
}
