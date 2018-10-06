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

const int maxn = 1000010;

int u, v, opt, cnt, flag, end_prog;
int hed[2], nxt[maxn][2];
ll x, y, val[maxn];

int reado() {
	register char ch = getc();
	register int ret = 0;
	while (!isupper(ch))
		ch = getc();
	if (ch == 'P') {
		ch = getc();
		if (ch == 'U') ret = 1;
		else ret = 2;
	} else if (ch == 'A') {
		ret = 3;
	} else if (ch == 'S') {
		ch = getc();
		if (ch == 'U') ret = 4;
		else ret = 7;
	} else if (ch == 'D') {
		ret = 5;
	} else if (ch == 'M') {
		ret = 6;
	} else if (ch == 'E') {
		ret = 8;
	}
	while (isupper(ch))
		ch = getc();
	return ret;
}

void push(ll x, int u) {
	++cnt;
	if (hed[u] == 1) {
		hed[u] = cnt;
	}
	val[cnt] = x;
	nxt[cnt][u] = nxt[1][u];
	nxt[cnt][u ^ 1] = 1;
	nxt[1][u ^ 1] = cnt;
}

void pop(int u) {
	printf("%d %d %d\n", u, nxt[1][u], nxt[nxt[1][u]][u]);
	int top = nxt[1][u];
	nxt[nxt[top][u]][u ^ 1] = 1;
	nxt[1][u] = nxt[top][u];
	if (!nxt[1][u]) {
		hed[u] = 1;
	}
}

bool solve(int opt) {
	printf("=== solve %d ===\n", opt);
	if (opt == 1) {
		read(u), read(x);
		u ^= flag;
		push(x, u);
	} else if (opt == 2) {
		read(u);
		u ^= flag;
		if (hed[u] == 1)
			return false;
		pop(u);
	} else if (opt == 3) {
		read(u);
		u ^= flag;
		if (hed[0] == 1 || hed[1] == 1)
			return false;
		x = val[nxt[1][0]], y = val[nxt[1][1]];
		pop(0), pop(1);
		push(x + y, u);
	} else if (opt == 4) {
		read(u);
		u ^= flag;
		if (hed[0] == 1 || hed[1] == 1)
			return false;
		x = val[nxt[1][0]], y = val[nxt[1][1]];
		pop(0), pop(1);
		push(abs(x - y), u);
	} else if (opt == 5) {
		read(u);
		u ^= flag;
		nxt[1][u] = 0;
		hed[u] = 1;
	} else if (opt == 6) {
		read(u), read(v);
		u ^= flag, v ^= flag;
		if (hed[v] == 1) {
			printf("skipped\n");
			return true;
		}
		if (hed[u] == 1) {
			printf("easy change\n");
			hed[u] = nxt[1][v];
			nxt[1][v] = 0;
			nxt[1][u] = hed[v];
			hed[v] = 1;
			return true;
		}
//		puts("!!!!!!!!");
		int topu = nxt[1][u], topv = nxt[1][v];
		nxt[topv][v] = topu;
		nxt[topu][u] = topv;
		nxt[1][u] = 0;
		nxt[1][v] = hed[u];
		hed[u] = 1;
	} else if (opt == 7) {
		// SWAP
		flag ^= 1;
	} else {
		// END
		end_prog = 1;
	}
	return true;
}

void printout(int u) {
	printf("print out %d\n", u);
	if (hed[u] == 1) {
		puts("NONE");
		return;
	}
	while (nxt[1][u]) {
		print(val[nxt[1][u]]);
		printf("[%d %d]\n", nxt[1][u], hed[u]);
		pop(u);
	}
	putc('\n');
}

int main() {
	
	cnt = 1, val[cnt] = -1;
	hed[0] = hed[1] = 1;
	while (!end_prog) {
		opt = reado();
		printf("%d %d %d %d %d %d %d %d\n", hed[0], hed[1], nxt[hed[0]][0], nxt[hed[1]][0], nxt[hed[0]][1], nxt[hed[1]][1], nxt[1][0], nxt[1][1]);
		if (solve(opt)) puts("SUCCESS");
		else puts("UNSUCCESS");
	}
	printf("%d %d %d %d %d %d %d %d\n", hed[0], hed[1], nxt[hed[0]][0], nxt[hed[1]][0], nxt[hed[0]][1], nxt[hed[1]][1], nxt[1][0], nxt[1][1]);
	printout(flag);
	printout(flag ^ 1);

	return 0;
}

/*

PUSH 1 1
MOVE 0 1
END

*/
