#include <bits/stdc++.h>
using namespace std;
const int maxn = 80010;
set < int > a;
set < int > ::iterator it, l, r;
int n, x, y, mark;
int main() {
	scanf("%d", &n);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &x, &y);
		if (mark == x) a.insert(y);
		else if (a.size() == 0) {
			mark = x;
			a.insert(y);
		} else {
			it = a.lower_bound(y);
			if (it == a.end()) it--;
			if (it != a.begin()) {
				r = it;
				l = --it;
				printf("!%d %d!\n", *l, *r);
				if ((y - *l) <= (*r - y)) {
					a.erase(l);
					printf("  !%d!\n", *l);
					ans = (ans + y - *l) % 1000000;
				}
				else {
					a.erase(r);
					printf("  !%d!\n", *r);
					ans = (ans + *r - y) % 1000000;
				}
			} else {
				a.erase(it);
				ans = (ans + *it - y) % 1000000;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
