// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r) for (int i = l; i <= r; i++)
#define getc(x) getchar(x)
#define putc(x) putchar(x)
#define endl ('\n')

template <typename T> inline void read(T &x) {
	x = 0; register char ch; register bool fl = 0;
	while (ch = getc(), ch < 48 || 57 < ch) fl ^= ch == '-'; x = (ch & 15);
	while (ch = getc(), 47 < ch && ch < 58) x = (x << 1) + (x << 3) + (ch & 15);
	if (fl) x = -x;
}
template <typename T> inline void print(T x, char c = ' ') {
	static int buf[40];
	if (x == 0) { putc('0'); putc(c); return; }
	if (x < 0) putc('-'), x = -x;
	for (buf[0] = 0; x; x /= 10) buf[++buf[0]] = x % 10 + 48;
	while (buf[0]) putc((char) buf[buf[0]--]);
	putc(c);
}

const int maxn = 100010, maxm = maxn * 33;

int n, m, rt, tot;
ll ans, ful;
ll a[maxn], b[maxn], s[maxn];
int cnt[maxm][2], siz[maxm], lc[maxm], rc[maxm];

void insert(int &u, ll x, int h) {
	if (!h) return;
	if (!u) u = ++tot;
//	printf("insert %d %d\n", u, h);
	int side = x & (1 << (h - 1)) ? 1 : 0;
	cnt[u][side]++, siz[u]++;
	insert(side ? rc[u] : lc[u], x, h - 1);
}

//void dfs(int u, int h, int flag, ll sum, ll now) {
//	if (!u && h) return;
//	if (!siz[u] && h) return;
//	if (!h) {
//		if (!flag) return;
////		printf("dfs %d %d %d %d %d\n", u, h, flag, sum, now);
//		if (sum > ans) ans = sum, ful = 0;
//		else if (ans == sum) ful++;
//		return;
//	}
//	if (flag) {
//		dfs(lc[u], h - 1, flag, sum | (1 << (h - 1)), cnt[u][0]);
//		dfs(rc[u], h - 1, flag, sum | (1 << (h - 1)), cnt[u][1]);
//	} else {
//		if (cnt[u][0] && cnt[u][1]) {
//			flag = 1;
//			dfs(lc[u], h - 1, flag, sum, cnt[u][0]);
//			dfs(rc[u], h - 1, flag, sum, cnt[u][1]);
//		} else {
//			dfs(lc[u], h - 1, flag, sum | (1 << (h - 1)), cnt[u][0]);
//			dfs(rc[u], h - 1, flag, sum | (1 << (h - 1)), cnt[u][1]);
//		}
//	}
//}

void dfs(int u, int h, int sum) {
//	printf("dfs %d %d %d\n", u, h, sum);
	if (!h) {
		if (sum > ans) ans = sum, ful = 0;
		if (sum == ans) ful++;
		return;
	}
	if (!cnt[u][0]) return (void) dfs(rc[u], h - 1, sum | (1 << (h - 1)));
	if (!cnt[u][1]) return (void) dfs(lc[u], h - 1, sum | (1 << (h - 1)));
	dfs(lc[u], h - 1, sum), dfs(rc[u], h - 1, sum);
}

void output(int u, int h, int sum, int ans) {
//	printf("output %d %d %d %d\n", u, h, sum, ans);
	if (!u && h) return;
	if (!h) {
		printf("%d * %d\n", sum, ans);
		return;
	}
	output(lc[u], h - 1, sum, cnt[u][0]);
	output(rc[u], h - 1, sum | (1 << (h - 1)), cnt[u][1]);
}

int main() {
//	freopen("INPUT", "r", stdin);
//	freopen("3.txt", "r", stdin);
//	freopen("1.txt", "w", stdout);

	read(n), read(m);
	for (int i = 1; i <= m; i++)
		read(a[i]);
	for (int i = 1; i <= m; i++)
		if ((a[i] << 1) < (1 << n)) b[i] = a[i] << 1;
		else b[i] = (a[i] << 1) - (1 << n) + 1;
	for (int i = 1; i <= m; i++)
		s[0] ^= b[i];
	for (int i = 1; i <= m; i++)
		s[i] = s[i - 1] ^ a[i] ^ b[i];
	for (int i = 0; i <= m; i++) {
		insert(rt, s[i], n);
//		output(rt, n, 0, 0);
	}
//	for (int i = 0; i <= m; i++) print(a[i]); putc('\n');
//	for (int i = 0; i <= m; i++) print(b[i]); putc('\n');
//	for (int i = 0; i <= m; i++) print(s[i]); putc('\n');
	dfs(rt, n, 0);
	printf("%lld\n%lld\n", ans, ful);

	return 0;
}
