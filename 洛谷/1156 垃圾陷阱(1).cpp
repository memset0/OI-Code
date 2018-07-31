#include <bits/stdc++.h>
using namespace std;
int read() {
	int x = 0; bool m = 0; char c = getchar();
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') m = 1, c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (m) return -x; else return x;
}
const int maxn = 110, maxm = 1010, INF = 1e9 + 10;
int n, h, ans, final_ans, f[maxn];
struct Node {
	int t, f, h;
} a[maxn];
bool cmp(Node x, Node y) {
	return x.t < y.t;
}
int main() {
	freopen("INPUT", "r", stdin);
	h = read(), n = read();
	for (int i = 1; i <= n; i++)
		a[i].t = read(), a[i].f = read(), a[i].h = read();
	sort(a + 1, a + n + 1, cmp);
	for (int i = n; i > 0; i--)
		a[i].t = a[i].t - a[i - 1].t;
	for (int i = 1; i <= h; i++)
		f[i] = -INF;
	f[0] = 10;
	for (int i = 1; i <= n && !ans; i++)
		for (int j = h; j >= 0; j--) {
			f[j] = max(f[j]- a[i].t, f[j]- a[i].t + a[i].f);
			if (j >= a[i].h) f[j] = max(f[j], f[j - a[i].h] - a[i].t);
			if (f[j] < 0) f[j] = -INF;
			if (j == h && f[j] >= 0) {
				ans = i;
				break;
			}
		}
	// cout << ans << endl;
	if (ans) {
		for (int i = 1; i <= ans; i++)
			final_ans += a[i].t;
		printf("%d\n", final_ans);
	} else printf("%d\n", f[0]);
	return 0;
}