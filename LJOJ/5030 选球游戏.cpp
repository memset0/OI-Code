#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")

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
 
void print(int x) {
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}
  
const int maxn = 50010;
const ll mod = 1000000007;
  
/* TODO (#1#): 开 long long */
/* TODO (#2#): 检查是否有取膜 */
  
int n, m, u, v, l, r, k, opt;
int w;
int a[maxn];
ll C[maxn][11];

struct status {
    ll f[11];
};
  
struct node {
    int l, r, mid;
    ll tag1;
	int len;
    bool tag2;
    status x;
} p[maxn << 2];
  
inline status merge(const status &a, const status &b) {
    status c;
    c.f[0] = 1, c.f[1] = c.f[2] = 0;
    c.f[3] = c.f[4] = c.f[5] = c.f[6] = 0;
    c.f[7] = c.f[8] = c.f[9] = c.f[10] = 0;
//  puts("=== merge ===");
//  a.print(), b.print();
    for (int i = 1; i <= 10; ++i) {
        for (int j = 0; j <= i; ++j)
            c.f[i] += a.f[j] * b.f[i - j]; 
    }
    for (int i = 1; i <= 10; i++)
    	c.f[i] %= mod;
//  c.print();
    return c;
}

inline void merge(const status &a, const status &b, status &c) {
    c.f[0] = 1, c.f[1] = c.f[2] = 0;
    c.f[3] = c.f[4] = c.f[5] = c.f[6] = 0;
    c.f[7] = c.f[8] = c.f[9] = c.f[10] = 0;
    for (int i = 1; i <= 10; ++i) {
        for (int j = 0; j <= i; ++j)
            c.f[i] = (a.f[j] * b.f[i - j] + c.f[i]) % mod;
    }
}

inline void pushup_modify(int u, ll w) {
//  if (p[u].rev) w = mod - w;
//  printf("pushup modify %d %lld\n", u, w);
    status c = p[u].x;
    p[u].x.f[0] = 1, p[u].x.f[1] = p[u].x.f[2] = 0;
    p[u].x.f[3] = p[u].x.f[4] = p[u].x.f[5] = p[u].x.f[6] = 0;
    p[u].x.f[7] = p[u].x.f[8] = p[u].x.f[9] = p[u].x.f[10] = 0;
    ll tim[11] = {1};
    for (int i = 1; i <= 10; ++i)
        tim[i] = tim[i - 1] * w % mod;
    for (int i = 1; i <= 10; ++i) {
        for (int j = 0; j <= i; ++j)
            p[u].x.f[i] = (c.f[i - j] * C[p[u].len - (i - j)][j] % mod * tim[j] % mod + p[u].x.f[i]) % mod;
    }
    (p[u].tag1 += p[u].tag2 ? mod - w : w) %= mod;
}
  
inline void pushup_reverse(int u) {
    p[u].tag2 ^= 1;
    for (int i = 1; i <= 10; i += 2)
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
        p[u].x.f[1] = a[l];
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
//  freopen("data.txt", "r", stdin);
//  freopen("out1.txt", "w", stdout);
  
    n = read(), m = read();
    for (int i = 1; i <= n; ++i) 
        a[i] = read();
          
    build(1, 1, n);
      
    for (int i = 0; i <= n; ++i)
        C[i][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= 10; ++j)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
    }
      
    for (int i = 1; i <= m; ++i) {
        opt = read();
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
