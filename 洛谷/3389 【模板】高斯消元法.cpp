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
int n;
double ans[maxn], a[maxn][maxn], f[maxn][maxn];

void merge(double *a, double *b, int k) {
//	printf("=== MERGE ===\n");
//	for (int i = 1; i <= n + 1; i++) printf("%7.2lf", a[i]); cout << endl;
//	for (int i = 1; i <= n + 1; i++) printf("%7.2lf", b[i]); cout << endl;
	if (b[k] == 0) {
		for (int i = k; i <= n + 1; i++)
			a[i] = b[i];
	} else {
		double t = -a[k] / b[k];
		for (int i = k; i <= n + 1; i++)
			a[i] = a[i] + b[i] * t;
	}
//	for (int i = 1; i <= n + 1; i++) printf("%7.2lf", a[i]); cout << endl;
//	cout << endl;
}

int main() {
//	freopen("INPUT", "r", stdin);
	
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n + 1; j++)
			scanf("%lf", &a[i][j]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n + 1; j++)
			f[i][j] = a[i][j];
	
	for (int i = 1; i < n; i++)
		for (int j = n; j > i; j--)
			merge(f[j], f[j - 1], i);
	
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n + 1; j++)
//			printf("%7.2lf", f[i][j]);
//		puts("");
//	}
	
	for (int i = n; i >= 1; i--) {
		for (int j = i + 1; j <= n; j++)
			f[i][n + 1] -= f[i][j] * ans[j];
		if (f[i][i] == 0) {
			printf("No Solution\n");
			return 0;
		} else ans[i] = f[i][n + 1] / f[i][i];
	}
	for (int i = 1; i <= n; i++)
		printf("%.2lf\n", ans[i]);
	
	return 0;
}

