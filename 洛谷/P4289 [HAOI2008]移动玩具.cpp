// ==============================
//  author: memset0
//  website: https://memset0.cn
//  note: _rqy 又强又可爱
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
	if (x == 0) { putc('0'); return; }
	if (x < 0) putc('-'), x = -x;
	for (buf[0] = 0; x; x /= 10) buf[++buf[0]] = x % 10 + 48;
	while (buf[0]) putc((char) buf[buf[0]--]);
	putc(c);
}

const int mov[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int a[4][4], b[4][4];
int s, e, l, r, u, v, x, y, stp;

bool vis[100000];

struct status {
	int a, h;
} q[100000];

int convert(int a[4][4]) {
	int ret = 0;
	for (int i = 0; i < 4; i++) 
		for (int j = 0; j < 4; j++) {
			ret += a[i][j] << (i * 4 + j);
//			printf("%d %d\n", a[i][j], (i * 4 + j));
		}
	return ret;
}

int main() {
//	freopen("INPUT", "r", stdin);
//	freopen("OUTPUT", "w", stdout);

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			scanf("%1d", &a[i][j]);
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			scanf("%1d", &b[i][j]);
	s = convert(a), e = convert(b);
	if (s == e) {
		puts("0");
		return 0;
	}
//	printf("%d %d\n", s, e);
	l = r = 1, q[1].a = s, q[1].h = 0, vis[s] = 1;
	while (l <= r) {
		u = q[l].a, stp = q[l].h + 1, l++;
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				a[i][j] = u & (1 << (i * 4 + j)) ? 1 : 0;
//		printf(">>> %d\n", stp);
//		for (int i = 0; i < 4; i++) {
//			for (int j = 0; j < 4; j++)
//				printf("%d ", a[i][j]);
//			puts("");
//		}
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				for (int t = 0; t < 4; t++) {
					x = i + mov[t][0];
					y = j + mov[t][1];
					if (x < 0 || y < 0 || x > 3 || y > 3) continue;
					if (a[i][j] == a[x][y]) continue;
					std::swap(a[i][j], a[x][y]);
					v = convert(a);
//					printf("%d\n", v);
					if (!vis[v]) {
						if (v == e) {
							print(stp);
							return 0;
						}
						vis[v] = 1;
						r++, q[r].a = v, q[r].h = stp;
					}
					std::swap(a[i][j], a[x][y]);
				}
	}
	return 0;
}