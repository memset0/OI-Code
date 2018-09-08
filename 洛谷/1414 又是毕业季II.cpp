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
int n, sqn, a[maxn], f[maxn], cnt[1000010];

int main() {
	// freopen("INPUT", "r", stdin);
	// freopen("OUTPUT", "w", stdout);

	n = read();
	for (int i = 1; i <= n; i++) {
		a[i] = read();
		sqn = sqrt(a[i]);
		for (int j = 1; j <= sqn; j++)
			if (a[i] % j == 0) {
				cnt[j]++;
				if (j != a[i] / j)
					cnt[a[i] / j]++;
			}
	}
	for (int i = 1; i <= 1000000; i++)
		if (cnt[i])
			f[cnt[i]] = i;
	for (int i = n - 1; i >= 1; i--)
		f[i] = max(f[i], f[i + 1]);
	for (int i = 1; i <= n; i++)
		printf("%d\n", f[i]);

	return 0;
}