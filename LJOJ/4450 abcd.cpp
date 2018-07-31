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

const int maxn = 210, p = 50000;
int n, t, L, R, a[maxn], b[maxn], c[maxn], d[maxn], f[maxn][100010];
bool vis[maxn][100010];

#define Max(a,b) ((a)>(b)?(a):(b))

int main() {
	srand(20040725);
	n = read();
	for (int i = 1; i <= n; i++)
		a[i] = read(), b[i] = read(), c[i] = read(), d[i] = read();
	for (int i = 1, j = rand() % n + 1; i <= n; i++, j = rand() % n + 1)
		swap(a[i], a[j]), swap(b[i], b[j]), swap(c[i], c[j]), swap(d[i], d[j]);
	f[0][p] = 0, vis[0][p] = 1;
	for (int i = 1; i <= n; i++) {
		for (int e = a[i]; e <= b[i]; e++)
			for (int j = L; j <= R; j++)
				if (vis[i - 1][j + p]) {
					t = j + c[i] * e;
//					printf("i=%3d j=%3d t=%3d p=%3d %d \n", i, j, t, e * d[i], vis[i - 1][j]);
					if (t >= -p && t <= p) {
						if (!vis[i][t + p]) f[i][t + p] = f[i - 1][j + p] + e * d[i], vis[i][t + p] = 1;
						else f[i][t + p] = Max(f[i][t + p], f[i - 1][j + p] + e * d[i]);
					}
				}
		L += a[i] * c[i];
		R += b[i] * c[i];
	}
//	for (int i = 0; i <= n; i++) {
//		for (int j = -10; j <= 10; j++)
//			printf("%3d", f[i][j + p] < -100000 ? 0 : f[i][j + p]);
//		puts("");
//	}
	printf("%d\n", f[n][p]);
	return 0;
}
