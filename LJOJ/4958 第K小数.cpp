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

const int maxn = 200010;
ll n, m, a[maxn], b[maxn];
ll k, L, R, Mid, Ans;

bool check(ll x) {
	ll cnt = 0, t;
	for (int i = 1, j = m; i <= n; i++) {
		while (a[i] * b[j] > x && j > 0) j--;
		cnt += j;
//		cout << i << " " << j << endl;
	}
//	printf("CHECK %d %d\n", x, cnt >= k);
	return cnt >= k;
}

int main() {
	
	n = read(), m = read(), k = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	for (int i = 1; i <= m; i++)
		b[i] = read();
	sort(a + 1, a + n + 1);
	sort(b + 1, b + m + 1);
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++)
//			printf("%lld ", a[i] * (ll)b[j]);
//		puts("");
//	}
	
	L = 0, R = a[n] * (ll)b[m];
	while (L <= R) {
		Mid = (L + R) >> 1;
		if (check(Mid)) Ans = Mid, R = Mid - 1;
		else L = Mid + 1;
	}
	printf("%lld\n", Ans);

	return 0;
}

