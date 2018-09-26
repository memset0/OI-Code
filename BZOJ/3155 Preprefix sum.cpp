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

char readc() {
    char c = getchar();
    while (c != 'Q' && c != 'M') c = getchar();
    return c;
}

const int maxn = 100010;

int n, m, l, r, d, k, x;
int a[maxn];
ll s[maxn], ss[maxn];

ll sum[maxn << 2], tag1[maxn << 2], tag2[maxn << 2];

void pushup(ll val1, ll val2, int l, int r, int u) {
    sum[u] += val1 * (r - l + 1);
    sum[u] += val2 * (r - l) * (r - l + 1) / 2;
    tag1[u] += val1, tag2[u] += val2;
}

void pushdown(int l, int r, int u) {
    if (tag1[u] || tag2[u]) {
        if (l != r) {
            int mid = (l + r) >> 1;
            pushup(tag1[u], tag2[u], l, mid, u << 1);
            pushup(tag1[u] + tag2[u] * (mid - l + 1), tag2[u], mid + 1, r, u << 1 | 1);
        }
        tag1[u] = tag2[u] = 0;
    }
}

void modify(int ql, int qr, ll val1, ll val2, int l = 1, int r = n, int u = 1) {
//	printf("modify %d %d %d %d %d %d %d\n", ql, qr, val1, val2, l, r, u);
    pushdown(l, r, u);
    if (ql == l && qr == r) {
        pushup(val1, val2, l, r, u);
        return;
    }
    int mid = (l + r) >> 1;
    if (qr <= mid) modify(ql, qr, val1, val2, l, mid, u << 1);
    else if (ql > mid) modify(ql, qr, val1, val2, mid + 1, r, u << 1 | 1);
    else {
        modify(ql, mid, val1, val2, l, mid, u << 1);
        modify(mid + 1, qr, val1 + val2 * (mid - ql + 1), val2, mid + 1, r, u << 1 | 1);
    }
    sum[u] = sum[u << 1] + sum[u << 1 | 1];
}

ll query(int k, int l = 1, int r = n, int u = 1) {
    pushdown(l, r, u);
    if (l == r) return sum[u];
    int mid = (l + r) >> 1;
    if (k <= mid) return query(k, l, mid, u << 1);
    else return query(k, mid + 1, r, u << 1 | 1);
}

int main() {
	
    read(n), read(m);
    for (int i = 1; i <= n; i++) {
        read(a[i]);
        s[i] = s[i - 1] + a[i];
        ss[i] = ss[i - 1] + s[i];
    }
    
    for (int i = 1; i <= m; i++) {
        if (readc() == 'M') {
            read(k), read(x);
            modify(k, n, x - a[k], x - a[k]);
            a[k] = x;
        } else {
			read(k);
            print(query(k) + ss[k]);
        }
    }
    
    return 0;
}
