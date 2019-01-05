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

const int maxm = 15010, maxl = 20;
const ll mod = 1000000007;

int m, l, tn;
ll n, ans, now, tmp2, tmp3, tmp5, tmp7;
int v[maxl];
ll t[maxm], b[maxm], f[maxl][maxm][2];

struct pair {
	ll v;
	int i, j;
} u;
inline bool operator < (const pair &a, const pair &b) {
	return a.v < b.v;
}

inline bool rev(const int &a, const int &b) {
	return a > b;
}

typedef std::priority_queue < pair > heap;
heap q;

#define find(x) (std::lower_bound(b+1,b+tn+1,x)-b)

void move(int fr, int to, int k, int p) {
	if (p == v[k]) {
		f[k][to][1] += f[k - 1][fr][1];
		f[k][to][0] += f[k - 1][fr][0];
	} else if (p < v[k]) {
		f[k][to][0] += f[k - 1][fr][1];
		f[k][to][0] += f[k - 1][fr][0];
	} else {
		f[k][to][0] += f[k - 1][fr][0];
	}
	// printf("move %d %d %d %d\n", fr, to, k, p);
}

void split(ll n) {
	while (n) v[++l] = n % 10, n /= 10;
	std::reverse(v + 1, v + l + 1);
}

int main() {
	read(n), read(m);
	now = 1;
	for (int c2 = 0; now <= n; c2++) {
		tmp2 = now;
		for (int c3 = 0; now <= n; c3++) {
			tmp3 = now;
			for (int c5 = 0; now <= n; c5++) {
				tmp5 = now;
				for (int c7 = 0; now <= n; c7++) {
					b[++tn] = now;
					now *= 7;
				}
				now = tmp5 * 5;
			}
			now = tmp3 * 3;
		}
		now = tmp2 * 2;
	}
	std::sort(b + 1, b + tn + 1);
	// for (int i = 1; i <= tn; i++)
	// 	print(b[i]);
	// putc('\n');
	split(n);
	for (int k = 1; k <= l; k++) {
		for (int j = 1; j < 10; j++)
			if (k > 1 || (k == 1 && j <= v[1]))
				f[k][j][k == 1 && j == v[1] ? 1 : 0]++;
		for (int i = 1; i <= tn; i++)
			for (int j = 1; j < 10; j++)
				if (b[i] % j == 0)
					move(find(b[i] / j), i, k, j);
	}
	for (int i = 1; i <= tn; i++)
		t[i] = f[l][i][0] + f[l][i][1];
	// for (int t = 1; t <= l; t++) {
	// 	for (int i = 0; i <= tn; i++)
	// 		printf("%d %d %d %d\n", i, b[i], f[t][i][0], f[t][i][1]);
	// 	putc('\n');
	// }
	// for (int i = 1; i <= tn; i++)
	// 	print(t[i]);
	// putc('\n');
	std::sort(t + 1, t + tn + 1, rev);
	for (int i = 1; i <= tn; i++)
		q.push(pair{t[i] * t[1], i, 1});
	for (int i = 1; i <= m; i++) {
		u = q.top(), q.pop();
		ans = (ans + u.v) % mod;
		// printf("> %d %d %d\n", u.v, u.i, u.j);
		if (u.j < n)
			q.push(pair{t[u.i] * t[u.j + 1], u.i, u.j + 1});
	}
	print(ans, '\n');
	return 0;
}