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

const int maxn = 500010;
ll n, d, k, mid, l, r, t, pl, pr, lbound, rbound, ans;
ll f[maxn], q[maxn];
struct node {
	ll x, s;
	bool operator < (const node &b) {
		return x < b.x;
	}
} a[maxn];

void pop() {
	// printf("pop(%d)\n", q[l]);
	l++;
}

void push() {
	// printf("push()\n");
	while (l <= r && f[t] > f[q[r]]) r--;
	q[++r] = t++;
}

bool check(ll val) {
	memset(f, 0, sizeof(0));
	pl = max((ll)1, d - val), pr = d + val;
	l = 1, r = 1, t = 0, q[1] = 0, f[0] = 0;
	for (int i = 1; i <= n; i++) {
		while (t < i && a[t].x <= a[i].x - pl) push();
		while (l <= r && a[q[l]].x < a[i].x - pr) pop();
		// printf(">>> i = %d l = %d r = %d rr = %d q[l] = %d f[q[l]] = %d\n", i, l, r, t, q[l], f[q[l]]);
		// printf("%d %d %d\n", t, a[t].x, a[i].x - pl);
		// for (int i = l; i <= r; i++)
		// 	printf("%d ", q[i]);
		// puts("");
		if (l <= r && a[q[l]].x <= a[i].x - pl) {
			f[i] = f[q[l]] + a[i].s;
			// printf("%d %d %d\n", a[q[l]].x, a[i].x - pr, (l <= r && a[q[l]].x < a[i].x - pr));
			// printf("%d => %d : %d %d %d\n", q[l], i, f[q[l]], a[i].s, f[i]);
			if (f[i] >= k) return true;
		} else f[i] = -4e18;
	}
	// for (int i = 1; i <= n; i++)
	// 	printf("%d ", q[i]);
	// puts("");
	return false;
}

int main() {
	// freopen("INPUT", "r", stdin);
	// freopen("OUTPUT", "w", stdout);

	n = read(), d = read(), k = read();
	for (int i = 1; i <= n; i++)
		a[i].x = read(), a[i].s = read();
	sort(a + 1, a + n + 1);

	// printf("=== %d ===\n", check(23));
	// for (int i = 1; i <= n; i++)
	// 	printf("%d\n", f[i]);
	lbound = 0, rbound = 1e9, ans = -1;
	while (lbound <= rbound) {
		mid = (lbound + rbound) >> 1;
		// printf("check(%d) = %d\n", mid, check(mid));
		if (check(mid)) {
			ans = mid;
			rbound = mid - 1;
		} else {
			lbound = mid + 1;
		}
	}
	printf("%lld\n", ans);

	return 0;
}