// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define il inline
#define rg register
#define ll long long
#define ull unsigned long long
#define y1 this_is_not_y1
#define y2 this_is_not_y2
#define sqr ((x)*(x))
#define lowbit(x) ((x)&(-x))
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

const int maxn = 110;
const double inf = 1e10;
int n;
double t, ans[maxn], f[maxn][maxn];

int work() {
	for (int i = 1; i <= n; i++) {
		if (f[i][i] == 0) {
			int j = i + 1;
			while (f[j][i] == 0 && j <= n) j++;
			if (j > n) return -1; // ¿Ï¶¨ÎÞ½â 
			swap(f[i], f[j]);
		}
		for (int j = i + 1; j <= n; j++) {
			t = -f[j][i] / f[i][i];
			for (int k = i; k <= n + 1; k++)
				f[j][k] += f[i][k] * t;
		}
	} 
	for (int i = n; i >= 1; i--) {
		for (int j = i + 1; j <= n; j++)
			f[i][n + 1] -= ans[j] * f[i][j];
		ans[i] = f[i][n + 1] / f[i][i];
	}
	return 0;
}

int main() {
//	freopen("INPUT", "r", stdin);

	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n + 1; j++)
			scanf("%lf", &f[i][j]);
	
	if (work() == -1)
		printf("No Solution\n");
	else for (int i = 1; i <= n; i++)
		printf("%.2lf\n", ans[i]);
	
	return 0;
}

