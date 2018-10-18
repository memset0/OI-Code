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

inline void init();
int n;
unsigned int SA, SB, SC;
inline unsigned int rd() {
	SA ^= SA << 16, SA ^= SA >> 5, SA ^= SA << 1;
	unsigned int t = SA; SA = SB, SB = SC, SC ^= t ^ SA;
	return SC;
}
inline void gen(int *a) {
	for (int i = 1; i <= n; ++i)
		a[i] = i;
	for (int i = 1; i <= n; ++i)
		std::swap(a[i], a[1 + rd() % n]);
}

const int maxn = 2000010;

ll X, Y, Z, ret, ans;
int a[maxn], b[maxn], c[maxn];
int d[maxn], s[maxn], heap[maxn];

void modify(int k) { for (; k <= n; k += k & -k) ++s[k]; }
void query(int k, ll &r) { for (; k; k -= k & -k) r += s[k]; }
void print(int *a) { for (int i = 1; i <= n; ++i) print(a[i]); putc('\n'); }

ll solve(int *a, int *b) {
	memset(s, 0, sizeof(s)), ret = 0;
	// printf("=== solve ===\n");
	// print(a), print(b);
	for (int i = 1; i <= n; i++)
		heap[a[i]] = i;
	for (int i = 1; i <= n; i++)
		d[i] = b[heap[i]];
	// print(d);
	for (int i = 1; i <= n; i++) {
		query(d[i], ret);
		modify(d[i]);
	}
	// printf(">>> %lld\n", ret);
	return ret;
}

int main() {
	// freopen("1.in", "r", stdin);

	scanf("%d%u%u%u", &n, &SA, &SB, &SC);
	gen(a), gen(b), gen(c);
	
	X = solve(a, b);
	Y = solve(a, c);
	Z = solve(b, c);
	ans = (X + Y + Z - ((1ll * n * (n - 1)) >> 1)) >> 1;
	print(ans, '\n');

	return 0;
}