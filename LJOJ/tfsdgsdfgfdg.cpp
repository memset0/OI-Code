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

unsigned int SA, SB, SC;
inline unsigned int rd() {
	SA ^= SA << 16, SA ^= SA >> 5, SA ^= SA << 1;
	unsigned int t=SA; SA=SB, SB=SC, SC ^= t ^ SA;
	return SC;
}

const int maxn = 2000010;
int n;
int s[maxn], hep[maxn];
ll ans;

struct node {
	int a, b, c;
} a[maxn], b[maxn];
inline bool cmp1(const node &a, const node &b) {
	return a.a < b.a;
}

#define lowbit(x) ((x)&(-(x)))

void add(int x) {
	for (int i = x; i <= n; i += lowbit(i))
		s[i] += 1;
}

int ask(int x) {
	int ret = 0;
	for (int i = x; i >= 1; i -= lowbit(i))
		ret += s[i];
	return ret;
}

void print() {
	for (int i = 1; i <= n; i++)
		printf(">>> %d %d %d\n", a[i].a, a[i].b, a[i].c);
	putc('\n');
}

int main() {
	freopen("cdq1.in", "r", stdin);
//	freopen("cdq.out", "w", stdout);

	scanf("%d%u%u%u", &n, &SA, &SB, &SC);
	for (int i = 1; i <= n; ++i)
		a[i].a = a[i].b = a[i].c = i;
	for (int i = 1; i <= n; ++i)
		std::swap(a[i].a, a[1 + rd() % n].a);
	for (int i = 1; i <= n; ++i)
		std::swap(a[i].b, a[1 + rd() % n].b);
	for (int i = 1; i <= n; ++i)
		std::swap(a[i].c, a[1 + rd() % n].c);
	
	print();
	for (int i = 1; i <= n; i++)
		hep[a[i].a] = i;
	for (int i = 1; i <= n; i++)
		b[i] = a[hep[i]];
	for (int i = 1; i <= n; i++)
		a[i] = b[i];
	print();
	
	ans = 1ll * n * (n - 1) / 2;
	print(ans, '\n');
	for (int i = n; i >= 1; i--) {
		ans -= ask(a[i].b);
		add(a[i].b);
	}
	print(ans, '\n');
	memset(s, 0, sizeof(s));
	for (int i = n; i >= 1; i--) {
		ans -= ask(a[i].c);
		add(a[i].c);
	}
	print(ans, '\n');
	
	for (int i = 1; i <= n; i++)
		hep[a[i].b] = i;
	for (int i = 1; i <= n; i++)
		b[i] = a[hep[i]];
	for (int i = 1; i <= n; i++)
		a[i] = b[i];
	print();
	
	memset(s, 0, sizeof(s));
	for (int i = 1; i <= n; i++) {
		ans += ask(a[i].c);
		printf("> %d\n", ask(a[i].c));
		add(a[i].c);
	}
	print(ans, '\n');
	
	return 0;
}
