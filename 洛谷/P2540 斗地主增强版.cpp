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

const int maxn = 30;

int n, t, T, ans = -1, uans;
int cnt[5], a[maxn], f[maxn][maxn][maxn][maxn][3];

int cge[] = {0, 12, 13, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

void dfs(int stp) {
	memset(cnt, 0, sizeof(cnt));
	for (int i = 1; i <= 13; i++) {
		cnt[4] += a[i] / 4;
		cnt[a[i] % 4]++;
	}
	uans = stp + f[cnt[1]][cnt[2]][cnt[3]][cnt[4]][a[0]];
//	for (int i = 0; i <= 13; i++) cout << a[i] << " "; cout << endl;
//	printf("%d %d (%d %d %d %d %d)\n", stp, f[cnt[1]][cnt[2]][cnt[3]][cnt[4]][a[0]], cnt[1], cnt[2], cnt[3], cnt[4], a[0]);
	if (!~ans || ans > uans) ans = uans;
	for (int l = 5; l <= 13; l++)
		for (int i = 1; i + l <= 13; i++) {
			bool flag = 1; for (int j = i; j < i + l; j++) if (!a[j]) flag = 0;
			if (flag) {
				for (int j = i; j < i + l; j++) a[j]--;
				dfs(stp + 1);
				for (int j = i; j < i + l; j++) a[j]++;
			}
		}
	for (int l = 3; l <= 13; l++)
		for (int i = 1; i + l <= 13; i++) {
			bool flag = 1; for (int j = i; j < i + l; j++) if (a[j] < 2) flag = 0;
			if (flag) {
				for (int j = i; j < i + l; j++) a[j] -= 2;
				dfs(stp + 1);
				for (int j = i; j < i + l; j++) a[j] += 2;
			}
		}
	for (int l = 2; l <= 13; l++)
		for (int i = 1; i + l <= 13; i++) {
			bool flag = 1; for (int j = i; j < i + l; j++) if (a[j] < 3) flag = 0;
			if (flag) {
				for (int j = i; j < i + l; j++) a[j] -= 3;
				dfs(stp + 1);
				for (int j = i; j < i + l; j++) a[j] += 3;
			}
		}
}

int main() {
//	freopen("INPUT", "r", stdin);
//	freopen("OUTPUT", "w", stdout);

	T = read(), n = read();
	for (int k = 0; k <= 2; k++)
		for (int q = 0; q <= 25; q++)
			for (int p = 0; p <= 25; p++)
				for (int j = 0; j <= 25; j++)
					for (int i = 0; i <= 25; i++) {
						f[i][j][p][q][k] = i + j + p + q + k;
						#define upd(a, b, c, d, e)\
							if (a >= 0 && b >= 0 && c >= 0 && d >= 0 && e >= 0)\
								if (f[a][b][c][d][e] + 1 < f[i][j][p][q][k])\
									f[i][j][p][q][k] = f[a][b][c][d][e] + 1	
						upd(i - 1, j, p, q, k);
						upd(i, j - 1, p, q, k);
						upd(i, j, p - 1, q, k);
						upd(i, j, p, q - 1, k);
						upd(i, j, p, q, k - 1);
						upd(i, j, p, q, k - 2);
						upd(i, j, p - 1, q, k - 1);
						upd(i - 1, j, p - 1, q, k);
						upd(i, j - 1, p - 1, q, k);
						upd(i, j, p, q - 1, k - 2);
						upd(i - 2, j, p, q - 1, k);
						upd(i, j - 2, p, q - 1, k);
						if (k) f[i][j][p][q][k] = min(f[i][j][p][q][k], f[i + 1][j][p][q][k - 1]);
						if (j) f[i][j][p][q][k] = min(f[i][j][p][q][k], f[i + 2][j - 1][p][q][k]);
						if (p) f[i][j][p][q][k] = min(f[i][j][p][q][k], f[i + 3][j][p - 1][q][k]);
						if (q) f[i][j][p][q][k] = min(f[i][j][p][q][k], f[i + 4][j][p][q - 1][k]);
						if (q) f[i][j][p][q][k] = min(f[i][j][p][q][k], f[i][j + 2][p][q - 1][k]);
						if (p) f[i][j][p][q][k] = min(f[i][j][p][q][k], f[i + 1][j + 1][p - 1][q][k]);
						if (q) f[i][j][p][q][k] = min(f[i][j][p][q][k], f[i + 2][j + 1][p][q - 1][k]);
						if (q) f[i][j][p][q][k] = min(f[i][j][p][q][k], f[i + 1][j][p + 1][q - 1][k]);
//						printf("%d %d %d %d %d : %d\n", i, j, p, q, k, f[i][j][p][q][k]);
					}
	while (T--) {
		memset(a, 0, sizeof(a));
		ans = -1;
		for (int i = 1; i <= n; i++) {
			t = read(), read();
			a[cge[t]]++;
		}
//		puts("");
		dfs(0);
		printf("%d\n", ans);
	}
	
	return 0;
}
