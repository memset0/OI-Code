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
int n, *ret;
int a[maxn], f[maxn];

int main() {
//	freopen("manage.in", "r", stdin);
//	freopen("manage.out", "w", stdout);
	
	memset(f, 63, sizeof(f));
	
	n = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
		
	for (int i = 1; i <= n; i++)
		*lower_bound(f + 1, f + n + 1, a[i]) = a[i];
		
	printf("%d\n", int(lower_bound(f + 1, f + n + 1, f[0]) - f - 1));
	
	return 0;
}
