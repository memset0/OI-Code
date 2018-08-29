// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long
#define rg register
using namespace std;

inline int read() {
    int x = 0; bool m = 0; char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') m = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (m) return -x; else return x;
}

inline void print(int x) {
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

const int maxn = 1000010;
int n, m, k, l, r, u;
int a[maxn], nxt[maxn][21];
ll sum[maxn];
int ans;

int main() {
	freopen("T2.in", "r", stdin);
	freopen("T2.out", "w", stdout);
	// freopen("../sample/T2/sample5.in", "r", stdin);
	// freopen("../sample/T2/sample5.ans", "w", stdout);

	n = read(), m = read(), k = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();

	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] - a[i - 1];
		for (int j = nxt[i - 1][0]; j <= n; j++)
			if (sum[i] + a[j] <= k) sum[i] += a[j];
			else {
				nxt[i][0] = j;
				break;
			}
		if (!nxt[i][0]) nxt[i][0] = n + 1;
	}

	for (int i = 0; i < 21; i++)
		nxt[n + 1][i] = n + 1;
	for (int i = 1; i < 21; i++)
		for (int j = 1; j <= n; j++)
			nxt[j][i] = nxt[nxt[j][i - 1]][i - 1];

	// for (int i = 1; i <= n; i++) {
	// 	for (int j = 0; j < 21; j++)
	// 		printf("%d ", nxt[i][j]);
	// 	puts("");
	// }

	for (int i = 1; i <= m; i++) {
		l = read(), r = read();
		u = l, ans = 0;
		for (int i = 20; i >= 0; i--)
			if (nxt[u][i] < r + 1) {
				u = nxt[u][i];
				ans += (1 << i);
			}
		u = nxt[u][0];
		ans++;
		if (u < r + 1)
			puts("Chtholly");
		else
			print(ans), putchar('\n');
	}

	return 0;
}