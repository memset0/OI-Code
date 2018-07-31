#include <bits/stdc++.h>
using namespace std;
int n, t, cnt, u;
int main() {
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &t);
		if (cnt == 0) {
			u = t;
			cnt = 1;
		} else if (t == u) cnt++;
		else cnt--;
	}
	printf("%d", u);
	return 0;
}
