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

const int maxn = 500010, maxm = 210, maxk = 1010;

int n, m, q, w, l, r, t, a, b, c, d, now, mid, ans, pos;
int v[maxm][maxm], sum[maxm][maxm][maxk], cnt[maxm][maxm][maxk];
int h[maxn], root[maxn];

int get_sum(int a, int b, int c, int d, int w) { return sum[c][d][w] + sum[a - 1][b - 1][w] - sum[a - 1][d][w] - sum[c][b - 1][w]; }
int get_cnt(int a, int b, int c, int d, int w) { return cnt[c][d][w] + cnt[a - 1][b - 1][w] - cnt[a - 1][d][w] - cnt[c][b - 1][w]; }

void solve1() {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			read(v[i][j]);
			for (int k = 1; k <= 1000; k++) {
				sum[i][j][k] = sum[i - 1][j][k] + sum[i][j - 1][k] - sum[i - 1][j - 1][k];
				cnt[i][j][k] = cnt[i - 1][j][k] + cnt[i][j - 1][k] - cnt[i - 1][j - 1][k];
				if (k == v[i][j]) {
					sum[i][j][k] += v[i][j];
					cnt[i][j][k] += 1;
				}
			}
		}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			for (int k = 1000; k >= 1; k--) {
				sum[i][j][k] += sum[i][j][k + 1];
				cnt[i][j][k] += cnt[i][j][k + 1];
			}
	// for (int k = 1; k <= 1000; k++) {
	// 	for (int i = 1; i <= n; i++) {
	// 		for (int j = 1; j <= m; j++)
	// 			print(sum[i][j][k]);
	// 		putc('\n');
	// 	} 
	// 	putc('\n');
	// }
	for (int i = 1; i <= q; i++) {
		read(a), read(b), read(c), read(d), read(w);
		l = 1, r = 1000, ans = -1;
		while (l <= r) {
			mid = (l + r) >> 1;
			now = get_sum(a, b, c, d, mid);
			// printf("%d %d %d | %d | %d %d %d %d\n", l, r, mid, now, a, b, c, d);
			if (now >= w) {
				ans = mid;
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}
		if (!~ans) puts("Poor QLW");
		else {
			now = get_sum(a, b, c, d, ans);
			// printf("%d %d %d\n", ans, now - w, get_cnt(a, b, c, d, ans));
			ans = get_cnt(a, b, c, d, ans) - (now - w) / ans;
			print(ans, '\n');
		}
	}
}

struct node {
	int lc, rc, cnt, sum;
} p[maxn << 4];

void build(int l, int r, int &u) {
	u = ++pos;
	if (l == r) return;
	int mid = (l + r) >> 1;
	build(l, mid, p[u].lc);
	build(mid + 1, r, p[u].rc);
}

void insert(int w, int l, int r, int &u, int v) {
	u = ++pos, p[u] = p[v];
	// printf("insert %d %d %d %d %d\n", w, l, r, u, v);
	if (l == r) {
		p[u].sum += w;
		p[u].cnt += 1;
		return;
	}
	int mid = (l + r) >> 1;
	if (w <= mid) insert(w, l, mid, p[u].lc, p[v].lc);
	else insert(w, mid + 1, r, p[u].rc, p[v].rc);
	p[u].sum = p[p[u].lc].sum + p[p[u].rc].sum;
	p[u].cnt = p[p[u].lc].cnt + p[p[u].rc].cnt;
}

int query(int ql, int qr, bool flag, int l, int r, int u, int v) {
	// printf("query %d %d %d %d %d %d\n", ql, qr, l, r, u, v);
	if (ql == l && qr == r) return flag ? p[u].sum - p[v].sum : p[u].cnt - p[v].cnt;
	int mid = (l + r) >> 1;
	if (qr <= mid) return query(ql, qr, flag, l, mid, p[u].lc, p[v].lc);
	else if (ql > mid) return query(ql, qr, flag, mid + 1, r, p[u].rc, p[v].rc);
	else return query(ql, mid, flag, l, mid, p[u].lc, p[v].lc) +
		query(mid + 1, qr, flag, mid + 1, r, p[u].rc, p[v].rc);
}

int get_sum(int l, int r, int w) { return query(w, 1000, 1, 1, 1000, root[r], root[l - 1]); }
int get_cnt(int l, int r, int w) { return query(w, 1000, 0, 1, 1000, root[r], root[l - 1]); }

void solve2() {
	n = m;
	build(1, 1000, root[0]);
	for (int i = 1; i <= n; i++) {
		read(h[i]);
		insert(h[i], 1, 1000, root[i], root[i - 1]);
	}
	for (int i = 1; i <= q; i++) {
		read(t), read(a), read(t), read(b), read(w);
		l = 1, r = 1000, ans = -1;
		while (l <= r) {
			mid = (l + r) >> 1;
			now = get_sum(a, b, mid);
			// printf("%d %d %d | %d | %d %d\n", l, r, mid, now, a, b);
			if (now >= w) {
				ans = mid;
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}
		if (!~ans) puts("Poor QLW");
		else {
			now = get_sum(a, b, ans);
			// printf("%d %d %d\n", ans, now - w, get_cnt(a, b, ans));
			ans = get_cnt(a, b, ans) - (now - w) / ans;
			print(ans, '\n');
		}
	}
}

int main() {
	// freopen("1.in", "r", stdin);

	read(n), read(m), read(q);
	if (n == 1) solve2();
	else solve1();

	return 0;
}