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

const int maxn = 10010;

int n, x, w, ans;
int a[maxn], f[maxn];

int main() {
	
	n = read();
	read(), ans = f[1] = read(), read();
	for (int i = 2; i <= n; i++) {
		read(), w = read();
		while (x = read())
			f[i] = max(f[i], f[x] + w);
		ans = max(ans, f[i]);
	}
	printf("%d\n", ans);
	
	return 0;
}