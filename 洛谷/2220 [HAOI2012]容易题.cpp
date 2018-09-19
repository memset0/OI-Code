// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int read() {
	int x = 0; bool m = 0; char c = getchar();
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') m = 1, c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (m) return -x; else return x;
}

const int maxn = 100010;
const int mod = 1000000007;

int n, m, q, cnt;
ll ans = 1, sum, org;

struct node {
	int x, y;
} a[maxn];
bool operator < (const node &x, const node &y) {
	if (x.x ^ y.x) return x.y < y.y;
	return x.x < y.x;
}

ll pow(ll x, int t) {
	ll ret = 1;
	while (t) {
		if (t & 1)
			ret = ret * x % mod;
		x = x * x % mod;
		t >>= 1;
	}
	return ret;
}

int main() {
	n = read(), m = read(), q = read();
	for (int i = 1; i <= q; i++)
		a[i].x = read(), a[i].y = read();
	sort(a + 1, a + q + 1);
	org = n * (n + 1) / 2 % mod;
	for (int i = 1, j = i; i <= q; i = j) {
		sum = org;
		while (a[j].x == a[i].x && j <= q) {
			if (!(a[j].x == a[j - 1].x && a[j].y == a[j - 1].y)) {
				sum -= a[j].y;
			}
			j++;
		}
		printf(">> %d[%d %d] %d[%d %d]\n", i, a[i].x, a[i].y, j, a[j].x, a[j].y);
		cnt++, ans = ans * sum % mod;
	}
	printf("%lld\n", ans * pow(org, m - cnt) % mod);
	return 0;
}

