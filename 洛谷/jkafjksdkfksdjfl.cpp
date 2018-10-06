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


const int maxN = 6000010;

int x, y, cnt, pre[maxN], nxt[maxN], hed[2];
ll k, val[maxN];

inline void success() { puts("SUCCESS"); }
inline void unsuccess() { puts("UNSUCCESS"); }

inline void connect(int u, int v) {
	nxt[u] = v;
	pre[v] = u;
}
inline void push(int u, int v, ll w) { val[++cnt] = w; connect(u, cnt), connect(cnt, v); }

void push(int x, ll k) {
	switch (x) {
		case 0:
			push(pre[2], 2, k);
			break;
		case 1:
			push(2, nxt[2], k);
			break;
	}
	success();
}
inline ll pop(int u) {
	connect(pre[u], nxt[u]);
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

int main() {
	freopen("C:\\Users\\surface\\Desktop\\Temp\\Day2\\problem\\data\\Portal\\Portal3.in", "r", stdin);
	freopen("C:\\Users\\surface\\Desktop\\Temp\\Day2\\problem\\data\\Portal\\Portal3.out", "w", stdout);
	connect(0, 2), connect(2, 1); cnt = 2;
	hed[0] = 0, hed[1] = 1;
	while (true) {
		char opt1, opt2;
		readc(opt1), readc(opt2);
		if (opt1 == 'P') {
			if (opt2 == 'U') { // Push:
				read(x), read(k);
				x = hed[x];
				push(x, k);
			} else { // Pop:
				read(x);
				x = hed[x];
				switch (x) {
					case 0:
						if (pre[2] == 0) 
							unsuccess();
						else {
							pop(pre[2]);
							success();
						}
						break;
					case 1:
						if (nxt[2] == 1)
							unsuccess();
						else {
							pop(nxt[2]);
							success();
						}
						break;
				}
			}
		} else if (opt1 == 'A') { // Add
			read(x);
			x = hed[x];
			if (pre[2] == 0 || nxt[2] == 1) { unsuccess(); } else { push(x, pop(pre[2]) + pop(nxt[2])); }
		} else if (opt1 == 'S') {
			if (opt2 == 'U') { // Sub
				read(x);
				x = hed[x];
				if (pre[2] == 0 || nxt[2] == 1) { unsuccess(); } else { push(x, std::abs(pop(pre[2]) - pop(nxt[2]))); }
			} else { // Swap
				char opt;
				readc(opt), readc(opt);
				std::swap(hed[0], hed[1]);
				success();
			}
		} else if (opt1 == 'D') { // Del
			read(x);
			x = hed[x];
			switch (x) {
				case 0:
					connect(0, 2);
					break;
				case 1:
					connect(2, 1);
					break;
			}
			success();
		} else if (opt1 == 'M') { // Move
			read(x), read(y);
			x = hed[x], y = hed[y];
			connect(pre[2], nxt[2]);
			switch (x) {
				case 0:
					connect(pre[1], 2);
					connect(2, 1);
					break;
				case 1:
					connect(2, nxt[0]);
					connect(0, 2);
					break;  
			}
			success();
		} else { // End:
			success();
			printout(!hed[0] ? 0 : 1);
			printout(!hed[0] ? 1 : 0);
			break;
		}
	}
	return 0;
}
