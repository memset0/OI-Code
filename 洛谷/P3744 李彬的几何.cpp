// luogu-judger-enable-o2
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

const int N = 1010;
int n;
double ans;

struct node {
	double x, y;
} a[N];

double dis(const node &a, const node &b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double S(const node &a, const node &b, const node &c) {
	double x = dis(a, b), y = dis(a, c), z = dis(b, c), p = (x + y + z) / 2;
	return sqrt(p * (p - x) * (p - y) * (p - z));
}

void main() {
	read(n);
	for (int i = 1; i <= n; i++)
		read(a[i].x), read(a[i].y);
	a[0] = a[n], a[n + 1] = a[1];
	ans = 1e10000;
	for (int i = 1; i <= n; i++)
		ans = std::min(ans, S(a[i], a[i + 1], a[i - 1]) / dis(a[i - 1], a[i + 1]));
	printf("%.10lf\n", ans);
}

} signed main() { return ringo::main(), 0; }