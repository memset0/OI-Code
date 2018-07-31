#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
const int maxm = 30010;
int n, m, f[maxm];
struct food {
	int w, v;
} a[maxn];
int main() {
	memset(f, 63, sizeof(f));
	char s[1000]; int x, y; double y_;
	cin >> n >> m; m *= 1000;
	for (int i = 1; i <= n; i++) {
		scanf("%s %d %lf", s, &x, &y_);
		y = y_ * 1000;
		a[i].w = y, a[i].v = x;
	}
	for (int i = 1; i <= n; i++) printf("%d ", a[i].w); puts("");
	for (int i = 1; i <= n; i++) printf("%d ", a[i].v);	puts("");
	f[0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = m - a[i].w; j >= 0; j--)
			f[j + a[i].w] = min(f[j + a[i].w], f[j] + a[i].v);
	}
	int ans = f[30009];
	for (int i = 0; i <= m; i++)
		cout << f[i] << " ";
	puts("");
	for (int i = m; i <= 30000; i++)
		ans = min(ans, f[i]);
	cout << ans << endl;
	cout << f[m];
	return 0;
}  
