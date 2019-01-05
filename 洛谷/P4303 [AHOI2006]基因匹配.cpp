// luogu-judger-enable-o2
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

const int maxn = 200010;
int n;
int a[maxn * 5], b[maxn * 5], max[maxn * 5];

typedef std::vector < int > vector;
vector vet[maxn];

void modify(int k, int x) {
	for (int i = k; i <= n * 5; i += i & -i)
		max[i] = std::max(max[i], x);
	// printf("modify %d : %d\n", k, x);
}

int query(int k) {
	int ret = 0;
	for (int i = k; i >= 1; i -= i & -i)
		ret = std::max(ret, max[i]);
	// printf("query %d => %d\n", k, ret);
	return ret;
}

int main() {
	// freopen("1.in", "r", stdin);
	read(n);
	for (int i = 1; i <= n * 5; i++)
		read(a[i]);
	for (int i = 1; i <= n * 5; i++)
		read(b[i]);
	for (int i = 1; i <= n * 5; i++)
		vet[b[i]].push_back(i);
	for (int i = 1; i <= n * 5; i++) {
		for (vector ::reverse_iterator it = vet[a[i]].rbegin(); it != vet[a[i]].rend(); it++) {
			modify(*it, query(*it - 1) + 1);
		}
	}
	print(query(n * 5), '\n');
	return 0;
}