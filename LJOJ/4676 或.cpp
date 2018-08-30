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

int read1d() {
    char c = getchar();
    while (!isdigit(c)) c = getchar();
    return c - '0';
}

const int maxn = 1000010;
const ll p = 1e9 + 7;
const ll inv2 = 500000004;
int n, a[maxn];
ll m, t, lft, unuse, A, B;
ll f[maxn][2], mi2[maxn], g[maxn];

int func(int x) {
	int ret = 0;
	for (int i = 0; i <= 12; i++)
		if ((1 << i) & x)
			ret++;
//	printf("f(%d) = %d\n", x, ret);
	return ret;
}

int main() {
//	freopen("or.in", "r", stdin);
//	freopen("or.out", "w", stdout);

	n = read();
	for (int i = 1; i <= n; i++)
		a[i] = read1d();
	
	t = 1;
	for (int i = n; i >= 1; i--) {
		if (a[i]) g[i] = (g[i + 1] + t) % p;
		else g[i] = (g[i + 1]) % p;
		t = (t << 1) % p;
	}
//	for (int i = 1; i <= n; i++)
//		printf("%lld ", g[i]);
//	puts("");
	m = (g[1] + 1) % p;
	mi2[0] = 1;
	for (int i = 1; i <= n; i++)
		mi2[i] = (mi2[i - 1] << 1) % p;
	
	lft = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i]) {
			f[i][0] = (f[i][0] + mi2[n - i]) % p;
			f[i][1] = (f[i][1] + g[i] + 1 - mi2[n - i] + p) % p;
			unuse = (g[i] + 1 - mi2[n - i] + p) % p;
//			printf("f[%d][0] += %lld\n", i, mi2[n - i]);
//			printf("f[%d][1] += %lld\n", i, (g[i] + 1 - mi2[n - i] + p) % p);
		} else {
			f[i][0] = (f[i][0] + unuse) % p;
//			printf("f[%d][0] += %lld\n", i, unuse);
		}
		f[i][0] = (f[i][0] + mi2[n - i] * lft % p) % p;
		f[i][1] = (f[i][1] + mi2[n - i] * lft % p) % p;
//		printf("f[%d][0] += %lld\n", i, mi2[n - i] * lft % p);
//		printf("f[%d][1] += %lld\n", i, mi2[n - i] * lft % p);
		lft = a[i] ? (lft * 2 + 1) % p : lft * 2 % p; 
//		printf(">>> %lld\n", lft);
	}
//	for (int j = 1; j <= n; j++)
//		printf("(%lld, %lld) ", f[j][0], f[j][1]);
//	puts("");
//	memset(f, 0, sizeof(f));
//	for (int i = 0; i < m; i++) {
//		for (int j = 1; j <= n; j++)
//			if (i & (1 << (n - j))) f[j][1]++;
//			else f[j][0]++;
//	}
//	for (int j = 1; j <= n; j++)
//		printf("(%lld, %lld) ", f[j][0], f[j][1]);
//	puts("");
//	
	for (int j = 1; j <= n; j++)
		A = (A + f[j][0] * f[j][1] % p * 2 % p + f[j][1] * f[j][1] % p) % p;
	for (int j = 1; j <= n; j++)
		B = (B + f[j][1]) % p;
	
//	printf("%lld %lld\n", A, B);
	printf("%lld\n", (A + B) * inv2 % p);
	
	return 0;
}
