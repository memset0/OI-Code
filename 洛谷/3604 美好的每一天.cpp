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
	register char ch;
	while (ch = getc(), !islower(ch));
	x = ch - 'a';
}
template <typename T> inline void print(T x, char c = '\n') {
	static int buf[40];
	if (x == 0) { putc('0'); putc(c); return; }
	if (x < 0) putc('-'), x = -x;
	for (buf[0] = 0; x; x /= 10) buf[++buf[0]] = x % 10 + 48;
	while (buf[0]) putc((char) buf[buf[0]--]);
	putc(c);
}

const int maxn = 60010;

int n, m, l, r, ql, qr, sqn, now;
int a[maxn], bit[maxn], bln[maxn], ans[maxn];
short cnt[1 << 26];

struct query {
	int l, r, i;
} q[maxn];
inline bool operator < (const query &a, const query &b) {
	if (bln[a.l] ^ bln[b.l]) return a.l < b.l;
	if (bln[a.l] & 1) return a.r < b.r;
	else return a.r > b.r;
}

inline void insert(int x) {
//	printf("insert(%d) : %d\n", x, bit[x]);
	now += cnt[bit[x]];
	for (register int i = 0; i < 26; i++)
		now += cnt[bit[x] ^ (1 << i)];
	++cnt[bit[x]];
//	printf("-> %d\n", now);
}

inline void erase(int x) {
//	printf("erase(%d) : %d\n", x, bit[x	]);
	--cnt[bit[x]];
	now -= cnt[bit[x]];
	for (register int i = 0; i < 26; i++)
		now -= cnt[bit[x] ^ (1 << i)];
//	printf("-> %d\n", now);
}

int main() {
//	freopen("INPUT", "r", stdin);
//	freopen("OUTPUT", "w", stdout);

	read(n), read(m);
	sqn = n / sqrt(m * 2.0 / 3);
	for (int i = 1; i <= n; i++)
		readc(a[i]);
//	std::cerr << std::clock() << std::endl;
	for (int i = 0; i <= n; i++)
		bln[i] = i / sqn;
	for (int i = 1; i <= n; i++)
		bit[i] = bit[i - 1] ^ (1 << a[i]);
	for (int i = 1; i <= m; i++) {
		read(q[i].l);
		read(q[i].r);
		q[i].i = i;
	}
	std::sort(q + 1, q + m + 1);
//	std::cerr << std::clock() << std::endl;
	
	ql = 0, qr = -1;
	for (int i = 1; i <= m; i++) {
		l = q[i].l - 1, r = q[i].r;
//		printf("=== %d -> %d ===\n", l, r);
//		printf("%d %d %d %d\n", l, bln[l], r, bln[r]);
		while (ql < l) erase(ql++);
		while (ql > l) insert(--ql);
		while (qr > r) erase(qr--);
		while (qr < r) insert(++qr);
		ans[q[i].i] = now;
//		printf("=> %d\n", now);
	}
//	std::cerr << std::clock() << std::endl;
	
	for (int i = 1; i <= m; i++)
		print(ans[i]);
//	std::cerr << std::clock() << std::endl;
	
	return 0;
}
