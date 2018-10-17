// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r) for (int i = l; i <= r; i++)
#define getc(x) getchar(x)
#define putc(x) putchar(x)
 
#define int long long
 
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
 
const int maxn = 200010;
const int mod = 998244353;
 
int n, m, u, v;
int a[maxn];
ll sum, now, ans, mul = 1;
 
struct node {
    int l, r, mid;
    ll sum;
} p[maxn << 2];
 
void build(int u, int l, int r) {
    p[u].l = l, p[u].r = r, p[u].mid = (l + r) >> 1;
    if (l == r) {
        p[u].sum = a[l];
        return;
    }
    build(u << 1, l, p[u].mid);
    build(u << 1 | 1, p[u].mid + 1, r);
    p[u].sum = p[u << 1].sum + p[u << 1 | 1].sum;
}
 
void modify(int u, int k, ll v) {
    p[u].sum += v;
    if (p[u].l == p[u].r)
        return;
    modify(k <= p[u].mid ? u << 1 : u << 1 | 1, k, v);
}
 
int query(int u, ll sum) {
    if (p[u].l == p[u].r)
        return p[u].l;
    if (sum <= p[u << 1].sum) return query(u << 1, sum);
    else return query(u << 1 | 1, sum - p[u << 1].sum);
}
 
signed main() {
//  freopen("station.in", "r", stdin);
//  freopen("station.out", "w", stdout);
//  freopen("3.txt", "r", stdin);
//  freopen("1.txt", "w", stdout);
     
    read(n), read(m);
    for (int i = 1; i <= n; i++) {
        read(a[i]);
        sum += a[i];
    }
    build(1, 1, n);
    for (int i = 1; i <= m; i++) {
        read(u), read(v);
        sum += v;
        modify(1, u, v);
        mul = mul * 19260817 % mod;
        now = query(1, (sum + 1) >> 1);
//      printf("%d\n", now);
        ans = (ans + mul * now) % mod;
    }
    print(ans, '\n');
 
    return 0;
}
