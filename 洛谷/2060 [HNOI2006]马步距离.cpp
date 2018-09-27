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
template <typename T> inline void print(T x, char c = ' ') {
	static int buf[40];
	if (x == 0) { putc('0'); putc(c); return; }
	if (x < 0) putc('-'), x = -x;
	for (buf[0] = 0; x; x /= 10) buf[++buf[0]] = x % 10 + 48;
	while (buf[0]) putc((char) buf[buf[0]--]);
	putc(c);
}

const int mov[8][2] = {
	{1, 2}, {2, 1},
	{-1, 2}, {2, -1}, 
	{1, -2}, {-2, 1},
	{-1, -2}, {-2, -1}
};

#define dis(x,y) (_dis[x + 100][y + 100])

int l, r, ans = 2000000000;
int sx, sy, ex, ey;
int _dis[210][210];

struct node {
	int x, y;
	node () {}
	node (int a, int b) { x = a, y = b; }
} u, v, q[40010];

int fly(int x, int y) {
	if (x > y) std::swap(x, y);
	if ((x + y) % 3 == 0 && ((y << 1) - x) >= 0 && ((x << 1) - y) >= 0) return (x + y) / 3;
	if (y % 2 == 0 && ((x << 1) + y) % 4 == 0 && (y - (x << 1)) >= 0) return y >> 1;
	return 1000000;
}

int main() {
//	freopen("INPUT", "r", stdin);

	read(sx), read(sy), read(ex), read(ey);
	
	l = r = 1, q[1] = node(0, 0), dis(0, 0) = 1;
	while (l <= r) {
		u = q[l++];
		for (int i = 0; i < 8; i++) {
			v.x = u.x + mov[i][0];
			v.y = u.y + mov[i][1];
			if (v.x < -100 || v.y < -100 || v.x > 100 || v.y > 100)
				continue;
			if (dis(v.x, v.y))
				continue;
			dis(v.x, v.y) = dis(u.x, u.y) + 1;
			q[++r] = v;
		}
	}
	
	ex -= sx, ey -= sy;
//	printf("%d %d\n", ex, ey);
	for (int i = -100; i <= 100; i++)
		for (int j = -100; j <= 100; j++)
			if (dis(i, j))
				ans = std::min(fly(abs(i - ex), abs(j - ey)) + dis(i, j) - 1, ans);
//	for (int i = -10; i <= 10; i++) {
//		for (int j = -10; j <= 10; j++)
//			printf("%d ", fly(abs(i - ex), abs(j - ey)) + dis(i, j) - 1);
//		puts("");
//	}
	print(ans, '\n');

	return 0;
}
