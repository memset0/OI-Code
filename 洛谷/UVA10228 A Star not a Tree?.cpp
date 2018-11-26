#include <bits/stdc++.h>
namespace ringo {
typedef long long ll;

template < class T >
inline void read(T &x) {
	x = 0; register char c = getchar(); register bool f = 0;
	while (!isdigit(c)) f ^= c == '-', c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (f) x = -x;
}

template < class T >
inline void print(T x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) print(x / 10);
	putchar('0' + x % 10);
}

template < class T >
inline void print(T x, char c) {
	print(x), putchar(c);
}

const int N = 110;
const double start_tpr = 2e8, end_tpr = 1e-12, down_tpr = 1 - 1e-3;
int t, n, i;
double tpr;

struct node {
	int x, y;
} a[N];

struct status {
	double x, y, val;
	inline void refresh() {
		val = 0;
		for (int i = 1; i <= n; i++)
			val += sqrt((x - a[i].x) * (x - a[i].x) + (y - a[i].y) * (y - a[i].y));
	}
} u, v, ans, sum;

void sa() {
	u = sum, tpr = start_tpr;
	// puts("===========");
	while (tpr > end_tpr) {
		v.x = u.x + (rand() * 2 - RAND_MAX) * tpr;
		v.y = u.y + (rand() * 2 - RAND_MAX) * tpr;
		v.refresh();
		// printf("%.2lf %.2lf %.2lf : %.2lf\n", v.x, v.y, v.val, u.val);
		if (v.val < u.val || exp((u.val - v.val) / tpr) * RAND_MAX > rand()) {
			u = v;
			if (u.val < ans.val) ans = u;
		}
		tpr *= down_tpr;
	}
}

void main() {
	srand(20040725);
	for (read(t); t--; ) {
		sum.x = sum.y = 0;
		for (read(n), i = 1; i <= n; i++) {
			read(a[i].x), read(a[i].y);
			sum.x += a[i].x, sum.y += a[i].y;
		}
		sum.x /= n, sum.y /= n, sum.refresh(), ans = sum;
		for (int i = 0; i < 30; i++) sa();
		print((int)(ans.val + 0.5), '\n');
		if (t) putchar('\n');
	}
}

} signed main() { return ringo::main(), 0; }