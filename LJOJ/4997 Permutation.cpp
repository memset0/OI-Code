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

const int maxn = 60;
int n, a[maxn];
ll k, f[maxn];

int main() {
//	freopen("Permutation.in", "r", stdin);
//	freopen("Permutation.out", "w", stdout);
	
	n = read(), k = readll();
	
	f[0] = 1, f[1] = 2;
	for (int i = 2; i <= n; i++)
		f[i] = f[i - 2] + f[i - 1];
//	for (int i = 1; i <= n; i++)
//		cout << f[i] << endl;

	for (int i = 1; i <= n; i++)
		a[i] = i;

//	for (int i = 1; i <= n; i++)
//		printf("%d ", a[i]);
//	puts("");

	int i = 1;
	k--;
	while (i <= n && k) {
//		printf("i = %d k = %d t = %d\n", i, k, t);
		if (k >= f[n - i - 1]) {
			k -= f[n - i - 1];
			swap(a[i], a[i + 1]);
			i += 2;
		} else i++;
	}
	
	printf("%d", a[1]);
	for (int i = 2; i <= n; i++)
		printf(" %d", a[i]);
	puts("");

	return 0;
}

