#include <bits/stdc++.h>
using namespace std;
int n = 0, t, x, y, l = 0, a[200010], f[200010][20], m[10000];
char c;
struct Ans {
	int val, cnt;
} ans[5000];
bool cmp(Ans a, Ans b) {
	if (a.cnt == b.cnt) return a.val < b.val;
	return a.cnt > b.cnt; 
}
int ta[20], tl;
int main() {
	freopen("1.txt", "r", stdin);
	scanf("%d%d%d", &x, &y, &t);
	c = getchar();
	while (c != EOF) {
		while (!(c == '0' || c == '1')) c = getchar();
		a[ ++n ] = c - '0';
		c = getchar();
	}
	int i, j;
	f[0][0] = 1;
	//f[i][j] 表示以第i个元素结尾的长度为j的字符串 
	for (i = 1; i <= n; i++) {
		f[i][0] = 1;
		for (j = 1; j <= y; j++) {
			if (i - j < 0) break;
			f[i][j] = f[i - 1][j - 1] * 2 + a[i];
			if (j >= x) m[f[i][j]] ++;
		}
	}
	for (int i = 0; i < 10000; i++)
		if (m[i]) {
			l++;
			ans[l].val = i;
			ans[l].cnt = m[i];
		}
	sort(ans + 1, ans + l + 1, cmp);
	j = 1;
	int cnt;
	for (i = 1; i <= t; i++) {
		cnt = 0;
		printf("%d\n", ans[j].cnt);
		while (j <= n && (ans[j].cnt == ans[j - 1].cnt || cnt == 0)) {
			tl = 0;
			cnt++;
			while (ans[j].val > 0) {
				ta[++tl] = ans[j].val % 2;
				ans[j].val /= 2;
			}
			for (int i = tl - 1; i > 0; i--)
				printf("%d", ta[i]);
			if (cnt % 6 == 0) puts("");
			else putchar(' ');
			j++;
		}
		if (cnt % 6 != 0) puts("");
	}
	return 0;
}
