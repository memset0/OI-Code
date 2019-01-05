// luogu-judger-enable-o2
#include <bits/stdc++.h>
#define il inline
#define rg register
#define int long long
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

const int maxn = 100010;
int n, m, l, r, ans;
int a[maxn], f[maxn], q[maxn];

void main() {
	read(n), read(m), n += 2;
	for (int i = 2; i < n; i++)
		read(a[i]);
	f[1] = 0, q[1] = l = r = 1;
	for (int i = 2; i <= n; i++) {
		while (l <= r && q[l] < i - m - 1) l++;
		f[i] = f[q[l]] + a[i];
		while (l <= r && f[i] <= f[q[r]]) r--;
		q[++r] = i;
 	}
 	// for (int i = 1; i <= n; i++)
 	// 	print(f[i]), putc(i == n ? '\n' : ' ');
 	ans = -f[n];
 	for (int i = 1; i <= n; i++)
 		ans += a[i];
 	print(ans), putc('\n');
}

} signed main() { return ringo::main(), 0; }