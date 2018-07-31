#include <bits/stdc++.h>
#define boom(x, y, a, b, c, d) (a <= x && x <= c && b <= y && y <= d)
using namespace std;
const int maxn = 2010;
int n, m;
struct Group {
	int x1, x2, y1, y2;
} a[maxn];
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d%d", &a[i].x1, &a[i].y1, &a[i].x2, &a[i].y2);
	}
	int x, y;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &x, &y);
		int cnt = 0, last;
		for (int i = 1; i <= n; i++)
			if (boom(x, y, a[i].x1, a[i].y1, a[i].x2, a[i].y2)) {
				cnt ++;
				last = i;
			}
		if (cnt) {
			printf("YES %d %d", cnt, last);
			puts("");
		} else printf("NO\n");
	}
	return 0;
}
