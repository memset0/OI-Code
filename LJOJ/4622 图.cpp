// 开 long long  开 long long  开 long long  开 long long  开 long long  开 long long  开 long long  开 long long  开 long long  开 long long 
// 开 long long  开 long long  开 long long  开 long long  开 long long  开 long long  开 long long  开 long long  开 long long  开 long long 
// 开 long long  开 long long  开 long long  开 long long  开 long long  开 long long  开 long long  开 long long  开 long long  开 long long 
// 开 long long  开 long long  开 long long  开 long long  开 long long  开 long long  开 long long  开 long long  开 long long  开 long long 
// 开 long long  开 long long  开 long long  开 long long  开 long long  开 long long  开 long long  开 long long  开 long long  开 long long 
// 开 long long  开 long long  开 long long  开 long long  开 long long  开 long long  开 long long  开 long long  开 long long  开 long long 
// 开 long long  开 long long  开 long long  开 long long  开 long long  开 long long  开 long long  开 long long  开 long long  开 long long 
// 开 long long  开 long long  开 long long  开 long long  开 long long  开 long long  开 long long  开 long long  开 long long  开 long long 
// 开 long long  开 long long  开 long long  开 long long  开 long long  开 long long  开 long long  开 long long  开 long long  开 long long 
// 开 long long  开 long long  开 long long  开 long long  开 long long  开 long long  开 long long  开 long long  开 long long  开 long long 
// 开 long long  开 long long  开 long long  开 long long  开 long long  开 long long  开 long long  开 long long  开 long long  开 long long 
// 开 long long  开 long long  开 long long  开 long long  开 long long  开 long long  开 long long  开 long long  开 long long  开 long long 
// 开 long long  开 long long  开 long long  开 long long  开 long long  开 long long  开 long long  开 long long  开 long long  开 long long 
// 开 long long  开 long long  开 long long  开 long long  开 long long  开 long long  开 long long  开 long long  开 long long  开 long long 
// 开 long long  开 long long  开 long long  开 long long  开 long long  开 long long  开 long long  开 long long  开 long long  开 long long 
// 开 long long  开 long long  开 long long  开 long long  开 long long  开 long long  开 long long  开 long long  开 long long  开 long long 
// 开 long long  开 long long  开 long long  开 long long  开 long long  开 long long  开 long long  开 long long  开 long long  开 long long 
// 开 long long  开 long long  开 long long  开 long long  开 long long  开 long long  开 long long  开 long long  开 long long  开 long long 
// 开 long long  开 long long  开 long long  开 long long  开 long long  开 long long  开 long long  开 long long  开 long long  开 long long 
// 开 long long  开 long long  开 long long  开 long long  开 long long  开 long long  开 long long  开 long long  开 long long  开 long long
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

const int maxn = 100010;
const ll inf = 3e18;
int n, u;
ll k, stp, ans1, ans2;
ll mi2[40], f[maxn][35], f1[maxn][35], f2[maxn][35];

int main() {
	
	n = read(), k = readll();
	for (int i = 1; i <= n; i++)
		f[i][0] = (read() + 1);
	for (int i = 1; i <= n; i++)
		f1[i][0] = f2[i][0] = read();
	
	mi2[0] = 1;
	for (int i = 1; i < 35; i++)
		mi2[i] = mi2[i - 1] << 1;
	for (int i = 1; i < 35; i++)
		for (int j = 1; j <= n; j++) {
			f[j][i] = f[f[j][i - 1]][i - 1];
			f1[j][i] = f1[f[j][i - 1]][i - 1] + f1[j][i - 1];
			f2[j][i] = min(f2[f[j][i - 1]][i - 1], f2[j][i - 1]);
		}
	
//	for (int i = 1; i <= n; i++) {
//		for (int j = 0; j < 35; j++)
//			printf("(%lld %lld %lld) ", f[i][j], f1[i][j], f2[i][j]);
//		puts("");
//	}
	
	for (int now = 1; now <= n; now++) {
		u = now, stp = k, ans1 = 0, ans2 = inf;
		for (int i = 34; i >= 0; i--)
			if (stp - mi2[i] >= 0) {
				stp -= mi2[i];
				ans1 = ans1 + f1[u][i];
				ans2 = min(ans2, f2[u][i]);
				u = f[u][i];
			}
		printf("%lld %lld\n", ans1, ans2);
	}

	return 0;
}