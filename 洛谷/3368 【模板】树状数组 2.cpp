#include <bits/stdc++.h>
#define lowbit(x) (x&-x)
using namespace std;
const int maxn = 500010;
int n, m, a[maxn], c[maxn];
//b[i] 表示 a[1] + ... + a[n] 的值
void add(int k, int x) {
	while (k <= n) {
		c[k] += x;
		k += lowbit(k);
	}
}
int sum (int k) {
	int s = 0;
	while (k > 0) {
		s += c[k];
		k -= lowbit(k);
	}
	return s;
}
int main() {
	cin >> n >> m;
	int s = 0, x, y, z;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		add(i, a[i] - a[i - 1]);
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d", &x);
		if (x == 1) {
			scanf("%d%d%d", &x, &y, &z);
			add(x, z), add(y + 1, -z);
		} else {
			scanf("%d", &x);
			printf("%d\n", sum(x));
		}
	}
	return 0;
} 
