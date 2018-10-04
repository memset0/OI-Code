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

const int maxn = 100010;

int n, m, t, l, r, x, ans;
int a[maxn], s[maxn];

struct node {
	int l, r, mid, cnt;
	std::vector < int > x;
} p[maxn << 2];

void build(int u, int l, int r) {
	p[u].l = l, p[u].r = r, p[u].mid = (l + r) >> 1;
	if (l == r) { 
		p[u].cnt = 1;
		return;
	}
	build(u << 1, l, p[u].mid);
	build(u << 1 | 1, p[u].mid + 1, r);
	p[u].cnt = p[u << 1].cnt + p[u << 1 | 1].cnt; 
}

void insert(int u, int l, int r, int x) {
	if (p[u].l == l && p[u].r == r) {
//		printf("> %d < %d\n", u, x);
		p[u].x.push_back(x);
		++s[x];
		return;
	}
	if (r <= p[u].mid) insert(u << 1, l, r, x);
	else if (l > p[u].mid) insert(u << 1 | 1, l, r, x);
	else {
		insert(u << 1, l, p[u].mid, x);
		insert(u << 1 | 1, p[u].mid + 1, r, x);
	}
}

void erase(int u, int k) {
	if (p[u].l == p[u].r) {
		--p[u].cnt;
	} else {
		erase(k <= p[u].mid ? u << 1 : u << 1 | 1, k);
		p[u].cnt = p[u << 1].cnt + p[u << 1 | 1].cnt;
	}
	if (!p[u].cnt) {
		for (std::vector < int > ::iterator it = p[u].x.begin(); it != p[u].x.end(); it++) {
			--s[*it];
			if (!s[*it]) {
//				printf("erase %d\n", *it);
				++ans;
			}
		}
	}
}

int main() {
	
	read(n), read(m);
	for (int i = 1; i <= n; i++)
		read(a[i]);
	build(1, 1, n);
	for (int i = 1; i <= m; i++) {
		read(l), read(r);
		insert(1, l, r, i);
	}
	read(t);
	for (int i = 1; i <= t; i++) {
		read(x);
		x = (x + ans - 1) % n + 1;
//		printf("== %d ==\n", x);
		--a[x];
		if (!a[x]) {
			erase(1, x);
		}
		print(ans, '\n');
	}

	return 0;
}
