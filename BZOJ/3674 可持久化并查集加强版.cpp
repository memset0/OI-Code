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
template <typename T> inline void print(T x, char c = '\n') {
	static int buf[40];
	if (x == 0) { putc('0'); putc(c); return; }
	if (x < 0) putc('-'), x = -x;
	for (buf[0] = 0; x; x /= 10) buf[++buf[0]] = x % 10 + 48;
	while (buf[0]) putc((char) buf[buf[0]--]);
	putc(c);
}

const int maxn = 200010, maxm = 200010, maxl = 6200010;

int n, m, u, v, k, i, pos, opt, lastans;

struct pair {
    int fa, siz;
    pair() {}
    pair(int a, int b)  {
        fa = a, siz = b;
    }
} x, y;

struct SEG {
    int pos;
    int root[maxm], lc[maxl], rc[maxl], val[maxl];
    bool flag;
    void build(int &u, int l, int r) {
        u = ++pos;
        if (l == r) { val[u] = flag ? l : 1; return; }
        int mid = (l + r) >> 1;
        build(lc[u], l, mid);
        build(rc[u], mid + 1, r);
    }
    int query(int u, int l, int r, int k) {
        if (l == r) return val[u];
        int mid = (l + r) >> 1;
        if (k <= mid) return query(lc[u], l, mid, k);
        else return query(rc[u], mid + 1, r, k);
    }
    void modify(int &u, int v, int l, int r, int k, int c) {
        u = ++pos, lc[u] = lc[v], rc[u] = rc[v];
        if (l == r) { val[u] = c; return; }
        int mid = (l + r) >> 1;
        if (k <= mid) modify(lc[u], lc[v], l, mid, k, c);
        else modify(rc[u], rc[v], mid + 1, r, k, c);
    }
} fa, siz;

pair find(int root1, int root2, int u) {
    int f = fa.query(root1, 1, n, u);
    if (u == f) return pair(f, siz.query(root2, 1, n, u));
    return find(root1, root2, f);
}

int main() {
    
    read(n), read(m);
    fa.flag = 1, siz.flag = 0;
    fa.build(fa.root[0], 1, n);
    siz.build(siz.root[0], 1, n);
    for (i = 1; i <= m; i++) {
        fa.root[i] = fa.root[i - 1], siz.root[i] = siz.root[i - 1];
        read(opt);
        if (opt == 1) {
        	read(u), read(v);
        	u ^= lastans;
        	v ^= lastans;
            x = find(fa.root[i], siz.root[i], u);
            y = find(fa.root[i], siz.root[i], v);
            if (x.fa != y.fa) {
                if (x.siz > y.siz) std::swap(x, y);
                fa.modify(fa.root[i], fa.root[i - 1], 1, n, x.fa, y.fa);
                siz.modify(siz.root[i], siz.root[i - 1], 1, n, y.fa, x.siz + y.siz);
            } 
        } else if (opt == 2) {
            read(k);
            k ^= lastans;
            fa.root[i] = fa.root[k];
            siz.root[i] = siz.root[k];
        } else {
        	read(u), read(v);
        	u ^= lastans;
        	v ^= lastans;
            x = find(fa.root[i], siz.root[i], u);
            y = find(fa.root[i], siz.root[i], v);
//			printf("%d %d : %d %d : %d %d\n", u, v, x.fa, y.fa, x.siz, y.siz);
            if (x.fa == y.fa) print(lastans = 1);
            else print(lastans = 0);
        }
    }

    return 0;
}
