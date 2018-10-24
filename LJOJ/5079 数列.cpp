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

const int maxn = 100010;

int n, tn;
int a[maxn], b[maxn], f[maxn];

typedef std::vector < int > vector;
typedef vector::iterator iterator;
vector s[maxn];

struct max_node {
	bool tag;
	int val, key;
} first, second;

int main() {
	// freopen("1.in", "r", stdin);
	// freopen("2.out", "w", stdout);
	read(n);
	for (int i = 1; i <= n; i++)
		read(a[i]), b[++tn] = a[i];
	std::sort(b + 1, b + tn + 1);
	tn = std::unique(b + 1, b + tn + 1) - b - 1;
	n = std::unique(a + 1, a + n + 1) - a - 1;
	for (int i = 1; i <= n; i++)
		a[i] = std::lower_bound(b + 1, b + tn + 1, a[i]) - b;
	for (int i = 1; i <= n; i++)
		s[a[i]].push_back(i);
	// print(n, '\n');
	// for (int i = 1; i <= n; i++)
		// print(a[i]);
	// putc('\n');
	first.tag = second.tag = false;
	for (int i = 1; i <= tn; i++) {
		for (iterator it = s[i].begin(); it != s[i].end(); it++) {
			if ((*it != first.key + 1 || s[i].size() == 1) && first.tag) {
				f[*it] = first.val;
			} else if ((*it != second.key + 1 || s[i].size() == 1) && second.tag) {
				f[*it] = second.val;
			}
			f[*it] += a[*it + 1] == i + 1;
		}
		first.tag = second.tag = false;
		for (iterator it = s[i].begin(); it != s[i].end(); it++) {
			if (!first.tag || f[*it] > first.val) {
				second = first;
				first.key = *it;
				first.tag = true;
				first.val = f[*it];
			} else if (!second.tag || f[*it] > second.val) {
				second.key = *it;
				second.tag = true;
				second.val = f[*it];
			}
		}
		// printf("%d : %d(%d)(%d) %d(%d)(%d)\n", i, first.tag ? first.val : -1, first.key, a[first.key + 1] == i + 1, second.tag ? second.val : -1, second.key, a[second.key + 1] == i + 1);
		// for (iterator it = s[i].begin(); it != s[i].end(); it++)
			// printf("    %d > %d\n", *it, f[*it]);
	}
	print(n - 1 - (first.tag ? first.val : 0), '\n');
	return 0;
}


/*
201 : 43 -1
    278 > 43
202 : 43 43
    281 > 43
    285 > 43
    287 > 43
203 : 44 43
    282 > 44
    286 > 43

*/