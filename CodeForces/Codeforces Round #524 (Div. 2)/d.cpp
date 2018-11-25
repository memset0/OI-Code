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

const long long llmax = 9223372036854775807ll;

int t, n, k, p;
bool flag;

int pow(int a, int b) {
	if (b < 0) return 0;
	int s = 1;
	while (b--) s *= a;
	return s;
}

bool boom(int a, int b) {
	if (a >= llmax / b) return true;
	return false;
}

bool check(int t, int p, int k, int c) {
//	printf("check %d %d %d\n", t, p, k);
	if (!p || k < 0) return c >= t;
	if (t <= c) return true;
	t -= c;
	int s = p, pw = pow(2, k);
	if (s >= t) return true;
	if (boom(s, p)) return true;
	s = s * p;
	if (s >= t) return true;
	if (boom(s, pw)) return true;
	s = s * pw;
	if (s >= t) return true;
	if (boom(s, pw)) return true;
	s = s * pw;
	if (s >= t) return true;
	return false;
//	return p * p * pow(2, k) * pow(2, k) >= t - c;
}

void main() {
	for (read(t); t--; ) {
		read(n), read(k), flag = 0;
//		printf(">>> %d %d\n", n, k);
		int s = 0, l = 1, c = 0;
		for (int i = 1; i <= n; i++) {
			c += (l >> 1) * (l >> 1), s += l, l = l << 1 | 1;
			if (s > k) break;
//			printf("i = %lld s = %lld l = %lld\n", i, s, l);
			if (check(k - s, l >> 1, n - i - 1, c)) {
				flag = 1;
				printf("YES ");
				print(n - i);
				putc('\n');
				break;
			}
		}
		if (!flag) puts("NO");
	}
}

} signed main() { return ringo::main(), 0; }
