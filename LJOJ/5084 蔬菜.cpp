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

const int maxn = 210, maxm = 100010;

int n, m, p, tn, pa, pb, pc, pd, qa, qb, qc, qd, sqn, sqm;
int now;
int bln[maxn], blm[maxn], a[maxn][maxn], b[maxn * maxn], cnt[maxn * maxn];
int ans[maxm];

struct query {
	int x1, y1, x2, y2, i;
} q[maxm];

inline bool operator < (const query &a, const query &b) {
	if (bln[a.x1] ^ bln[b.x1]) return a.x1 < b.x1;
	if (blm[a.y1] ^ blm[b.y1]) return a.y1 < b.y1;
	if (bln[a.x2] ^ bln[b.x2]) return a.x2 < b.x2;
	if (blm[a.y2] ^ blm[b.y2]) return a.y2 < b.y2;
	return a.x1 < b.x1;
}

void add(int ua, int ub, int uc, int ud) {
//	printf("add %d %d %d %d\n", ua, ub, uc, ud);
	for (int i = ua; i <= uc; i++)
		for (int j = ub; j <= ud; j++) {
			now += 2 * cnt[a[i][j]] + 1;
			++cnt[a[i][j]];
		}
//	printf("now = %d\n", now); 
}

void del(int ua, int ub, int uc, int ud) {
//	printf("del %d %d %d %d\n", ua, ub, uc, ud); 
	for (int i = ua; i <= uc; i++)
		for (int j = ub; j <= ud; j++) {
			now -= 2 * cnt[a[i][j]] - 1;
			--cnt[a[i][j]];
		}
//	printf("now = %d\n", now);
}

int main() {
//	freopen("vegetable.in", "r", stdin);
//	freopen("vegetable.out", "w", stdout);
	// freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);

	read(n), read(m), read(p);
	sqn = sqrt(n), sqm = sqrt(m);
//	printf(">>> %d %d %d : %d %d\n", n, m, p, sqn, sqm);
	for (int i = 1; i <= n; i++)
		bln[i] = (i - 1) / sqn + 1;
	for (int i = 1; i <= m; i++)  
		blm[i] = (i - 1) / sqm + 1;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			read(a[i][j]);
			b[++tn] = a[i][j];
		}
	std::sort(b + 1, b + tn + 1);
	tn = std::unique(b + 1, b + tn + 1) - b - 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			a[i][j] = std::lower_bound(b + 1, b + tn + 1, a[i][j]) - b;
	// for (int i = 1; i <= n; i++) {
	// 	for (int j = 1; j <= m; j++)
	// 		print(a[i][j]);
	// 	putc('\n'); 
	// }
	
	for (int i = 1; i <= p; i++) {
		read(q[i].x1), read(q[i].y1);
		read(q[i].x2), read(q[i].y2);
		// if (q[i].x1 > q[i].x2) std::swap(q[i].x1, q[i].x2);
		// if (q[i].y1 > q[i].y2) std::swap(q[i].y1, q[i].y2);
		// printf(">>> %d %d %d %d\n", q[i].x1, q[i].y1, q[i].x2, q[i].y2);
		q[i].i = i;
	}
	std::sort(q + 1, q + p + 1);
	// std::random_shuffle(q + 1, q + p + 1);
	
	pa = q[1].x1, pb = q[1].y1, pc = q[1].x2, pd = q[1].y2;
	add(pa, pb, pc, pd), ans[q[1].i] = now;
//	printf(">>> %d : %d\n", q[1].i, now);
	for (int i = 2; i <= p; i++) {
		qa = q[i].x1, qb = q[i].y1, qc = q[i].x2, qd = q[i].y2;
		// printf("%d %d %d %d > %d %d %d %d\n", pa, pb, pc, pd, qa, qb, qc, qd);
		if (pa > qa) add(qa, pb, pa - 1, pd), pa = qa;
		if (pb > qb) add(pa, qb, pc, pb - 1), pb = qb;
		if (pc < qc) add(pc + 1, pb, qc, pd), pc = qc;
		if (pd < qd) add(pa, pd + 1, pc, qd), pd = qd;
		if (pa < qa) del(pa, pb, qa - 1, pd), pa = qa;
		if (pb < qb) del(pa, pb, pc, qb - 1), pb = qb;
		if (pc > qc) del(qc + 1, pb, pc, pd), pc = qc;
		if (pd > qd) del(pa, qd + 1, pc, pd), pd = qd;
		ans[q[i].i] = now;
		// printf(">>> %d : %d\n", q[i].i, now); 
	}
	
	for (int i = 1; i <= p; i++)
		print(ans[i], '\n');
	return 0;
}