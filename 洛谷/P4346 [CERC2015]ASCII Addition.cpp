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

int n, u, l, r;
ll lst, ans;
char s[8][1000];

bool check(int k) {
	if (k == 1) return s[2][r] && s[3][r];
	else if (k == 2) return s[5][r] && s[6][r];
	else if (k == 3) return s[2][l] && s[3][l];
	else if (k == 4) return s[5][l] && s[6][l];
	else if (k == 5) return s[1][l + 1] && s[1][r - 1];
	else if (k == 6) return s[4][l + 1] && s[4][r - 1];
	else return s[7][l + 1] && s[7][r - 1];
}

int get() {
	// printf("%d %d %d %d %d %d %d\n", check(1), check(2), check(3), check(4), check(5), check(6), check(7));
	if ( check(1) &&  check(2) && !check(3) && !check(4) && !check(5) && !check(6) && !check(7)) return 1;
	if ( check(1) && !check(2) && !check(3) &&  check(4) &&  check(5) &&  check(6) &&  check(7)) return 2;
	if ( check(1) &&  check(2) && !check(3) && !check(4) &&  check(5) &&  check(6) &&  check(7)) return 3;
	if ( check(1) &&  check(2) &&  check(3) && !check(4) && !check(5) &&  check(6) && !check(7)) return 4;
	if (!check(1) &&  check(2) &&  check(3) && !check(4) &&  check(5) &&  check(6) &&  check(7)) return 5;
	if (!check(1) &&  check(2) &&  check(3) &&  check(4) &&  check(5) &&  check(6) &&  check(7)) return 6;
	if ( check(1) &&  check(2) && !check(3) && !check(4) &&  check(5) && !check(6) && !check(7)) return 7;
	if ( check(1) &&  check(2) &&  check(3) &&  check(4) &&  check(5) &&  check(6) &&  check(7)) return 8;
	if ( check(1) &&  check(2) &&  check(3) && !check(4) &&  check(5) &&  check(6) &&  check(7)) return 9;
	if ( check(1) &&  check(2) &&  check(3) &&  check(4) &&  check(5) && !check(6) &&  check(7)) return 0;
	if (!check(1) && !check(2) && !check(3) && !check(4) && !check(5) &&  check(6) && !check(7)) return -1;
	return 10;
}

void print_num(int u, int k) {
	if (k == 1) {
		if (u == 2 || u == 3 || u == 5 || u == 6 || u == 7 || u == 8 || u == 9 || u == 0) printf("xxxxx");
		if (u == 1) printf("....x");
		if (u == 4) printf("x...x");
	} else if (k == 2 || k == 3) {
		if (u == 1 || u == 2 || u == 3 || u == 7) printf("....x");
		if (u == 4 || u == 8 || u == 9 || u == 0) printf("x...x");
		if (u == 5 || u == 6) printf("x....");
	} else if (k == 4) {
		if (u == 2 || u == 3 || u == 4 || u == 5 || u == 6 || u == 8 || u == 9) printf("xxxxx");
		if (u == 1 || u == 7) printf("....x");
		if (u == 0) printf("x...x");
	} else if (k == 5 || k == 6) {
		if (u == 1 || u == 3 || u == 7 || u == 9) printf("....x");
		if (u == 6 || u == 8 || u == 0) printf("x...x");
		if (u == 5 || u == 4) printf("....x");
		if (u == 2) printf("x....");
	} else {
		if (u == 2 || u == 3 || u == 5 || u == 6 || u == 8 || u == 9 || u == 0) printf("xxxxx");
		if (u == 1 || u == 4 || u == 7) printf("....x");
	}
}

void output(int x, int k) {
	if (x > 9) {
		output(x / 10, k);
		putc('.');
	}
	print_num(x % 10, k);
}

int main() {
	// freopen("1.in", "r", stdin);
	for (int i = 1; i <= 7; i++)
		scanf("%s", s[i] + 1);
	n = strlen(s[1] + 1);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= 7; j++)
			s[j][i] = s[j][i] == 'x' ? 1 : 0;
	// printf("%d\n", n);
	for (int i = 1; i <= (n + 1) / 6; i++) {
 		l = (i - 1) * 6 + 1, r = i * 6 - 1;
		u = get();
		// printf("%d %d %d %d\n", l, r, u, lst);
		if (u == -1) {
			ans += lst;
			lst = 0;
		} else {
			lst = lst * 10 + u;
		}
	}
	ans += lst;
	// print(ans, '\n');
	for (int i = 1; i <= 7; i++)
		output(ans, i), putc('\n');
	return 0;
}

/*
....x.xxxxx.xxxxx.x...x.xxxxx.xxxxx.xxxxx.......xxxxx.xxxxx.xxxxx
....x.....x.....x.x...x.x.....x.........x...x...x...x.x...x.x...x
....x.....x.....x.x...x.x.....x.........x...x...x...x.x...x.x...x
....x.xxxxx.xxxxx.xxxxx.xxxxx.xxxxx.....x.xxxxx.xxxxx.xxxxx.x...x
....x.x.........x.....x.....x.x...x.....x...x...x...x.....x.x...x
....x.x.........x.....x.....x.x...x.....x...x...x...x.....x.x...x
....x.xxxxx.xxxxx.....x.xxxxx.xxxxx.....x.......xxxxx.xxxxx.xxxxx
*/