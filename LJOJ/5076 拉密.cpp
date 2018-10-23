// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r) for (int i = l; i <= r; i++)
#define getc(x) getchar(x)
#define putc(x) putchar(x)

template <typename T> inline void read(T &x) {
	x = 0; register char ch; register bool fl = 0;
	while (ch = getc(), ch < 48 || 57 < ch) fl ^= ch == '-'; x = (ch & 15);
	while (ch = getc(), 47 < ch && ch < 58) x = (x << 1) + (x << 3) + (ch & 15);
	if (fl) x = -x;
}
template <typename T> inline void readc(T &x) {
	while (x = getc(), !islower(x) && !isupper(x));
}
template <typename T> inline void print(T x, char c = ' ') {
	static int buf[40];
	if (x == 0) { putc('0'); putc(c); return; }
	if (x < 0) putc('-'), x = -x;
	for (buf[0] = 0; x; x /= 10) buf[++buf[0]] = x % 10 + 48;
	while (buf[0]) putc((char) buf[buf[0]--]);
	putc(c);
}

const int maxn = 22;
const int mod = 1000000007;

int n, m, t, x, s, sum, cnt, ans, flag, point;
int a[maxn], inv[maxn];

int f[1 << 20];
bool p[1 << 20];

typedef std::vector < int > vector;
vector pos, vet;
vector::iterator it, at;

inline void read_card(int &x) {
	int t;
	readc(t);
	if (t == 'K') x = 1;
	else if (t == 'R') x = 2;
	else if (t == 'B') x = 3;
	else x = 4;
	read(t);
	x = (x - 1) * 13 + t - 1;
}

inline int get_point(int x) {
	return x % 13 + 1;
}

inline int get_color(int x) {
	return x / 13 + 1;
}

bool check(int x) {
	vet.clear();
	for (int i = 1; i <= n; i++)
		if (x & (1 << (i - 1)))
			vet.push_back(a[i]);
	if (vet.size() < 3)
		return false;
	std::sort(vet.begin(), vet.end());
	point = get_point(*vet.begin()), flag = true;
	for (it = vet.begin(); it != vet.end(); it++)
		if (point != get_point(*it)) {
			flag = false;
			break;
		}
	if (flag)
		return true;
	flag = true;
	for (at = vet.begin(), it = at++; at != vet.end(); it++, at++)
		if (get_point(*at) - get_point(*it) != 1 || get_color(*at) != get_color(*it)) {
			flag = false;
			break;
		}
	if (flag)
		return true;
	return false;
}

void output(int x) {
	for (int i = 1; i <= n; i++)
		if (x & (1 << (i - 1)))
			putc('1');
		else
			putc('0');
}

int main() {
	// freopen("rummikub.in", "r", stdin);
	// freopen("rummikub.out", "w", stdout);

	read(n), read(m);
	for (int i = 1; i <= n; i++)
		read_card(a[i]);
	inv[0] = inv[1] = 1;
	for (int i = 2; i <= n; i++)
		inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
	for (int i = 0; i < (1 << n); i++)
		if (check(i))
			pos.push_back(i);
//	for (it = pos.begin(); it != pos.end(); it++)
//		output(*it), putc('\n');
//	putc('\n');
	p[0] = 1;
	for (int x = 0; x < (1 << n); x++)
		if (p[x]) {
//			output(x), putc('\n');
			for (it = pos.begin(); it != pos.end(); it++)
				if (!(x & *it))
					p[x | *it] = 1;
		}
//	putc('\n');
	p[0] = 0;
	for (int k = 1; k <= m; k++) {
		read(t), s = ans = 0;
		for (int i = 1; i <= t; i++)
			read(x), s |= (1 << (x - 1));
		f[s] = 1;
		for (int x = s; x < (1 << n); x++)
			if (f[x]) {
//				output(x), putc(' '), print(f[x], '\n');
				if (p[x]) {
					sum = 0;
					for (int i = 1; i <= n; i++)
						if (!(x & (1 << (i - 1))))
							sum = sum + get_point(a[i]);
					ans = (ans + 1ll * f[x] * sum) % mod;
				} else {
					cnt = 0;
					for (int i = 1; i <= n; i++)
						if (x & (1 << (i - 1)))
							++cnt;
					for (int i = 1; i <= n; i++)
						if (!(x & (1 << (i - 1))))
							f[x | (1 << (i - 1))] = (f[x | (1 << (i - 1))] + 1ll * f[x] * inv[n - cnt]) % mod;
				}
				f[x] = 0;
			}
		print(ans, '\n');
	}
	return 0;
}
