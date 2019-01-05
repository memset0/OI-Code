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

const int maxn = 6000010;

int x, y, opt, cnt, finish_game;
int pre[maxn], nxt[maxn], hed[2];
ll k, val[maxn];

inline void link(int u, int v) {
	nxt[u] = v;
	pre[v] = u;
}

inline void simple_push(int u, int v, ll w) {
	val[++cnt] = w;
	link(u, cnt);
	link(cnt, v);
}

inline void push(int x, ll k) {
	if (x == 0) simple_push(pre[2], 2, k);
	else simple_push(2, nxt[2], k);
}

inline ll pop(int u) {
	link(pre[u], nxt[u]);
	return val[u];
}

void printout(int u) {
	if (u == 0) {
		if (pre[2] == 0) { 
			printf("NONE\n");
			return;
		}
		for (int i = pre[2]; i != 0; i = pre[i])
			print(val[i]);
		putc('\n');
	} else {
		if (nxt[2] == 1) {
			printf("NONE\n");
			return;
		}
		for (int i = nxt[2]; i != 1; i = nxt[i])
			print(val[i]);
		putc('\n');
	}
}

int read_opt() {
	char c1, c2;
	readc(c1), readc(c2);
	if (c1 == 'P')
		return c2 == 'U' ? 1 : 2;
	if (c1 == 'A')
		return 3;
	if (c1 == 'S') {
		if (c2 == 'U')
			return 4;
		readc(c2), readc(c2);
		return 7;
	}
	if (c1 == 'D')
		return 5;
	if (c1 == 'M')
		return 6;
	if (c1 == 'E')
		return 8;
	return 0;
}

bool solve(int opt) {
	if (opt == 1) {
		read(x), read(k);
		x = hed[x];
		push(x, k);
	} else if (opt == 2) {
		read(x);
		x = hed[x];
		if (x == 0) {
			if (pre[2] == 0) return false;
			pop(pre[2]);
		} else {
			if (nxt[2] == 1) return false;
				pop(nxt[2]);
		}
	} else if (opt == 3) {
		read(x);
		x = hed[x];
		if (pre[2] == 0 || nxt[2] == 1) return false;
		push(x, pop(pre[2]) + pop(nxt[2]));
	} else if (opt == 4) {
		read(x);
		x = hed[x];
		if (pre[2] == 0 || nxt[2] == 1)	return false;
		push(x, std::abs(pop(pre[2]) - pop(nxt[2])));
	} else if (opt == 5) {
		read(x);
		x = hed[x];
		if (x == 0) link(0, 2);
		else link(2, 1);
	} else if (opt == 6) {
		read(x), read(y);
		x = hed[x], y = hed[y];
		link(pre[2], nxt[2]);
		if (x == 0) {
			link(pre[1], 2);
			link(2, 1);
		} else {
			link(2, nxt[0]);
			link(0, 2);
		}
	} else if (opt == 7) {
		std::swap(hed[0], hed[1]);
	} else if (opt == 8) {
		finish_game = 1;
	}
	return true;
}

int main() {
//	freopen("C:\\Users\\surface\\Desktop\\Temp\\Day2\\problem\\data\\Portal\\Portal2.in", "r", stdin);
//	freopen("C:\\Users\\surface\\Desktop\\Temp\\Day2\\problem\\data\\Portal\\Portal2.out", "w", stdout);
	cnt = 2;
	link(0, 2), link(2, 1); 
	hed[0] = 0, hed[1] = 1;
	while (!finish_game) {
		opt = read_opt();
		if (solve(opt)) puts("SUCCESS");
		else puts("UNSUCCESS");
	}
	printout(!hed[0] ? 0 : 1);
	printout(!hed[0] ? 1 : 0);
	return 0;
}