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

const int maxn = 600010, inf = 1e9;

int n, m, x, y, rt, opt, cnt, top, ans, FG;
int stk[maxn];

struct point {
	int x[2];
	point () {}
	point (int a, int b) { x[0] = a, x[1] = b; } 
} p[maxn]; 
bool operator < (const point &a, const point &b) {
	return a.x[FG] < b.x[FG];
}

struct node {
	int ch[2], min[2], max[2];
	int cnt;
	point a;
} e[maxn];

#define lc e[u].ch[0]
#define rc e[u].ch[1]

void update(int u) {
	for (int i = 0; i ^ 2; i++) {
		e[u].min[i] = e[u].max[i] = e[u].a.x[i];
		if (lc) e[u].min[i] = std::min(e[u].min[i], e[lc].min[i]);
		if (rc) e[u].min[i] = std::min(e[u].min[i], e[rc].min[i]);
		if (lc) e[u].max[i] = std::max(e[u].max[i], e[lc].max[i]);
		if (rc) e[u].max[i] = std::max(e[u].max[i], e[rc].max[i]);
	}
	e[u].cnt = e[lc].cnt + e[rc].cnt + 1;
}

int newnode(point s) {
	int u = top ? stk[top--] : ++cnt;
	e[u].a = s, lc = rc = 0;
	return update(u), u;
}
	
void pia(int u, int k) {
	if (lc) pia(lc, k);
	p[k + e[lc].cnt] = e[u].a, stk[++top] = u;
	if (rc) pia(rc, k + e[lc].cnt + 1);
}

int build(int l, int r, int flag) {
	if (l > r) return 0;
	int mid = (l + r) >> 1;
	FG = flag, std::nth_element(p + l, p + r + 1, p + mid);
	int u = newnode(p[mid]);
	lc = build(l, mid - 1, flag);
	rc = build(mid + 1, r, flag);
	return update(u), u;
}

void check(int &u, int flag) {
	static int ratio = 4;
	if (e[lc].cnt * ratio < e[rc].cnt || e[rc].cnt * ratio < e[lc].cnt)
		pia(u, e[u].cnt), u = build(1, e[u].cnt, flag); 
}

void insert(int &u, point a, int flag) {
	if (!u) return (void)(u = newnode(a));
	insert(a.x[flag] <= e[u].a.x[flag] ? lc : rc, a, flag ^ 1);
	update(u), check(u, flag);
}

inline int min_dis(const point &a, int min[2], int max[2]) {
	return std::min(std::abs(a.x[0] - min[0]), std::abs(a.x[0] - max[0])) +
		std::min(std::abs(a.x[1] - min[1]), std::abs(a.x[1] - max[1]));
}
inline int max_dis(const point &a, int min[2], int max[2]) {
	return std::max(std::abs(a.x[0] - min[0]), std::abs(a.x[0] - max[0])) +
		std::max(std::abs(a.x[1] - min[1]), std::abs(a.x[1] - max[1]));
}

void query(int u, point a) {
	if (!u) return;
	ans = std::min(ans, max_dis(a, e[u].min, e[u].max));
	if (min_dis(a, e[u].min, e[u].max) >= ans) return;
	query(lc, a), query(rc, a);
}

void dfs(int u) {
	if (lc) dfs(lc);
	printf("%d : %d %d %d %d %d %d\n", u, e[u].a.x[0], e[u].a.x[1], e[u].min[0], e[u].min[1], e[u].max[0], e[u].max[1]);
	if (rc) dfs(rc);
}

int main() {
	freopen("INPUT", "r", stdin);
	read(n), read(m);
	for (int i = 1; i <= n; i++) {
		read(x), read(y);
		insert(rt, point(x, y), 0);
	}
	for (int i = 1; i <= m; i++) {
		read(opt), read(x), read(y);
		printf(">>> %d %d %d\n", opt, x, y);
		if (opt == 1) {
			insert(rt, point(x, y), 0);
		} else {
			ans = inf;
			query(rt, point(x, y));
			print(ans, '\n');
		}
		dfs(rt);
	}
	return 0;
}

