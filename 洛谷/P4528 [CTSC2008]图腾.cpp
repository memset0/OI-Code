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

const int N = 2e5 + 10, mod = 16777216;
int n, m, ans;
int a[N], l[N], r[N], s[N];

int ask(int k) { int t = 0; for (; k; k -= k & -k) (t += s[k]) %= mod; return t; }
void add(int k, int x) { for (; k <= n; k += k & -k) (s[k] += x) %= mod; }

int solve_1xxx() {
	int ans = 0;
	for (int i = 1, t; i <= n; i++) {
		t = n - i - r[i];
		ans = (ans + (ll)t * (t - 1) * (t - 2) / 6) % mod;
	}
	// printf("#1xxx# %d\n", ans);
	return ans;
}

int solve_1234() {
	int ans = 0;
	memset(s, 0, sizeof(s));
	for (int i = 1; i <= n; i++) {
		ans = (ans + (ll)(n - i - r[i]) * ask(a[i] - 1)) % mod;
		add(a[i], l[i]);
	}
	// printf("#1234# %d\n", ans);
	return ans;
}

int solve_1x2x() {
	int ans = 0;
	memset(s, 0, sizeof(s));
	for (int i = 1, now; i <= n; i++) {
		now = (ll)l[i] * (i - 1) % mod;
		now = (now - (ll)l[i] * (l[i] - 1) / 2 % mod + mod) % mod;
		now = (now - ask(a[i] - 1)) % mod;
		ans = (ans + (ll)(n - i - r[i]) * now) % mod;
		add(a[i], i);
		// printf(">> %d\n", ans);
	}
	// printf("#1x2x# %d\n", ans);
	return ans;
}

int solve_13xx() {
	int ans = 0;
	memset(s, 0, sizeof(s));
	for (int i = 1, now; i <= n; i++) {
		now = l[i] * (a[i] - 1) % mod;
		now = (now - (ll)l[i] * (l[i] - 1) / 2 % mod + mod) % mod;
		now = (now - ask(a[i] - 1) + mod) % mod;
		ans = (ans + (ll)(n - i - r[i]) * now) % mod;
		add(a[i], a[i]);
	}
	// printf("#13xx# %d\n", ans);
	return ans;
}

void main() {
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]);
	memset(s, 0, sizeof(s));
	for (int i = 1; i <= n; i++) l[i] = ask(a[i] - 1), add(a[i], 1);
	memset(s, 0, sizeof(s));
	for (int i = n; i >= 1; i--) r[i] = ask(a[i] - 1), add(a[i], 1);
	ans = (solve_1x2x() + solve_13xx() + solve_1234() - solve_1xxx()) % mod;
	ans = (ans % mod + mod) % mod;
	// for (int i = 1; i <= n; i++) print(l[i], " \n"[i == n]);
	// for (int i = 1; i <= n; i++) print(r[i], " \n"[i == n]);
	print(ans, '\n');
}

} signed main() { return ringo::main(), 0; }