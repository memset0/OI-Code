#include <bits/stdc++.h>
using namespace std;
int read() {
	int x = 0; bool m = 0; char c = getchar();
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') m = 1, c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (m) return -x; else return x;
}
const int maxn = 110, INF = 1e9;
int h, n, ans, f[maxn];
struct Node {
	int t, f, h, dt;
} a[maxn];
bool cmp(Node x, Node y) {
	return x.t < y.t;
}
int main() {
	// freopen("INPUT", "r", stdin);
	h = read(), n = read();
	for (int i = 1; i <= n; i++)
		a[i].t = read(), a[i].f = read(), a[i].h = read();
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n; i++)
		a[i].dt = a[i].t - a[i - 1].t;
	// for (int i = 1; i <= n; i++)
	// 	printf("%d ", a[i].t);
	// putchar('\n');
	int sum1 = 10, sum2 = 0;
	for (int i = 1; i <= n; i++) {
		// printf("[%d] => %d %d => %d %d\n", i, a[i].f, a[i].dt, sum1, sum2);
		sum1 += a[i].f, sum2 += a[i].dt;
		if (sum1 <= sum2) {
			printf("%d\n", sum1 - a[i].f);
			return 0;
		}
	}
	for (int i = 0; i <= h; i++)
		f[i] = -INF;
	f[0] = 10;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= h; j++)
			f[j] -= a[i].dt;
		for (int j = h; j >= 0; j--) {
			if (f[j] >= 0) {
				if (j + a[i].h <= h) f[j + a[i].h] = max(f[j + a[i].h], f[j]);
				f[j] += a[i].f;
			}
		}
		if (f[h] >= 0) {
			ans = i;
			break;
		}
	}
	if (ans) printf("%d\n", a[ans].t);
	else {
		for (int i = 1; i <= n; i++)
			ans += a[i].f;
		ans += 10;
		printf("%d\n", ans);
	}
	return 0;
}