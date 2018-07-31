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

const int maxn = 200010, M = 1000000007;
int m, n;
ll a[maxn], b[maxn], t[maxn];

int main() {
//	freopen("video.in", "r", stdin);
//	freopen("video.out", "w", stdout);

	m = read(), n = read();
	a[0] = b[0] = a[1] = b[1] = t[0] = t[1] = 1;
	for (int i = 2; i <= max(n, m - n); i++)
		t[i] = (M - M / i) * t[M % i] % M;
	for (int i = 2; i <= max(n, m - n); i++)
		a[i] = a[i - 1] * t[i] % M;
	for (int i = 2; i <= m; i++)
		b[i] = b[i - 1] * i % M;
//	for (int i = 1; i <= max(n, m - n); i++)
//		printf("%d ", a[i]);
//	puts("");
//	for (int i = 1; i <= m; i++)
//		printf("%d ", b[i]);
//	puts("");
	
	printf("%lld\n", b[m] * a[n] % M * a[m - n] % M);
	return 0;
}

