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

const int maxn = 500010;
const int M = 99999997, P1 = 20040301, P2 = 19260817;

int n, l, r, mid, ans;
int a[maxn], c[maxn];
int sh1[maxn], sh2[maxn];
int hs1[maxn], hs2[maxn];
int pw1[maxn], pw2[maxn];
int map1[P1 + 10], map2[P2 + 10];

bool check(int x) {
	for (int i = 1; i + x - 1 <= n; i++) {
		sh1[i] = (hs1[i + x - 1] - 1ll * hs1[i] * pw1[x - 1] % P1 + P1) % P1;
		sh2[i] = (hs2[i + x - 1] - 1ll * hs2[i] * pw2[x - 1] % P2 + P2) % P2;
//		printf("%d %d\n", sh1[i], sh2[i]);
		if (!map1[sh1[i]] || !map2[sh2[i]]) {
			map1[sh1[i]] = map2[sh2[i]] = i;
		} else {
			if (i - map1[sh1[i]] >= x && i - map2[sh2[i]] >= x && map1[sh1[i]] == map2[sh2[i]]) {
				for (int i = 1; i + x - 1 <= n; i++)
					map1[sh1[i]] = map2[sh2[i]] = 0;
				return true;
			}
		}
	}
	for (int i = 1; i + x - 1 <= n; i++)
		map1[sh1[i]] = map2[sh2[i]] = 0;
	return false;
}

int main() {
//	freopen("snowman.in", "r", stdin);
//	freopen("snowman.out", "w", stdout);
//	freopen("3.txt", "r", stdin);
//	freopen("1.txt", "w", stdout);

	read(n);
	for (int i = 1; i <= n; i++)
		read(a[i]);
	for (int i = 1; i <= n; i++)
		c[i] = a[i] - a[i - 1];
	for (int i = 1; i <= n; i++)
		hs1[i] = (1ll * hs1[i - 1] * M + c[i] % P1 + P1) % P1;
	for (int i = 1; i <= n; i++)
		hs2[i] = (1ll * hs2[i - 1] * M + c[i] % P2 + P2) % P2;
	pw1[0] = pw2[0] = 1;
	for (int i = 1; i <= n; i++)
		pw1[i] = 1ll * pw1[i - 1] * M % P1;
	for (int i = 1; i <= n; i++)
		pw2[i] = 1ll * pw2[i - 1] * M % P2;
//	for (int i = 1; i <= n; i++)
//		print(c[i]); putc('\n');
//	for (int i = 1; i <= n; i++)
//		print(hs1[i]); putc('\n'); 
//	for (int i = 1; i <= n; i++)
//		print(hs2[i]); putc('\n'); 
	l = 1, r = n;
	while (l <= r) {
		mid = (l + r) >> 1;
//		printf("check %d\n", mid);
		if (check(mid)) {
			ans = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	print(ans, '\n');
	
	return 0;
}
