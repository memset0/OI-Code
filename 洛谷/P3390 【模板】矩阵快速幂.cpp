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

const int maxn = 100, mod = 1e9 + 7;
ll n, k;

struct matrix {
	ll a[maxn][maxn];
	matrix() {
		memset(a, 0, sizeof(a));
	}
	matrix operator * (const matrix &b) const {
		matrix c;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				for (int k = 1; k <= n; k++)
					c.a[i][j] = (c.a[i][j] + a[i][k] * b.a[k][j] % mod) % mod;
		return c;
	}
} mul, ans;

int main() {
//	freopen("INPUT", "r", stdin);
	
	n = read(), k = read() - 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			ans.a[i][j] = mul.a[i][j] = read();
	while (k) {
//		printf("%d\n", k);
		if (k & 1) ans = ans * mul;
		mul = mul * mul;
		k >>= 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			printf("%d ", ans.a[i][j]);
		puts("");
	}
	return 0;
}