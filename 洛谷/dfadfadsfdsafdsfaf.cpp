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

int reado() {
	register char c = getc();
	register int ret = 0;
	while (ch = getc(), !isupper(ch));
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

inline void push(int x, int u) {
	if (end[u]) {
		++cnt;
		val[cnt] = x;
		nxt[hed[u]][1] = cnt;
		nxt[cnt][0] = hed[u];
		hed[u] = cnt;
	} else {
		++cnt;
		val[cnt] = x;
		hed[u] = end[u] = cnt;
	}
}

inline void pop(int u) {
	if (!end[hed[u]]) {
		hed[u] = end[u] = 0;
	} else {
		flag[nxt[hed[u]][0]] ^= flag[hed[u]];
		nxt[nxt[hed[u]][flag[hed[u]]]][flag[nxt[hed[u]]][flag[hed[u]]] ^ 1] = 0;
		hed[u] = nxt[hed[u]][flag];
	}
}

bool solve(int opt) {
	if (opt == 1) {
		read(x), read(u);
		push(x, u);
	} else if (opt == 2) {
		read(u);
		if (!end[u])
			return false;
		pop(u);
	} else if (opt == 3) {
		read(u);
		if (!end[0] || !end[1])
			return false;
		x = val[hed[0]], y = val[hed[1]];
		pop(0), pop(1);
		push(x + y, u);
	} else if (opt == 4) {
		read(u);
		if (!end[0] || !end[1])
			return false;
		x = val[hed[0]], y = val[hed[1]];
		pop(0), pop(1);
		push(abs(x - y), u);
	} else if (opt == 5) {
		read(u);
		hed[u] = end[u] = 0;
	} else if (opt == 6) {
		read(u), read(v);
		flag[hed[u]] ^= 1;
		flag[end[v]] ^= 1;
		nxt[hed[u]][flag[hed[u]] ^ 1] = end[v];
		nxt[hed[v]][flag[hed[v]] ^ 1] = hed[u];
		hed[u] = end[v];
		hed[v] = end[v] = 0;
	} else if (opt == 7) {
		
	} else {
		// END
		end_prog = 1;
	}
	return true;
}

int main() {
	
	while (!end_prog) {
		reado(opt);
		if (solve(opt)) puts("SUCCESS");
		else puts("UNSUCCESS");
	}

	return 0;
}
