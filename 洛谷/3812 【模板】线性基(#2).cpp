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

const int maxn = 60;
ll n, ans, s[maxn], f[maxn];

void main() {
	read(n); rep(i, 1, n) read(s[i]);
	rep(i, 1, n) {
		for (ll j = 60; j >= 0; j--)
			if (s[i] & (1ll << j)) {
				if (f[j]) s[i] ^= f[j];
				else { f[j] = s[i]; break; }
			}
	}
	for (ll i = 60; i >= 0; i--)
		if (!(ans & (1ll << i)))
			ans ^= f[i];
	// for (ll i = 60; i >= 0; i--)
	// 	print(f[i]), putc(!i ? '\n' : ' ');
	print(ans), putc('\n');
}

} int main() { return ringo::main(), 0; }