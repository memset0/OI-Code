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

const int maxn = 1e8 + 10, mod = 1e9 + 7;
int n, m, ans;
int f[maxn], prime[maxn / 20];

int pow(int a, int b) {
	int s = 1;
	while (b) {
		if (b & 1) s = (ll)s * a % mod;
		a = (ll)a * a % mod, b >>= 1;
	}
	return s;
}

int solve(int n, int m) {
	memset(f, 0, sizeof(f));
	ans = 0, f[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (!f[i]) f[i] = pow(i, m), prime[++prime[0]] = i;
		for (int j = 1; j <= prime[0] && i * prime[j] <= n; j++) {
			if (i % prime[j] == 0) { f[i * prime[j]] = f[i]; break; }
			else f[i * prime[j]] = (ll)f[i] * f[prime[j]] % mod;
		}
	}
	for (int i = 1; i <= n; i++) ans = (ans + f[i]) % mod;
	// for (int i = 1; i <= 10; i++) print(f[i]), putc('\n');
	return ans;
}

void main() {
	read(n), read(m);
	print(solve(n, m)), putc('\n');
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 1; j++) {
			printf("solve(%d, %d) = %d\n", i, j, solve(i, j));
		}
	}
}

} int main() { return ringo::main(), 0; }
