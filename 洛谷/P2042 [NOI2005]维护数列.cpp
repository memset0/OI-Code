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

const int maxn = 4000010;

#define inf (1000000000)
#define max2(a,b) std::max(a,b)
#define max3(a,b,c) std::max(a,std::max(b,c))

int n, m, x, y, z, k, l, v, rt, cnt, opt;
int a[maxn], siz[maxn], val[maxn], rnd[maxn], ch[maxn][2];
int sum[maxn], lmax[maxn], rmax[maxn], smax[maxn];
int tag[maxn], rev[maxn];

void read_opt(int &x) {
	register char ch;
	while (ch = getc(), !isupper(ch));
	if (ch == 'I') x = 1;
	else if (ch == 'D') x = 2;
	else if (ch == 'R') x = 4;
	else if (ch == 'G') x = 5;
	else {
		getc(), ch = getc();
		if (ch == 'K') x = 3;
		else x = 6;
	}
	while (ch = getc(), ch != '\n' && ch != ' ');
}

inline int newnode(int v) {
	int u = ++cnt;
	siz[u] = 1, val[u] = v, rnd[v] = rand();
	lmax[u] = rmax[u] = smax[u] = v;
	ch[u][0] = ch[u][1] = 0;
	rev[u] = 0, tag[u] = inf;
	return u;
}

inline void pushup_tag(int u, int v) {
	if (!u) return;
	tag[u] = val[u] = v, rev[u] = 0;
	sum[u] = v * siz[u];
	lmax[u] = rmax[u] = smax[u] = std::max(val[u], sum[u]);
}

inline void pushup_rev(int u) {
	if (!u) return;
	rev[u] ^= 1;
	std::swap(ch[u][0], ch[u][1]);
	std::swap(lmax[u], rmax[u]);
}

inline void pushdown(int u) {
	if (tag[u] ^ inf) {
//		printf("pushdown tag %d(%d)\n", u, val[u]);
		pushup_tag(ch[u][0], tag[u]);
		pushup_tag(ch[u][1], tag[u]);
		tag[u] = inf;
	}
	if (rev[u]) {
//		printf("pushdown rev %d(%d)\n", u, val[u]);
		pushup_rev(ch[u][0]);
		pushup_rev(ch[u][1]);
		rev[u] = 0;
	}
}

inline void update(int u) {
	pushdown(u);
	siz[u] = siz[ch[u][0]] + siz[ch[u][1]] + 1;
	sum[u] = sum[ch[u][0]] + sum[ch[u][1]] + val[u];
	lmax[u] = max2(lmax[ch[u][0]], sum[ch[u][0]] + val[u] + std::max(lmax[ch[u][1]], 0));
	rmax[u] = max2(rmax[ch[u][1]], sum[ch[u][1]] + val[u] + std::max(rmax[ch[u][0]], 0));
	smax[u] = max3(smax[ch[u][0]], smax[ch[u][1]], max2(rmax[ch[u][0]], 0) + val[u] + max2(lmax[ch[u][1]], 0));
}

int build(int l, int r) {
	if (l > r) return 0;
	int mid = (l + r) >> 1;
	int u = newnode(a[mid]);
	ch[u][0] = build(l, mid - 1);
	ch[u][1] = build(mid + 1, r);
	return update(u), u;
}

int merge(int x, int y) {
	if (!x || !y) return x | y;
	if (rnd[x] < rnd[y]) {
		pushdown(x);
		ch[x][1] = merge(ch[x][1], y);
		return update(x), x;
	} else {
		pushdown(y);
		ch[y][0] = merge(x, ch[y][0]);
		return update(y), y;
	}
}

void split(int u, int v, int &x, int &y) {
	if (!u) return (void)(x = y = 0);
	pushdown(u);
	if (v > siz[ch[u][0]]) {
		x = u, split(ch[x][1], v - siz[ch[u][0]] - 1, ch[x][1], y);
	} else {
		y = u, split(ch[y][0], v, x, ch[y][0]);
	}
	update(u);
}

void dfs(int u) {
	pushdown(u);
//	update(u);
	if (ch[u][0]) dfs(ch[u][0]);
//	printf("%d : %d %d %d\n", u, val[u], sum[u], siz[u]);
	print(val[u]);
	if (ch[u][1]) dfs(ch[u][1]);
}

int main() {
//	freopen("INPUT", "r", stdin);
//	freopen("OUTPUT", "w", stdout);
	srand(20040725);
	
	read(n), read(m);
	for (int i = 1; i <= n; i++)
		read(a[i]);
	rt = build(1, n);
	lmax[0] = rmax[0] = smax[0] = -inf;
	for (int i = 1; i <= m; i++) {
		read_opt(opt);
		switch (opt) {
			case 1:
				read(k), read(n);
				for (int i = 1; i <= n; i++)
					read(a[i]);
				split(rt, k, x, z);
				y = build(1, n);
				rt = merge(x, merge(y, z));
				break;
			case 2:
				read(k), read(v);
				split(rt, k - 1, x, y);
				split(y, v, y, z);
				rt = merge(x, z);
				break;
			case 3:
				read(k), read(l), read(v);
				split(rt, k - 1, x, y);
				split(y, l, y, z);
				pushup_tag(y, v);
				rt = merge(x, merge(y, z));
				break;
			case 4:
				read(k), read(l);
				split(rt, k - 1, x, y);
				split(y, l, y, z);
				pushup_rev(y);
				rt = merge(x, merge(y, z));
				break;
			case 5:
				read(k), read(l);
				split(rt, k - 1, x, y);
				split(y, l, y, z);
				print(sum[y], '\n');
				rt = merge(x, merge(y, z));
				break;
			case 6:
				print(smax[rt], '\n');
				break;
		}
//		dfs(rt), putc('\n');
//		printf("%d %d %d\n", lmax[0], rmax[0], smax[0]);
	}

	return 0;
}