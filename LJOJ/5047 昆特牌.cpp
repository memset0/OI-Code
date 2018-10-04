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

int n, w, ans = -1000000009, cnt, lim = 1, t[9], horn1, horn2;
bool abled;
typedef std::vector < int > ::iterator iterator;

struct card {
	int p, x, v;
} a[9], b[9], c[9];

struct player {
	std::vector < int > c[3];
	bool e[3];
	int calc_points() {
		int ret = 0;
		for (int i = 0; i < 3; i++)
			if (e[i]) {
				for (iterator it = c[i].begin(); it != c[i].end(); it++)
					ret += 1;
			} else {
				for (iterator it = c[i].begin(); it != c[i].end(); it++)
					ret += *it;
			}
		return ret;
	}
} p[2];

void read_card(card &a) {
	read(a.p);
	if (a.p == 1) read(a.v), read(a.x);
	else if (a.p == 2) read(a.x);
}

void print_card(const card &a) {
	printf("%d", a.p);
	if (a.p == 1) printf(" %d %d", a.v, a.x);
	else if (a.p == 2) printf(" %d", a.x);
	else if (a.p == 5) printf(" %d", a.x);
	putc('\n');
}

void init() {
	abled = 1;
	p[0].c[0].clear();
	p[0].c[1].clear();
	p[0].c[2].clear();
	p[1].c[0].clear();
	p[1].c[1].clear();
	p[1].c[2].clear();
	p[0].e[0] = p[0].e[1] = p[0].e[2] = 0;
	p[1].e[0] = p[1].e[1] = p[1].e[2] = 0;
}

void play(const card &a, int l) {
//	printf("play %d : ", l); print_card(a);
	static std::vector < int > tmp;
	if (a.p == 1) {
		p[l].c[a.x].push_back(a.v);
	} else if (a.p == 2) {
		p[l].e[a.x] = p[l ^ 1].e[a.x] = 1;
	} else if (a.p == 3) {
		p[0].e[0] = p[0].e[1] = p[0].e[2] = 0;
		p[1].e[0] = p[1].e[1] = p[1].e[2] = 0;
	} else if (a.p == 4) {
		int max = -1000000000;
		for (int i = 0; i < 6; i++) {
			if (p[i < 3 ? 0 : 1].e[i < 3 ? i : i - 3]) continue;
			std::vector < int > &now = p[i < 3 ? 0 : 1].c[i < 3 ? i : i - 3];
			for (iterator it = now.begin(); it != now.end(); it++)
				max = std::max(max, *it);
		}
		for (int i = 0; i < 6; i++) {
			if (p[i < 3 ? 0 : 1].e[i < 3 ? i : i - 3]) continue;
			tmp = p[i < 3 ? 0 : 1].c[i < 3 ? i : i - 3];
			std::vector < int > &now = p[i < 3 ? 0 : 1].c[i < 3 ? i : i - 3];
			now.clear();
			for (iterator it = tmp.begin(); it != tmp.end(); it++)
				if (*it != max)
					now.push_back(*it);
		}
	} else if (a.p == 5) {
		if (p[a.x < 3 ? l : l ^ 1].e[a.x < 3 ? a.x : a.x - 3]) {
			if (abled) {
				abled = 0;
				if (a.x == 0 && p[0].e[0] && p[0].e[1] && p[0].e[2] && p[1].e[0] && p[1].e[1] && p[1].e[2])
					abled = 1;
			}
			if (!abled) return;
		} else {
			std::vector < int > &now = p[a.x < 3 ? l : l ^ 1].c[a.x < 3 ? a.x : a.x - 3];
			tmp = p[a.x < 3 ? l : l ^ 1].c[a.x < 3 ? a.x : a.x - 3];
			now.clear();
			for (iterator it = tmp.begin(); it != tmp.end(); it++)
				now.push_back((*it) << 1);
		}
	}
}

void solve() {
	init();
	for (int p = 1; p <= n; p++)
		if (w) {
			play(b[p], 1);
			play(a[p], 0);
		} else {
			play(a[p], 0);
			play(b[p], 1);
		}
	int now = p[0].calc_points() - p[1].calc_points();
//	printf("[%d]", now);
	if (!abled) return;
	if (now > ans) {
		ans = now;
		cnt = 1;
	} else if (now == ans) {
		cnt++;
	}
}

int main() {
//	freopen("gwent.in", "r", stdin);
//	freopen("gwent.out", "w", stdout);
	
	read(w), read(n);
	for (int i = 1; i <= n; i++)
		read_card(b[i]);
	for (int i = 1; i <= n; i++)
		read_card(c[i]);
	for (int i = 1; i <= n; i++)
		t[i] = i;
	for (int i = 1; i <= n; i++)
		if (c[i].p == 5) {
			if (!horn1) horn1 = i;
			else horn2 = i;
		}
	for (int i = 1; i <= n; i++)
		lim *= i;
	for (int z = 1; z <= lim; z++) {
//		for (int i = 1; i <= n; i++)
//			print(t[i]); putc('\n');
		for (int i = 1; i <= n; i++)
			a[t[i]] = c[i];
		if (horn1 && horn2) {
			for (int i = 0; i < 6; i++)
				for (int j = 0; j < 6; j++) {
					a[t[horn1]].x = i;
					a[t[horn2]].x = j;
					solve();
				}
		} else if (horn1) {
			for (int i = 0; i < 6; i++) {
				a[t[horn1]].x = i;
				solve();
			}
		} else {
			solve();
		}
		std::next_permutation(t + 1, t + n + 1);
	}
	print(ans), print(cnt, '\n');

	return 0;
}
