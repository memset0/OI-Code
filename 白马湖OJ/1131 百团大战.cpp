#include <bits/stdc++.h>
using namespace std;
const int maxn = 15010;
const int maxm = 5010;
int n, m = 0, k, x, y, a[maxn], b[maxn];
char c, str[1000];
struct Team {
	int i, n;
}t[maxn];
bool my_sort(Team a, Team b) {
	return a.n > b.n;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("\n%c ", &c);
		if (c == 'C') {
			scanf("%d", &x);
			if (!a[x]) m++;
			a[x]++;
		}
		else if (c == 'D') {
			scanf("%d", &x);
			if (!a[x]) continue;
			a[x]--;
			if (!a[x]) m--;
		}
		else if (c == 'M') {
			scanf("%d<%d", &x, &y);
			if (!a[x] || !a[y]) continue;
			a[x] += a[y];
			a[y] = 0;
			m--;
		}
	}
	int i = 0, j = 0;
	while (i < m) {
		j++;
		if (!a[j]) {
			i++;
			t[i].i = j;
			t[i].n = a[j];
		}
	}
	sort(t+1, t+m+1, my_sort);
	int cnt = 0;
	for (int i = 1; i <= m; i++) {
		if (t[i].n != t[i-1].n) {
			b[++cnt] = t[i].n;
		}
	}
	m = cnt;
	scanf("%d", &k);
	while (k--) {
		scanf("%d", &x);
		if (x > m) printf("NO\n");
		else printf("%d\n", b[x]);
	}
	return 0;
}
