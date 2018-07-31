#include <bits/stdc++.h>
#define isnum(x) ('0' <= x && x <= '9')
#define read(x) do { \
	x = 0, r::c = std::getchar(), r::m = 1; \
	while (!isnum(r::c) && r::c != '-') r::c = getchar(); \
	if (r::c == '-') r::m = -1, r::c = getchar(); \
	while (isnum(r::c)) x = x * 10 + r::c - '0', r::c = getchar(); \
	x *= r::m; \
} while(0)
using namespace std;
namespace r {
	char c;
	int m;
}

const int maxn = 200010;
int n, t, k, ans, minn, ans_v, a[maxn];
struct Node {
	int val, last = -1;
} x, y;
map < int, Node > m;

int main() {
	
	read(n);
	
	for (int i = 1; i <= n; i++) {
		read(a[i]);
		if (a[i] < minn) minn = a[i];
	}
	
	for (int i = 1; i <= n; i++) {
		t = a[i], k = 1;
		x.val = 1;
		x.last = -1;
		m[a[i]] = x;
		if (x.val > ans) {
			ans = x.val;
			ans_v = a[i];
		}
		while (a[i] - k >= minn) {
//			cout << a[i] << " " << a[i] - k << endl;
			
			y = m[a[i] - k];
			if (y.val + 1 > x.val) {
//				cout << x.val << " " << y.val << endl;
				x.val = y.val + 1;
				x.last = a[i] - k;
				if (x.val > ans) {
					ans = x.val;
					ans_v = a[i];
				}
				m[a[i]] = x;
			}
			k <<= 1;
		}
	}
	printf("%d\n", ans);
	x = m[ans_v];
	printf("%d ", ans_v);
	while (x.last != -1) {
		printf("%d ", x.last);
		x = m[x.last];
	}
	
	return 0;
}

