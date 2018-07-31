#include <bits/stdc++.h> 
using namespace std;

const int maxn = 1010;
int n, m, a[maxn], tt[6], tt_cnt[7];
int t, sj, sx;
bool not_for;

int cal() {
	memset(tt_cnt, 0, sizeof(tt_cnt));
	for (int i = 0; i < 6; i++)
		tt_cnt[tt[i]]++;
	int maxx = -1, maxi = -1;
	for (int i = 1; i <= 6; i++)
		if (tt_cnt[i] > maxx) {
			maxi = i;
			maxx = tt_cnt[i];
		}
	if (maxi == 1 || maxi == 4) maxx *= 2;
	else maxx *= 1;
	return maxx;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		if (i == 1) sj = 1;
		else {
			sx = -1;
			for (int i = 1; i <= n; i++) 
				if (a[i] > sx) {
					sx = a[i];
					sj = i;
				}
		}
		not_for = true;
		for (int j = sj; j != sj || not_for; j = j % n + 1) {
			not_for = false;
			for (int i = 0; i < 6; i++)
				scanf("%d", &tt[i]);
			t = cal();
			a[j] += t;
//			cout << t << endl;
		}
//		for (int j = 1; j <= n; j++)
//			printf("%d ", a[j]);
//		puts("");
	}
	int maxx = -1, maxi = -1;
	for (int i = 1; i <= n; i++)
		if (a[i] > maxx) {
			maxx = a[i];
			maxi = i;
		}
	cout << maxi << " "  << maxx << endl;
//	for (int i = 1; i <= n; i++)
//		printf("%d ", a[i]);
//	puts("");
	return 0;
}
