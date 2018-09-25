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
	if (x == 0) { putc('0'); return; }
	if (x < 0) putc('-'), x = -x;
	for (buf[0] = 0; x; x /= 10) buf[++buf[0]] = x % 10 + 48;
	while (buf[0]) putc((char) buf[buf[0]--]);
	putc(c);
}

const int maxn = 50010, maxm = 1000010, maxe = maxn * 40;

int n, m = 1000000, l, r, pos, root;
int lc[maxe], rc[maxe];
bool mrk[maxm], tag[maxe];

void modify(int &u, int l, int r, int ql, int qr) {
	if (!u) u = ++pos;
	if (tag[u]) return;
	if (l == ql && r == qr) {
		tag[u] = 1;
		return;
	}
	int mid = (l + r) >> 1;
	if (qr <= mid) modify(lc[u], l, mid, ql, qr);
	else if (ql > mid) modify(rc[u], mid + 1, r, ql, qr);
	else {
		modify(lc[u], l, mid, ql, mid);
		modify(rc[u], mid + 1, r, mid + 1, qr);
	}
	tag[u] |= tag[lc[u]] & tag[rc[u]];
}

void output(int u, int l, int r) {
	if (!u) return;
	if (tag[u]) {
		for (int i = l; i <= r; i++)
			mrk[i] = 1;
		return;
	}
	if (l == r) return;
	int mid = (l + r) >> 1;
	output(lc[u], l, mid);
	output(rc[u], mid + 1, r);
}

int main() {
	
	read(n);
	for (int i = 1; i <= n; i++) {
		read(l), read(r);
		modify(root, 1, m, l, r);
	}
	output(root, 1, m);
	for (int i = 1; i <= m; i++)
		printf("%d ", mrk[i]);
	
	return 0;
}
