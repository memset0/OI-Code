// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll read() {
    ll x = 0; bool m = 0; char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') m = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (m) return -x; else return x;
}

#define sqr(x) ((x) * (x))
const int maxn = 1510;
ll n, m, ans;

struct node {
	ll x, y;
} a[maxn];

struct edge {
	ll dx, dy;
	ll x, y, len;
	bool operator < (const edge &b) const {
		if (x != b.x) return x < b.x;
		if (y != b.y) return y < b.y;
		return len < b.len;
	}
} e[maxn * maxn];

ll calc(int i, int j) {
	// cout << e[i].i << " " << e[int].j << " " << e[j].i << " " << e[j].j << " " << abs(e[i].dx * e[j].dy - e[i].dy * e[j].dx) << endl;
	return abs(e[i].dx * e[j].dy - e[i].dy * e[j].dx);
}

int main() {
	// freopen("INPUT", "r", stdin);
	
	n = read();
	for (int i = 1; i <= n; i++)
		a[i].x = read(), a[i].y = read();
		
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			e[++m] = {
				a[i].x - a[j].x,
				a[i].y - a[j].y,
				a[i].x + a[j].x,
				a[i].y + a[j].y,
				sqr(a[i].x - a[j].x) + sqr(a[i].y - a[j].y)
			};

	sort(e + 1, e + m + 1);

	for (int i = 1; i <= m; i++)
		for (int j = i - 1; j > 0 && e[i].x == e[j].x && e[i].y == e[j].y && e[i].len == e[j].len; j--)
			ans = max(ans, calc(i, j));

	printf("%lld\n", ans >> 1);
	
	return 0;
}
