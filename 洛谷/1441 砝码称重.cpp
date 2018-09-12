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

const int maxn = 22, maxm = 5;

int n, m, ans, sum, a[maxn];
bool d[maxn], f[2001];

void dfs(int u, int c) {
	if (u == n + 1) {
		if (c == m) {
			sum = 0, memset(f, 0, sizeof(f));
			f[0] = 1;
			for (int i = 1; i <= n; i++)
				if (!d[i])
					for (int j = 2000; j >= 0; j--)
						if (f[j] && !f[j + a[i]]) {
							f[j + a[i]] = 1;
							sum++;
						}
			ans = max(ans, sum);
		}
		return;
	}
	if (c < m) {
		d[u] = 1;
		dfs(u + 1, c + 1);
		d[u] = 0;
		dfs(u + 1, c);
	} else {
		dfs(u + 1, c);
	}
}

int main() {
	
	n = read(), m = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	dfs(1, 0);
	printf("%d\n", ans);
	
	return 0;
}
