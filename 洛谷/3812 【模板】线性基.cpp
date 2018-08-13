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

const int maxn = 60;
int n;
ll ans;
ll _2[maxn], a[maxn], f[maxn];

int main() {
//	freopen("INPUT", "r", stdin);
	
	n = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	_2[0] = 1;
	for (int i = 1; i <= 50; i++)
		_2[i] = _2[i - 1] << 1;
		
//	for (int i = 1; i <= n; i++) {
//		printf("%lld ", a[i]); 
//		for (int j = 0; j <= 50; j++)
//			if (a[i] & _2[j]) putchar('1');
//			else putchar('0'); 
//		puts("");
//	}
//	puts("=====");
	
	for (int i = 1; i <= n; i++)
		for (int j = 50; j >= 0; j--)
			if (a[i] & _2[j]) {
//				printf(">>> i=%d j=%d a[i]=%lld f[j]=%lld\n", i, j, a[i], f[j]);
				if (f[j]) a[i] ^= f[j];
				else {
					f[j] = a[i];
					break;
				}
//				printf(">>> i=%d j=%d a[i]=%lld f[j]=%lld\n", i, j, a[i], f[j]);
			}
	for (int j = 50; j >= 0; j--)
		if ((ans & _2[j]) == 0) {
			ans ^= f[j];
		}
		
//	for (int i = 50; i >= 0; i--) {
//		printf("%lld ", f[i]); 
//		for (int j = 0; j <= 50; j++)
//			if (f[i] & _2[j]) putchar('1');
//			else putchar('0'); 
//		puts("");
//	}
	
	printf("%lld\n", ans);
	
	return 0;
}

