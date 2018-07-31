#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
const char word[8] = "yizhong";
const int x_mov[8] = {1, -1, 0, 0, 1, 1, -1, -1};
const int y_mov[8] = {0, 0, 1, -1, -1, 1, 1, -1};
int n, i, x, y, xx, yy;
char str[maxn], p[maxn][maxn], f[maxn][maxn];
void check(int x, int y) {
	for (int k = 0; k < 7; k++) {
		xx = x, yy = y;
		for (i = 0; i < 7; i++) {
			if (xx < 0 || yy < 0 || xx > n || yy > n || p[xx][yy] != word[i]) break;
			xx += x_mov[k];
			yy += y_mov[k];
		}
		if (i == 7) {
			xx = x, yy = y;
			for (int i = 0; i < 7; i++) {
				f[xx][yy] = 1;
				xx += x_mov[k];
				yy += y_mov[k];
			}
		}
	}
}
int main() {
	cin >> n, gets(str);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			p[i][j] = getchar();
		gets(str);
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (p[i][j] == 'y')
				check(i, j);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			if (f[i][j]) putchar(p[i][j]);
			else putchar('*');
		puts("");
	}
} 
