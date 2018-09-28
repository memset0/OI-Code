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

const int maxn = 10510;

int n, l, r, u, max, tot;
int ans[160], len[160];
int ch[maxn][26], fail[maxn], id[maxn], q[maxn];
char s[1000010], a[160][80];

int reads(char *a) {
	scanf("%s", a + 1);
	int len = strlen(a + 1);
	for (int i = 1; i <= len; i++)
		a[i] -= 'a';
	return len;
}

void prints(char *a, int len) {
	for (int i = 1; i <= len; i++)
		putc(a[i] + 'a');
	putc('\n');
}

void clear() {
	max = 0, tot = 1;
	memset(id, 0, sizeof(id));
	memset(ch, 0, sizeof(ch));
	memset(ans, 0, sizeof(ans));
	memset(fail, 0, sizeof(fail));
}

void insert(char *a, int len, int now) {
	int i, u;
	for (i = u = 1; i <= len; u = ch[u][a[i]], i++) {
		if (!ch[u][a[i]])
			ch[u][a[i]] = ++tot;
//		printf("%d %d %d\n", u, ch[u][a[i]], a[i]);
	}
	id[u] = now;
}

void build() {
	l = r = 1, q[1] = 1;
	while (l <= r) {
		u = q[l++];
		for (int i = 0; i < 26; i++)
			if (ch[u][i]) {
				for (int t = fail[u]; t; t = fail[t])
					if (ch[t][i]) {
						fail[ch[u][i]] = ch[t][i];
						break;
					}
				if (!fail[ch[u][i]])
					fail[ch[u][i]] 	= 1;
				q[++r] = ch[u][i];
			}
	}
}

void solve(char *a, int len) {
	for (int i = 1, u = 1; i <= len; i++) {
		while (!ch[u][a[i]] && u ^ 1)
			u = fail[u];
		u = ch[u][a[i]];
		if (!u) u = 1;
//		printf("%d\n", u);
		for (int t = u; t ^ 1; t = fail[t])
			ans[id[t]]++;
	}
}

int main() {

	while (read(n), n) {
		clear();
		
		for (int i = 1; i <= n; i++) {
			insert(a[i], len[i] = reads(a[i]), i);
		}
		build();
		solve(s, reads(s));
		for (int i = 1; i <= n; i++)
			if (ans[i] > ans[max] || !max)
				max = i;
		print(ans[max], endl);
		for (int i = 1; i <= n; i++)
			if (ans[i] == ans[max])
				prints(a[i], len[i]);
//		for (int i = 1; i <= n; i++)
//			print(ans[i]);
//		putc(endl);
	}

	return 0;
}
