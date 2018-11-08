#include <bits/stdc++.h>
#define il inline
#define rg register
#define ll long long
#define getc getchar
#define putc putchar
#define rep(i, l, r) for (int i = l; i <= r; ++i)
namespace ringo {

template < class T > il void read(T &x) {
	x = 0; rg char c = getc(); rg bool f = 0;
	while (!isdigit(c)) f ^= c == '-', c = getc();
	while (isdigit(c)) x = x * 10 + c - '0', c = getc();
	if (f) x = -x;
}

template < class T > il void print(T x) {
	if (x < 0) putc('-'), x = -x;
	if (x > 9) print(x / 10);
	putc('0' + x % 10);
}

int a, b, x, y;

void exgcd(int a, int b, int &x, int &y) {
	if (b == 0) { x = 1, y = 0; return; }
	exgcd(b, a % b, x, y);
	int tmp = y;
	y = x - y * (a / b);
	x = tmp;
	// printf("exgcd %d %d %d %d\n", a, b, x, y);
}

void main() {
	// freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
	read(a), read(b);
	exgcd(a, b, x, y);
	print((x % b + b) % b), putc('\n');
}

} int main() { return ringo::main(), 0; }