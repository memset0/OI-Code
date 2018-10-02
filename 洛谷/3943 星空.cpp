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

const int maxn = 40010, maxm = 70, maxk = 10;

int n, k, m, p, u, l, r, v;
int a[maxk], b[maxm], c[maxk << 1], w[maxk << 1][maxk << 1], dis[maxn], q[maxn], f[1 << 16];
bool t[maxn];

int min(int a, int b) {
	if (!~a) return b;
	if (!~b) return a;
	return std::min(a, b);
}

void bfs(int s, int d) {
	memset(dis, -1, sizeof(dis));
	l = r = 1, q[1] = s, dis[s] = 0;
	while (l <= r) {
		u = q[l++];
		for (int i = 1; i <= m << 1; i++) {
			v = i > m ? u - b[i - m] : u + b[i];
			if (v < 1 || v > n + 1)
				continue;
			if (!~dis[v]) {
				dis[v] = dis[u] + 1;
				q[++r] = v;
			}
		}
	}
	for (int i = 1; i <= p; i++)
		w[d][i] = dis[c[i]];
}

void dp() {
	memset(f, -1, sizeof(f));
	f[0] = 0;
	for (int x = 0; x < (1 << p); x++)
		if (~f[x])
			for (int i = 1; i <= p; i++)
				if (!(x & (1 << (i - 1))))
					for (int j = 1; j <= p; j++)
						if (!(x & (1 << (j - 1))) && i ^ j && ~w[i][j]) {
//							printf("%d -> %d : %d\n", x, x | (1 << (i - 1)) | (1 << (j - 1)), w[i][j]);
							f[x | (1 << (i - 1)) | (1 << (j - 1))] = min(f[x | 1 << (i - 1) | (1 << (j - 1))], f[x] + w[i][j]);
						}
}

int main() {
	
	read(n), read(k), read(m);
	for (int i = 1; i <= k; i++)
		read(a[i]);
	for (int i = 1; i <= m; i++)
		read(b[i]);
	for (int i = 1; i <= k; i++)
		t[a[i]] = 1;
	for (int i = n + 1; i >= 1; i--)
		t[i] = t[i] ^ t[i - 1];
	for (int i = 1; i <= n + 1; i++)
		if (t[i])
			c[++p] = i;
	for (int i = 1; i <= p; i++)
		bfs(c[i], i);
	dp();
	print(f[(1 << p) - 1], '\n');

	return 0;
}
