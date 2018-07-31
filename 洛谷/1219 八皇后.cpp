#include <bits/stdc++.h> 
using namespace std;
const int maxn = 15;
int n, ans = 0, a[maxn][maxn], b[maxn];
void mark(int x, int y, int color) {
	/*for (int i = 1; i <= n; i++) {
		a[x][i] += color;
	}*/
	for (int i = /*1*/ x + 1; i <= n; i++) {
		a[i][y] += color;
	}
	int tx = x, ty = y;
	while (tx <= n && ty <= n) {
		a[tx][ty] += color;
		tx ++, ty ++;
	}
	/*tx = x, ty = y;
	while (tx >= 1 && ty >= 1) {
		a[tx][ty] += color;
		tx --, ty --;
	}*/
	tx = x, ty = y;
	while (tx <= n && ty >= 1) {
		a[tx][ty] += color;
		tx ++, ty --;
	}
	/*tx = x, ty = y;
	while (tx >= 1 && ty <= n) {
		a[tx][ty] += color;
		tx --, ty ++;
	}*/
	return ;
}
void DFS(int x) {
	if (x > n) {
		//FOUND THE ANSWER
		if (ans < 3) {
			for (int i = 1; i <= n; i++)
				printf("%d ", b[i]);
			puts("");
		}
		ans ++;
		return ;
	}
	for (int y = 1; y <= n; y++)
		if (!a[x][y]) {
			mark(x, y, 1);
			b[x] = y;
			DFS(x + 1);
			mark(x, y, -1);
		}
	return ;
}
int main() {
	scanf("%d", &n);
	DFS(1);
	printf("%d\n", ans);
	return 0;
}
