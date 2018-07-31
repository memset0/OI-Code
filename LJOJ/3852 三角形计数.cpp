#include <bits/stdc++.h>
#define ll long long
using namespace std;
int read(void) {
	int x = 0; bool m = 0; char c = getchar();
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') c = getchar(), m = 1;
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (m) return -x; else return x; 
}
const int maxn = 3010;
int n, x[maxn], y[maxn];
ll ans, sx, sy;
struct Node {
	int x, y;
} a[maxn];
bool cmp(Node x, Node y) {
	ll t1 = x.x * y.y, t2 = x.y * y.x;
	if (t1 == t2) return x.x < y.x;
	else return t1 < t2;
}
int main() {
	n = read();
	for (int i = 1; i <= n; i++)
		x[i] = read(), y[i] = read();
	for (int k = 3; k <= n; k++) {
		for (int i = 1; i < k; i++)
			a[i].x = x[i] - x[k], a[i].y = y[i] - y[k];
		sort(a + 1, a + k, cmp);
		sx = sy = 0;
		for (int i = 1; i < k; i++) {
			ans += a[i].x * sy - a[i].y * sx;
			sx += a[i].x, sy += a[i].y;
		}
	}
//	cout << ans << endl;
	if (ans & 1) printf("%lld.5\n", ans >> 1);
	else printf("%lld.0\n", ans >> 1);
	return 0;
} 
