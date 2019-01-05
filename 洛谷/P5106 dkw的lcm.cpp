// luogu-judger-enable-o2
// luogu-judger-enable-o2
// =================================
//   author: memset0
//   date: 2018.12.16 16:21:24
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
namespace ringo {
typedef long long ll;

template <class T> inline void read(T &x) {
    x = 0; register char c = getchar(); register bool f = 0;
    while (!isdigit(c)) f ^= c == '-', c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (f) x = -x;
}
template <class T> inline void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) print(x / 10);
    putchar('0' + x % 10);
}
template <class T> inline void maxd(T &a, T b) { if (b > a) a = b; }
template <class T> inline void mind(T &a, T b) { if (b < a) a = b; }
template <class T> inline void print(T x, char c) { print(x), putchar(c); }
template <class T> inline T abs(const T &a) { if (a < 0) return -a; return a; }

const int N = 1e6 + 10, M = 16777217, p = 1e9 + 7;
int n, m, k, mi, ans = 1;
int phi[M], pri[M / 10];

int fpow(int a, int b, int p) {
	int s = 1;
	while (b) {
		if (b & 1) s = (ll)s * a % p;
		b >>= 1, a = (ll)a * a % p;
	}
	return s;
}

void main() {
    read(n), read(k);
    phi[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!phi[i]) {
            phi[i] = i - 1;
            pri[++pri[0]] = i;
        }
        for (int j = 1; j <= pri[0] && i * pri[j] <= n; j++) {
            if (i % pri[j] == 0) {
                phi[i * pri[j]] = phi[i] * pri[j];
                break;
            } else {
                phi[i * pri[j]] = phi[i] * (pri[j] - 1);
            }
        }
    }
	for (int i = 1; i <= pri[0]; i++) {
		ll x = pri[i];
		for (int j = 1, a, b; x <= n; j++, x *= pri[i]) {
			a = n - n / x / pri[i];
			b = - (n / x / pri[i]) + (n / x);
			mi = (fpow(a, k, p - 1) - fpow(a - b, k, p - 1) + p - 1) % (p - 1);
			ans = ((ll)ans * fpow(phi[x], mi, p)) % p;
			// printf(">> %d %d : %d %d : %lld\n", pri[i], j, mi, fpow(phi[x], mi, p), ans);
			// printf("== %d %d %d\n", a, a - b, b);
		}
	}
	print(ans, '\n');
}

} signed main() { return ringo::main(), 0; }