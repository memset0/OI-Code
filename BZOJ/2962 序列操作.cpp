// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long
using namespace std;
  
inline char getc() {
    static const int IN_LEN = 1000000;
    static char buf[IN_LEN], *s, *t;
    return (s == t ? t = (s = buf) + fread(buf, 1, IN_LEN, stdin), (s == t ? -1 : *s++) : *s++);
}
inline int read() {
    static int x = 0;
    static bool iosig;
    static char c;
    for (iosig = false, c = getc(); !isdigit(c); c = getc()) {
        if (c == '-') iosig = true;
        if (c == -1) return 0;
    }
    for (x = 0; isdigit(c); c = getc()) x = ((x + (x << 2)) << 1) + (c ^ '0');
    if (iosig) x = -x;
    return x;
}
inline int readc() {
    char c = getc();
    while (c != 'I' && c != 'R' && c != 'Q') c = getc();
    return c == 'I' ? 1 : c == 'R' ? 2 : 3; 
}
  
void print(int x) {
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}
   
const int maxn = 50010;
const ll mod = 19940417;
   
/* TODO (#1#): 开 long long */
/* TODO (#2#): 检查是否有取膜 */
   
int n, m, u, v, l, r, k, w, opt;
ll a[maxn];
ll C[maxn][21];
 
struct status {
    ll f[21];
};
   
struct node {
    int l, r, mid;
    ll tag1;
    ll len;
    bool tag2;
    status x;
} p[maxn << 2];
   
inline status merge(const status &a, const status &b) {
    status c;
    memset(c.f, 0, sizeof(c.f));
    c.f[0] = 1;
//  puts("=== merge ===");
//  a.print(), b.print();
    for (int i = 1; i <= 20; ++i) {
        for (int j = 0; j <= i; ++j)
            (c.f[i] += a.f[j] * b.f[i - j]) %= mod;
    }
    for (int i = 1; i <= 20; i++)
        c.f[i] %= mod;
//  c.print();
    return c;
}
 
inline void merge(const status &a, const status &b, status &c) {
    memset(c.f, 0, sizeof(c.f));
    c.f[0] = 1;
    for (int i = 1; i <= 20; ++i) {
        for (int j = 0; j <= i; ++j)
            c.f[i] = (a.f[j] * b.f[i - j] + c.f[i]) % mod;
        c.f[i] %= mod;
    }
}
 
inline void pushup_modify(int u, ll w) {
//  if (p[u].rev) w = mod - w;
//  printf("pushup modify %d %lld\n", u, w);
    status c = p[u].x;
    memset(p[u].x.f, 0, sizeof(p[u].x.f));
    p[u].x.f[0] = 1;
    ll tim[21] = {1};
    for (int i = 1; i <= 20; ++i)
        tim[i] = tim[i - 1] * w % mod;
    for (int i = 1; i <= 20; ++i) {
        for (int j = 0; j <= i; ++j)
            p[u].x.f[i] = (c.f[i - j] * C[p[u].len - (i - j)][j] % mod * tim[j] % mod + p[u].x.f[i]) % mod;
        p[u].x.f[i] %= mod;
    }
    (p[u].tag1 += p[u].tag2 ? mod - w : w) %= mod;
}
   
inline void pushup_reverse(int u) {
    p[u].tag2 ^= 1;
    for (int i = 1; i <= 20; i += 2)
        p[u].x.f[i] = mod - p[u].x.f[i];
}
   
inline void pushdown(int u) {
    if (p[u].l != p[u].r) {
        if (p[u].tag1) {
//          printf("pushdown1 %d(%d %d) %d\n", u, p[u].l, p[u].r, p[u].tag1);
            pushup_modify(u << 1, p[u].tag1);
            pushup_modify(u << 1 | 1, p[u].tag1);
            p[u].tag1 = 0;
        }
        if (p[u].tag2) {
//          printf("pushdown2 %d(%d %d) %d\n", u, p[u].l, p[u].r, p[u].tag2);
            pushup_reverse(u << 1);
            pushup_reverse(u << 1 | 1);
            p[u].tag2 = 0;
        }
    }
}
   
void build(int u, int l, int r) {
    p[u].l = l, p[u].r = r;
    p[u].mid = (l + r) >> 1;
    p[u].len = r - l + 1;
    if (l == r) {
        p[u].x.f[0] = 1;
        p[u].x.f[1] = a[l] % mod;
        return;
    }
    build(u << 1, l, p[u].mid);
    build(u << 1 | 1, p[u].mid + 1, r);
    merge(p[u << 1].x, p[u << 1 | 1].x, p[u].x);
}
   
void reverse(int u, int l, int r) {
    pushdown(u);
    if (p[u].l == l && p[u].r == r) {
        pushup_reverse(u);
        return;
    }
    if (r <= p[u].mid) reverse(u << 1, l, r);
    else if (l > p[u].mid) reverse(u << 1 | 1, l, r);
    else {
        reverse(u << 1, l, p[u].mid);
        reverse(u << 1 | 1, p[u].mid + 1, r);
    }
    merge(p[u << 1].x, p[u << 1 | 1].x, p[u].x);
}
   
void modify(int u, int l, int r, int c) {
    pushdown(u);
    if (p[u].l == l && p[u].r == r) {
        pushup_modify(u, c);
        return;
    }
    if (r <= p[u].mid) modify(u << 1, l, r, c);
    else if (l > p[u].mid) modify(u << 1 | 1, l, r, c);
    else {
        modify(u << 1, l, p[u].mid, c);
        modify(u << 1 | 1, p[u].mid + 1, r, c);
    }
    merge(p[u << 1].x, p[u << 1 | 1].x, p[u].x);
}
   
status query(int u, int l, int r) {
    pushdown(u);
//  printf("query %d %d %d\n", u, l, r);
//  p[u].x.print();
    if (p[u].l == l && p[u].r == r)
        return p[u].x;
    if (r <= p[u].mid) return query(u << 1, l, r);
    else if(l > p[u].mid) return query(u << 1 | 1, l, r);
    else return merge(query(u << 1, l, p[u].mid),
        query(u << 1 | 1, p[u].mid + 1, r));
}

int main() {
//  freopen("C:\\Users\\surface\\Desktop\\Temp\\data\\data\\7.in", "r", stdin);
//  freopen("C:\\Users\\surface\\Desktop\\Temp\\data\\data\\7.ans", "w", stdout);
   
    n = read(), m = read();
    for (int i = 1; i <= n; ++i) 
        a[i] = read() % mod;

    build(1, 1, n);
       
    for (int i = 0; i <= n; ++i)
        C[i][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= 20; ++j)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
    }
       
    for (int i = 1; i <= m; ++i) {
        opt = readc();
//      printf(">>> %d\n", opt);
        if (opt == 1) {
            l = read(), r = read(), w = (read() + mod) % mod;
            modify(1, l, r, w);
        } else if (opt == 2) {
            l = read(), r = read();
            reverse(1, l, r);
        } else {
            l = read(), r = read(), w = read();
            print((query(1, l, r).f[w] + mod) % mod);
            putchar('\n');
        }
//      for (int i = 1; i <= n; ++i)
//          query(1, i, i).print();
    }
   
    return 0;
}
