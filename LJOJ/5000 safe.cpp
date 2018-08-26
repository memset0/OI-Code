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

ll readll() {
    ll x = 0; bool m = 0; char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') m = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (m) return -x; else return x;
}

const int maxn = 66000;

int n;
ll ans;

ll a[maxn];
ll f[maxn], g[maxn], s[maxn];

int main() {
//	freopen("safe.in", "r", stdin);
//	freopen("safe.out", "w", stdout);
	
	n = read();
	for (int i = 1; i <= n; i++)
		a[i] = readll();
	
	for (int i = 1; i <= n; i++)
		s[i] = max(a[i], s[i - 1] + a[i]);
	f[1] = a[1];
	for (int i = 2; i <= n; i++)
		f[i] = max(s[i], f[i - 1]);
		
	for (int i = n; i >= 1; i--)
		s[i] = max(a[i], s[i + 1] + a[i]);
	g[n] = a[n];
	for (int i = n - 1; i >= 1; i--)
		g[i] = max(s[i], g[i + 1]);
	
	ans = f[1] + g[2];
	for (int i = 1; i < n; i++)
		ans = max(ans, f[i] + g[i + 1]);
		
//	for (int i = 1; i <= n; i++)
//		printf("%d ", f[i]);
//	puts("");
//	for (int i = 1; i <= n; i++)
//		printf("%d ", g[i]);
//	puts("");
//	for (int i = 1; i < n; i++)
//		printf("%d ", f[i] + g[i + 1]);
//	puts("");
	
	printf("%lld\n", ans);
	
	return 0;
}

