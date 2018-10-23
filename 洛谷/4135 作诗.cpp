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

const int maxn = 100010, maxm = 320;

int n, m, c, l, r, sqn, top;

int ans, lastans;
int a[maxn], fst[maxm], bln[maxn], stk[maxn], tmp[maxn];
int cnt[maxm][maxn], sum[maxm][maxm];
bool tag[maxn];

void clear_tag() {
	for (int i = 1; i <= top; i++)
		tag[stk[i]] = 0;
}

int main() {
	// freopen("1.in", "r", stdin);
	read(n), read(c), read(m);
	for (int i = 1; i <= n; i++)
		read(a[i]);
	sqn = sqrt(n);
	for (int i = 1; i <= n; i++)
		bln[i] = (i - 1) / sqn + 1;
	for (int i = 1; i <= bln[n]; i++)
		fst[i] = (i - 1) * sqn + 1;
	fst[bln[n] + 1] = n + 1;
	for (int i = 1; i <= bln[n]; i++) {
		top = 0;
		for (int j = fst[i]; j <= fst[i + 1] - 1; j++)
			cnt[i][a[j]]++, tmp[a[j]]++, stk[++top] = a[j];
		clear_tag();
		for (int j = 1; j < i; j++) {
			sum[j][i] = sum[j][i - 1];
			for (int k = 1; k <= top; k++)
				if (!tag[stk[k]]) {
					if (cnt[i - 1][stk[k]] - cnt[j - 1][stk[k]])
						if (!((cnt[i - 1][stk[k]] - cnt[j - 1][stk[k]]) & 1))
							sum[j][i]--;
					if (!((tmp[stk[k]] + cnt[i - 1][stk[k]] - cnt[j - 1][stk[k]]) & 1))
						sum[j][i]++;
					tag[stk[k]] = 1;
				}
			clear_tag();
		}
		for (int j = 1; j <= top; j++)	
			if (tmp[stk[j]]) {
				if (!(tmp[stk[j]] & 1))
					sum[i][i]++;
				tmp[stk[j]] = 0;
			}
		for (int j = 1; j <= c; j++)
			cnt[i][j] += cnt[i - 1][j];
	}
	// for (int i = 1; i <= bln[n]; i++)
	// 	printf("> %d %d\n", fst[i], fst[i + 1] - 1);
	// for (int i = 1; i <= bln[n]; i++) {
	// 	for (int j = 1; j <= bln[n]; j++) {
	// 		printf("(%d,%d)", sum[i][j][0], sum[i][j][1]);
	// 	}
	// 	putc('\n');
	// }
	for (int i = 1; i <= m; i++) {
		read(l), read(r);
		l = (l + lastans) % n + 1;
		r = (r + lastans) % n + 1;
		if (l > r) std::swap(l, r);
		// printf(">>> %d %d\n", l, r);
		top = 0;
		if (bln[l] == bln[r]) {
			ans = 0;
			for (int i = l; i <= r; i++)
				tmp[a[i]]++, stk[++top] = a[i];
			for (int i = 1; i <= top; i++)
				if (tmp[stk[i]]) {
					if (!(tmp[stk[i]] & 1))
						ans++;
					tmp[stk[i]] = 0;
				}
		} else {
			ans = sum[bln[l] + 1][bln[r] - 1];
			for (int i = l; i < fst[bln[l] + 1]; i++)
				tmp[a[i]]++, stk[++top] = a[i];
			for (int i = fst[bln[r]]; i <= r; i++)
				tmp[a[i]]++, stk[++top] = a[i];
			for (int i = 1; i <= top; i++)
				if (tmp[stk[i]]) {
					// printf("%d : %d\n", stk[i], tmp[stk[i]]);
					if (cnt[bln[r] - 1][stk[i]] - cnt[bln[l]][stk[i]])
						if (!((cnt[bln[r] - 1][stk[i]] - cnt[bln[l]][stk[i]]) & 1))
							ans--;
					if (!((tmp[stk[i]] + cnt[bln[r] - 1][stk[i]] - cnt[bln[l]][stk[i]]) & 1))
						ans++;
					tmp[stk[i]] = 0;
				}
		}
		// printf(">>> %d %d\n", ans[0], ans[1]);
		print(lastans = ans, '\n');
	}
	return 0;
}