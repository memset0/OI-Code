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

const int maxn = 50010;
int n, m, sqn, a[maxn];
ll now, cnt[maxn], ansa[maxn], ansb[maxn];
struct Query {
	int i;
	ll l, r;
} q[maxn];
bool cmp(Query a, Query b) { return a.l / sqn == b.l / sqn ? a.r < b.r : a.l < b.l; };
void print(ll a, ll b)  {
	if (a == 0) b = 1;
	else {
		ll t = __gcd(a, b);
		a /= t, b /= t;
	}
	printf("%lld/%lld\n", a, b);
}
void init(void) {
	sqn = sqrt(n);
}
void ist(int t) {
	now += cnt[t]++;
}
void rmv(int t) {
	now -= --cnt[t];
}
int main() {
//	freopen("INPUT", "r", stdin);
//	freopen("1.out", "w", stdout);
	n = read(), m = read();
	init();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	for (int i = 1; i <= m; i++)
		q[i].l = read(), q[i].r = read(), q[i].i = i;
	sort(q + 1, q + m + 1, cmp);
	int l = 1, r = 0;
	for (int i = 1; i <= m; i++) {
		while (l < q[i].l) rmv(a[l++]);
		while (l > q[i].l) ist(a[--l]);
		while (r > q[i].r) rmv(a[r--]);
		while (r < q[i].r) ist(a[++r]);
		ansa[q[i].i] = now;
		ansb[q[i].i] = (q[i].r - q[i].l + 1) * (q[i].r - q[i].l) >> 1;
//		printf(">>> %d %d %d %d\n", l, r, ansa[q[i].i], ansb[q[i].i]);
	}
	for (int i = 1; i <= m; i++)
		print(ansa[i], ansb[i]);
	return 0;
}
