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

const int maxn = 20;

ll n, m;

int len, a[maxn];

ll f[maxn][maxn][maxn];
ll ans1[maxn], ans2[maxn];
ll f10[maxn], lst[maxn];

void add(ll *a, ll *b) {
	// printf("add %d\n", b[0]);
	for (int i = 0; i < 10; i++)
		a[i] += b[i];
}

void print(ll *a) {
	for (int i = 0; i < 10; i++)
		printf("%lld ", a[i]);
	puts("");
}

void init() {
	f10[0] = 1;
	for (int i = 1; i < 20; i++)
		f10[i] = f10[i - 1] * 10;
	for (int j = 1; j < 20; j++)
		for (int i = 0; i < 10; i++) {
			for (int k = 0; k < 10; k++)
				add(f[i][j], f[k][j - 1]);
			f[i][j][i] += f10[j - 1];
		}
	// for (int i = 1; i < 20; i++) {
	// 	for (int j = 0; j < 10; j++) {
	// 		printf("{%d,%d}", i, j);
	// 		for (int k =0 ; k < 10; k++) {
	// 			printf("%lld ", f[j][i][k]);
	// 		}
	// 		puts("");
	// 	}
	// 	puts("");
	// }
}

void calc(ll n, ll ans[]) {
	// printf("===== %lld =====\n", n);
	memset(lst, 0, sizeof(lst));
	if (!n) {
		return;
	}
	len = 0;
	while (n) {
		a[++len] = n % 10;
		n /= 10;
	}
	// print(ans);
	for (int i = len - 1; i >= 1; i--) {
		for (int j = 1; j < 10; j++)
			add(ans, f[j][i]);
	}
	// print(ans);
	for (int i = len; i >= 1; i--) {
		for (int j = (i == len ? 1 : 0); j <= (i == 1 ? a[i] : a[i] - 1); j++) {
			// printf(">>> %d %d\n", i, j);
			add(ans, f[j][i]);
			for (int k = 0; k < 10; k++)
				ans[k] += lst[k] * f10[i - 1];
			// printf(">>> %d %d\n", i, j);
			// print(ans);
		}
		lst[a[i]]++;
	}
	// print(ans);
}

int main() {
	// freopen("INPUT", "r", stdin);
	// freopen("OUTPUT", "w", stdout);

	init();

	scanf("%lld%lld", &n, &m);

	calc(n - 1, ans1);
	calc(m, ans2);

	for (int i = 0; i < 10; i++)
		printf("%lld ", ans2[i] - ans1[i]);
	puts("");

	return 0;
}