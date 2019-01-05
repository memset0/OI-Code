// ==============================
//  author: memset0
//  website: https://memset0.cn
//  note: _rqy ÓÖÇ¿ÓÖ¿É°®
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
template <typename T> inline void print(T x, char c = '\n') {
	static int buf[40];
	if (x < 0) putc('-'), x = -x; else if (x == 0) putc('0');
	else {
		for (buf[0] = 0; x; x /= 10) buf[++buf[0]] = x % 10 + 48;
		while (buf[0]) putc((char) buf[buf[0]--]);
	} putc(c);
}

const int maxn = 50000;

int n, m, l, r, tmp, fa[maxn], stp[maxn], data[maxn][8];
bool vis[maxn];

struct node {
	int a[8], stp, val;
	int load() {
		val = 0;
		int mul, cnt;
//		for (int i = 0; i < 8; i++)
//			printf("%d ", a[i]);
//		puts("");
		for (int i = 0; i < 8; i++) {
			cnt = a[i] - 1;
			for (int j = 0; j < i; j++)
				if (a[j] < a[i])
					cnt--;
			mul = 1;
			for (int j = 1; j < 8 - i; j++)
				mul *= j;
			val += cnt * mul;
		}
//		for (int i = 0; i < 8; i++)
//			if (data[val][i]) {
//				if (a[i] ^ data[val][i]) {
//					puts("WARNING!");
//					for (int i = 0; i < 8; i++)
//						print(a[i], ' ');
//					putc('\n');
//					for (int i = 0; i < 8; i++)
//						print(data[val][i], ' ');
//					putc('\n');
//				}
//			} else data[val][i] = a[i];
		return val;
	}
} s, e, u, v, q[maxn];

void dfs(int u) {
	if (u == s.val) return;
	dfs(fa[u]);
	putc(!stp[u] ? 'A' : stp[u] == 1 ? 'B' : 'C');
}

int main() {
//	freopen("INPUT", "r", stdin);
//	freopen("OUTPUT", "w", stdout);

//	for (int i = 0; i < 8; i++)
//		s.a[i] = i + 1;
	s.a[0] = 1;
	s.a[1] = 2;
	s.a[2] = 3;
	s.a[3] = 4;
	s.a[4] = 8;
	s.a[5] = 7;
	s.a[6] = 6;
	s.a[7] = 5;
//	printf("%d\n", s.load());
	
	read(e.a[0]);
	read(e.a[1]);
	read(e.a[2]);
	read(e.a[3]);
	read(e.a[7]);
	read(e.a[6]);
	read(e.a[5]);
	read(e.a[4]);
	s.load(), e.load();
	q[1] = s, l = r = 1, vis[s.val] = 1;
	
	if (s.val == e.val) {
		puts("0");
		return 0;
	}
	
	while (l <= r) {
		u = q[l++];
		for (int i = 0; i < 3; i++) {
			v = u;
			switch (i) {
				case 0:
					tmp = v.a[0], v.a[0] = v.a[4], v.a[4] = tmp;
					tmp = v.a[1], v.a[1] = v.a[5], v.a[5] = tmp;
					tmp = v.a[2], v.a[2] = v.a[6], v.a[6] = tmp;
					tmp = v.a[3], v.a[3] = v.a[7], v.a[7] = tmp;
					break;
				case 1:
					tmp = v.a[3], v.a[3] = v.a[2], v.a[2] = v.a[1], v.a[1] = v.a[0], v.a[0] = tmp;
					tmp = v.a[7], v.a[7] = v.a[6], v.a[6] = v.a[5], v.a[5] = v.a[4], v.a[4] = tmp;
					break;
				case 2:
					tmp = v.a[2], v.a[2] = v.a[1], v.a[1] = v.a[5], v.a[5] = v.a[6], v.a[6] = tmp;
					break;
			}
			v.stp = u.stp + 1;
			v.load();
			if (!vis[v.val]) {
				vis[v.val] = 1;
				fa[v.val] = u.val;
				stp[v.val] = i;
				q[++r] = v;
				if (v.val == e.val) {
//					for (int i = 0; i < 8; i++)
//						printf("%d ", v.a[i]);
//					puts("");
					print(v.stp, '\n');
					dfs(v.val);
					putc('\n');
					return 0;
				}
			}
		}
	}

	return 0;
}