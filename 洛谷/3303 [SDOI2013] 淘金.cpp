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
int m, l, tn;
ll n, now, tmp2, tmp3, tmp5, tmp7;
int v[maxl];
ll t[maxm], b[maxm], f[maxl][maxm][2];

#define find(x) (std::lower_bound(b+1,b+tn+1,x)-b)

void move(int fr, int to, int k, int p) {
	printf("move %d %d %d %d\n", fr, to, k, p);
	if (p == b[k]) {
		f[k][to][1] += f[k - 1][fr][1];
		f[k][to][0] += f[k - 1][fr][0];
	} else if (p < v[k]) {
		f[k][to][0] += f[k - 1][fr][1];
		f[k][to][0] += f[k - 1][fr][0];
	} else {
		f[k][to][0] += f[k - 1][fr][0];
	}
}

void split(int n) {
	while (n) {
		v[++l] = n % 10;
		n /= 10;
	}
	std::reverse(v + 1, v + l + 1);
}

int main() {
	freopen("1.in", "r", stdin);
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
	split(n);
	f[0][1][0] = 1;
	for (int k = 1; k <= l; k++)
		for (int i = 1; i <= tn; i++) {
			move(i, i, k, 1);
			if (b[i] % 2 == 0) move(find(b[i] / 2), i, k, 2);
			if (b[i] % 3 == 0) move(find(b[i] / 3), i, k, 3);
			if (b[i] % 4 == 0) move(find(b[i] / 4), i, k, 4);
			if (b[i] % 5 == 0) move(find(b[i] / 5), i, k, 5);
			if (b[i] % 6 == 0) move(find(b[i] / 6), i, k, 6);
			if (b[i] % 7 == 0) move(find(b[i] / 7), i, k, 7);
			if (b[i] % 8 == 0) move(find(b[i] / 8), i, k, 8);
			if (b[i] % 9 == 0) move(find(b[i] / 9), i, k, 9);
		}
	for (int i = 1; i <= tn; i++)
		t[i] = f[l][i][0] + f[l][i][1];
	for (int i = 1; i <= tn; i++)
		print(t[i]);
	putc('\n');
	for (int i = 1; i <= tn; i++)
		for (int j = 1; j <= tn; j++)
			q.push(t[i] * t[j]);
	for (int i = 1; i <= m; i++)
		
	return 0;
}