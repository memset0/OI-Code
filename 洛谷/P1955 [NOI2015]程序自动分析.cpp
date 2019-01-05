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

const int maxn = 100010;
int t, n, m, fu, fv, flag;
int f[maxn], u[maxn], v[maxn], k[maxn], b[maxn << 1];

int find(int x) {
	if (f[x] == x) return x;
	return f[x] = find(f[x]);
}

void main() {
	// freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
	for (read(t); t--; ) {
		read(n), m = 0, flag = true;
		for (int i = 1; i <= n; i++) {
			read(u[i]), read(v[i]), read(k[i]);
			b[++m] = u[i], b[++m] = v[i];
		}
		std::sort(b + 1, b + m + 1);
		m = std::unique(b + 1, b + m + 1) - b - 1;
		for (int i = 1; i <= n; i++) {
			u[i] = std::lower_bound(b + 1, b + m + 1, u[i]) - b;
			v[i] = std::lower_bound(b + 1, b + m + 1, v[i]) - b;
		}
		for (int i = 1; i <= m; i++)
			f[i] = i;
		for (int i = 1; i <= n; i++)
			if (k[i]) {
				fu = find(u[i]), fv = find(v[i]);
				if (fu != fv) f[fu] = fv;
			}
		for (int i = 1; i <= n; i++)
			if (!k[i] && find(u[i]) == find(v[i]))
				flag = false;
		puts(flag ? "YES" : "NO");
	}
}

} int main() { return ringo::main(), 0; }