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

const int maxn = 70;
int n, t, x;
int siz, lim, sum, minn;
int a[maxn], f[maxn];

bool cmp(int a, int b) {
	return a > b;
}

void dfs(int cnt, int sum, int cur) {
	if (sum == siz)
		cnt++, sum = 0, cur = a[1];
	if (cnt == lim) {
		printf("%d\n", siz);
		exit(0);
	}
	for (int i = cur; i >= a[n]; i--)
		if (f[i] && i + sum <= siz) {
			f[i]--;
			dfs(cnt, sum + i, i);
			f[i]++;
			if (sum + i == siz || sum == 0)
				return;
		}
}

int main() {
//	freopen("INPUT", "r", stdin);
	
	t = read();
	for (int i = 1; i <= t; i++) {
		x = read();
		if (x <= 50) a[++n] = x;
	}

	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n; i++) {
		sum += a[i];
		f[a[i]]++;
	}

	for (int i = n; i >= 2; i--)
		if (sum % i == 0) {
			lim = i, siz = sum / i;
//			printf(">> %d %d\n", lim, siz);
			dfs(0, 0, a[1]);
		}
	printf("%d\n", sum);
	
	return 0;
}
