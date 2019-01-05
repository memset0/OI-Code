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

int n, m, a[maxn], b[maxn];
int t[1000010];

int main() {
	
	n = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	for (int i = 1; i <= n; i++)
		b[i] = read();
	
	m = min(n, 1000);
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= m; j++)
			t[(i - 1) * m + j] = a[i] + b[j];
	sort(t + 1, t + m * m + 1);
	
	for (int i = 1; i <= n; i++)
		printf("%d ", t[i]);
	puts("");
	
    return 0;
}