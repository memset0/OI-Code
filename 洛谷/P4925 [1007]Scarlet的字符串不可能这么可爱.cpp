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

ll k, l, p, s, w;

inline ll pow(ll a, ll b) {
	ll res = 1;
	a %= p;
	while (b) {
		if (b & 1)
			res = res * a % p;
		a = a * a % p;
		b >>= 1;
	}
	return res;
}

inline ll inv(ll x) {
	return pow(x, p - 2);
}

int main() {
	
	read(k), read(l), read(p), read(s);
	if (l == 1)
		print(s ? 1 : k % p);
	else if (l == 2)
		print(k % p * ((k - 1) % p) % p * (s ? inv(k) : 1) % p);
	else
		print(k % p * ((k - 1) % p) % p * (s ? inv(k) : 1) % p * pow(k - 2, l - 2) % p);
	putc('\n');
		
	return 0;
}