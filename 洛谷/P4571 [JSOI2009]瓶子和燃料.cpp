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
template <typename T> inline void print(T x, char c = '\n') {
	static int buf[40];
	if (x == 0) { putc('0'); putc(c); return; }
	if (x < 0) putc('-'), x = -x;
	for (buf[0] = 0; x; x /= 10) buf[++buf[0]] = x % 10 + 48;
	while (buf[0]) putc((char) buf[buf[0]--]);
	putc(c);
}

const int maxn = 1010;

int n, k, a[maxn];
std::map < int, int > map;

int main() {
//	freopen("INPUT", "r", stdin);

	read(n), read(k);
	for (int i = 1; i <= n; i++) {
		read(a[i]);
		for (int j = 1; j * j <= a[i]; j++)
			if (a[i] % j == 0) {
				if (j * j == a[i]) {
					map[j]++;
				} else {
					map[j]++;
					map[a[i] / j]++;
				}
			}
	}
	for (std::map < int, int > ::reverse_iterator it = map.rbegin(); it != map.rend(); it++)
		if (it->second >= k){
			printf("%d\n", it->first);
			return 0;
		}
	
	return 0;
}