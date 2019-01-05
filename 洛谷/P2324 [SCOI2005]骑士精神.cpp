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

const int mov[8][2] = {
	{1, 2}, {1, -2}, {-1, -2}, {-1, 2},
	{2, 1}, {2, -1}, {-2, -1}, {-2, 1}
};

int T, sx, sy, ans, stp, dep;
int a[5][5];
char str[5][5];

int b[5][5] = {
	{1, 1, 1, 1, 1},
	{0, 1, 1, 1, 1},
	{0, 0, -1, 1, 1},
	{0, 0, 0, 0, 1},
	{0, 0, 0, 0, 0}
};

int calc() {
	int ret = 0;
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			if (a[i][j] != b[i][j])
				++ret;
	return ret;
}

void dfs(int stp, int ux, int uy) {
	// printf("dfs %d %d %d\n", stp, ux, uy);
	if (~ans && stp >= ans)
		return;
	int dis = calc();
	if (!dis) {
		ans = ~ans && ans < stp ? ans : stp;
		return;
	} else if (dis + stp > dep) {
		return;
	}
	for (int i = 0; i < 8; i++) {
		int vx = ux + mov[i][0];
		int vy = uy + mov[i][1];
		if (vx < 0 || vy < 0 || vx > 4 || vy > 4)
			continue;
		std::swap(a[ux][uy], a[vx][vy]);
		dfs(stp + 1, vx, vy);
		std::swap(a[ux][uy], a[vx][vy]);
	}
}

int main() {
	// freopen("1.in", "r", stdin);
	
	read(T);
	while (T--) {
		ans = -1;
		for (int i = 0; i < 5; i++)
			scanf("%s", str[i]);
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
				switch (str[i][j]) {
					case '1':
						a[i][j] = 1;
						break;
					case '0':
						a[i][j] = 0;
						break;
					case '*':
						a[i][j] = -1;
						sx = i;
						sy = j;
						break;
				}
		if (!calc())
			ans = 0;
		for (int i = 1; i <= 16 && !~ans; i++) {
			// printf("dep = %d\n", i);
			dep = i;
			dfs(0, sx, sy);
		}
		print(ans, '\n');
	}

	return 0;
}