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

const int maxn = 11000010;
int n, f[maxn << 1];
char a[maxn << 1], s[maxn];

int main() {
	// freopen("INPUT", "r", stdin);
	// freopen("OUTPUT", "w", stdout);

	scanf("%s", s + 1), n = strlen(s + 1);
	a[1] = '#';
	for (int i = 1; i <= n; i++)
		a[i << 1] = s[i], a[i << 1 | 1] = '#';
	n = n << 1 | 1;

	int mid = 0, maxR = 0;
	for (int i = 1; i <= n; i++) {
		if (i < maxR) f[i] = min(f[mid * 2 - i], maxR - i - 1);
		else f[i] = 0;
		for (int j = i + f[i] + 1; j <= n && (2 * i - j) >= 1 && a[j] == a[2 * i - j]; j++)
			f[i]++;
		if (i + f[i] > maxR) {
			maxR = i + f[i];
			mid = i;
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans = max(ans, f[i]);

	printf("%d\n", ans);
	// for (int i = 1; i <= n; i++)
	// 	printf("%d ", a[i]);
	// puts("");
	// for (int i = 1; i <= n; i++)
	// 	printf("%d ", f[i]);
	// puts("");

	return 0;
}