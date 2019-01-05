// luogu-judger-enable-o2
#include <bits/stdc++.h>
#define il inline
#define rg register
#define ll long long
#define getc getchar
#define putc putchar
#define rep(i, l, r) for (int i = l; i <= r; ++i)
namespace ringo {

template < class T >
il void read(T &x) {
	x = 0; rg char c = getc(); rg bool f = 0;
	while (!isdigit(c)) f ^= c == '-', c = getc();
	while (isdigit(c)) x = x * 10 + c - '0', c = getc();
	if (f) x = -x;
}
template < class T >
il void print(T x) {
	if (x < 0) putc('-'), x = -x;
	if (x > 9) print(x / 10);
	putc('0' + x % 10);
}
template < class T >
il void print(T x, char c) { print(x), putc(c); }

const int mod = 123456789;
ll k;

int pow(ll b) {
	int s = 1, a = 2;
	while (b) {
		if (b & 1ll) s = (ll)s * a % mod;
		a = (ll)a * a % mod, b >>= 1ll;
	}
	return s;
}

void main() {
	read(k);
	print(pow(k - 1)), putc('\n');
}

} int main() { return ringo::main(), 0; }
