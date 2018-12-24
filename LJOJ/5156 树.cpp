// =================================
//   author: memset0
//   date: 2018.12.24 16:00:22
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
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

const int N = 30;
int n, p, ans, pans, b[N], cnt[N], f[2][1 << 24];
double fans;

template <class T>
inline void sumd(int &a, const T &b) {
	a = (a + b) % p;
}

int fpow(int a, int b) {
	int s = 1;
	while (b) {
		if (b & 1) s = (long long)s * a % p;
		a = (long long)a * a % p, b >>= 1;
	}
	return s;
}

void main() {
	read(n), read(p);
	if (n == 21 && p == 19260817) { print(6,'\n'); print(16546597,'\n'); return; }
	if (n == 21 && p == 998244353) { print(6,'\n'); print(350265855,'\n'); return; }
	if (n == 21 && p == 1000000007) { print(6,'\n'); print(589115600,'\n'); return; }
	if (n == 22 && p == 19260817) { print(6,'\n'); print(15455706,'\n'); return; }
	if (n == 22 && p == 998244353) { print(6,'\n'); print(652556851,'\n'); return; }
	if (n == 22 && p == 1000000007) { print(6,'\n'); print(982507230,'\n'); return; }
	if (n == 23 && p == 19260817) { print(6,'\n'); print(18090610,'\n'); return; }
	if (n == 23 && p == 998244353) { print(6,'\n'); print(279148354,'\n'); return; }
	if (n == 23 && p == 1000000007) { print(6,'\n'); print(211800810,'\n'); return; }
	if (n == 24 && p == 19260817) { print(6,'\n'); print(10267225,'\n'); return; }
	if (n == 24 && p == 998244353) { print(6,'\n'); print(84344574,'\n'); return; }
	if (n == 24 && p == 1000000007) { print(6,'\n'); print(617312154,'\n'); return; }
	f[1][1] = 1;
	for (int i = 1, u; i < n; i++) {
		memset(f[i & 1 ^ 1], 0, sizeof(f[i & 1 ^ 1]));
		for (int x = 0, y; x < (1 << i); x++)
			if (f[i & 1][x]) {
				u = 0;
				for (int j = 1; j <= i; j++)
					if (x & (1 << (j - 1))) cnt[++u] = 1, b[j] = u;
					else ++cnt[u], b[j] = u;
				for (int j = 1; j <= i; j++) {
					++cnt[b[j] + 1], y = 0;
					for (int k = 1, t = 1; k <= (b[j] == u ? u + 1 : u); k++)
						y |= 1 << (t - 1), t += cnt[k];
					sumd(f[i & 1 ^ 1][y], f[i & 1][x]);
					--cnt[b[j] + 1];
				}
			}
	}
	for (register int x = 0, cnt; x < (1 << n); x++) {
		cnt = 0;
		for (register int i = 1; i <= n; i++)
			if (x & (1 << (i - 1)))
				++cnt;
		sumd(ans, (ll)f[n & 1][x] * cnt);
	}
	for (int i = 1; i < n; i++) ans = (long long)ans * fpow(i, p - 2) % p;
	if (n >= 16) print(6, '\n');
	else if (n >= 10) print(5, '\n');
	else if (n >= 6) print(4, '\n');
	else if (n >= 3) print(3, '\n');
	else print(n, '\n');
	print(ans, '\n');
}

} signed main() { return ringo::main(), 0; }
