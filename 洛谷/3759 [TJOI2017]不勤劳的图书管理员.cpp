%:pragma GCC optimize(3)
%:pragma GCC optimize("Ofast")
%:pragma GCC optimize("inline")
%:pragma GCC optimize("-fgcse")
%:pragma GCC optimize("-fgcse-lm")
%:pragma GCC optimize("-fipa-sra")
%:pragma GCC optimize("-ftree-pre")
%:pragma GCC optimize("-ftree-vrp")
%:pragma GCC optimize("-fpeephole2")
%:pragma GCC optimize("-ffast-math")
%:pragma GCC optimize("-fsched-spec")
%:pragma GCC optimize("unroll-loops")
%:pragma GCC optimize("-falign-jumps")
%:pragma GCC optimize("-falign-loops")
%:pragma GCC optimize("-falign-labels")
%:pragma GCC optimize("-fdevirtualize")
%:pragma GCC optimize("-fcaller-saves")
%:pragma GCC optimize("-fcrossjumping")
%:pragma GCC optimize("-fthread-jumps")
%:pragma GCC optimize("-funroll-loops")
%:pragma GCC optimize("-fwhole-program")
%:pragma GCC optimize("-freorder-blocks")
%:pragma GCC optimize("-fschedule-insns")
%:pragma GCC optimize("inline-functions")
%:pragma GCC optimize("-ftree-tail-merge")
%:pragma GCC optimize("-fschedule-insns2")
%:pragma GCC optimize("-fstrict-aliasing")
%:pragma GCC optimize("-fstrict-overflow")
%:pragma GCC optimize("-falign-functions")
%:pragma GCC optimize("-fcse-skip-blocks")
%:pragma GCC optimize("-fcse-follow-jumps")
%:pragma GCC optimize("-fsched-interblock")
%:pragma GCC optimize("-fpartial-inlining")
%:pragma GCC optimize("no-stack-protector")
%:pragma GCC optimize("-freorder-functions")
%:pragma GCC optimize("-findirect-inlining")
%:pragma GCC optimize("-fhoist-adjacent-loads")
%:pragma GCC optimize("-frerun-cse-after-loop")
%:pragma GCC optimize("inline-small-functions")
%:pragma GCC optimize("-finline-small-functions")
%:pragma GCC optimize("-ftree-switch-conversion")
%:pragma GCC optimize("-foptimize-sibling-calls")
%:pragma GCC optimize("-fexpensive-optimizations")
%:pragma GCC optimize("-funsafe-loop-optimizations")
%:pragma GCC optimize("inline-functions-called-once")
%:pragma GCC optimize("-fdelete-null-pointer-checks")

// =================================
//   author: memset0
//   date: 2018.12.03 22:51:47
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
namespace ringo {
typedef long long ll;

namespace fast_IO {
    inline char read() {
//        return getchar();
        static const int IN_LEN = 1000000;
        static char buf[IN_LEN], *s, *t;
        if (s == t) {
            t = (s = buf) + fread(buf, 1, IN_LEN, stdin);
            if (s == t) return -1;
        }
        return *s++;
    }
    template<class T>
    inline void read(T &x) {
        static bool iosig;
        static char c;
        for (iosig = false, c = read(); !isdigit(c); c = read()) {
            if (c == '-') iosig = true;
            if (c == -1) return;
        }
        for (x = 0; isdigit(c); c = read())
            x = ((x + (x << 2)) << 1) + (c ^ '0');
        if (iosig) x = -x;
    }
    const int OUT_LEN = 10000000;
    char obuf[OUT_LEN], *ooh = obuf;
    inline void print(char c) {
        if (ooh == obuf + OUT_LEN) fwrite(obuf, 1, OUT_LEN, stdout), ooh = obuf;
        *ooh++ = c;
    }
    template<class T>
    inline void print(T x) {
        static int buf[30], cnt;
        if (x == 0) {
            print('0');
        }
        else {
            if (x < 0) print('-'), x = -x;
            for (cnt = 0; x; x /= 10) buf[++cnt] = x % 10 + 48;
            while (cnt) print((char)buf[cnt--]);
        }
    }
    inline void flush() {
        fwrite(obuf, 1, ooh - obuf, stdout);
    }
}
using namespace fast_IO;

const int N = 5e4 + 10, M = N * 22, mod = 1e9 + 7;
int n, m, l, r, x, y, z, ans, cnt, top;
int key[N], val[N], stk[M], tkey[N], tval[N];

inline void sumd(int &a, int b) { a += b; if (a >= mod) a -= mod; }
inline void decd(int &a, int b) { a -= b; if (a < 0) a += mod; }

struct pair {
    int key, val;
    inline bool operator < (const pair &other) const {
        return key < other.key;
    }
} srt[N];

struct treap_node {
    int key, val, sum, rnd, siz, ch[2];
} e[M];

struct segment_node {
    int l, r, mid, rt, sum;
} p[N << 2];

inline int new_node() { return top ? stk[top--] : ++cnt; }
inline int new_node(int key, int val) {
    int u;
    if (top) u = stk[top--], e[u].ch[0] = e[u].ch[1] = 0;
    else u = ++cnt, e[u].rnd = rand();
    e[u].key = key, e[u].val = e[u].sum = val;
    e[u].siz = 1;
    return u;
}

inline void update(int u) {
    e[u].siz = e[e[u].ch[0]].siz + e[e[u].ch[1]].siz + 1;
    e[u].sum = e[u].val + e[e[u].ch[0]].sum + e[e[u].ch[1]].sum;
    if (e[u].sum >= mod) e[u].sum -= mod;
    if (e[u].sum >= mod) e[u].sum -= mod;
}

int merge(int x, int y) {
    if (!x || !y) return x | y;
    if (e[x].rnd < e[y].rnd) {
        e[x].ch[1] = merge(e[x].ch[1], y);
        return update(x), x;
    } else {
        e[y].ch[0] = merge(x, e[y].ch[0]);
        return update(y), y;
    }
}

void split(int u, int k, int &x, int &y) {
    if (!u) { x = y = 0; return; }
    if (k < e[u].key) {
        y = u;
        split(e[y].ch[0], k, x, e[y].ch[0]);
    } else {
        x = u;
        split(e[x].ch[1], k, e[x].ch[1], y);
    }
    update(u);
}

void dfs(int u) {
    if (e[u].ch[0]) dfs(e[u].ch[0]);
    printf("%d ", e[u].key);
    if (e[u].ch[1]) dfs(e[u].ch[1]);
}

inline void erase(int &rt, int key) {
    split(rt, key - 1, x, y), split(y, key, y, z);
    stk[++top] = y;
    rt = merge(x, merge(merge(e[y].ch[0], e[y].ch[1]), z));
}

inline void insert(int &rt, int key, int val) {
    split(rt, key, x, y);
    rt = merge(x, merge(new_node(key, val), y));
}

void build(int u, int l, int r) {
    p[u].l = l, p[u].r = r, p[u].mid = (l + r) >> 1;
    for (int i = l; i <= r; ++i)
        srt[i] = (pair){key[i], val[i]};
    std::sort(srt + l, srt + r + 1);
	for (int i = l; i <= r; ++i) {
        sumd(p[u].sum, val[i]);
		int u = ++cnt; e[u].rnd = rand(), e[u].siz = 1;
		e[u].val = e[u].sum = srt[i].val, e[u].key = srt[i].key;
		while (top && e[u].rnd < e[stk[top]].rnd)
			e[u].ch[0] = stk[top], update(stk[top--]);
		update(u);
		if (top) e[stk[top]].ch[1] = u, update(stk[top]);
		stk[++top] = u;
	}
	while (top) update(stk[top--]);
	p[u].rt = stk[1];
	top = 0;
    if (l == r) return;
    build(u << 1, l, p[u].mid);
    build(u << 1 | 1, p[u].mid + 1, r);
}

void modify(int u, int k, int key, int val, int oldkey, int oldval) {
    erase(p[u].rt, oldkey), insert(p[u].rt, key, val);
    sumd(p[u].sum, val); decd(p[u].sum, oldval);
    if (p[u].l == p[u].r) return;
    if (k <= p[u].mid) modify(u << 1, k, key, val, oldkey, oldval);
    else modify(u << 1 | 1, k, key, val, oldkey, oldval);
}

int query(int u, int l, int r, int key, int val, bool flag) {
    // if (l > r) return 0;
    if (p[u].l == l && p[u].r == r) {
        int &rt = p[u].rt, ret;
        split(rt, key, x, y);
        if (flag) {
            ret = p[u].sum; decd(ret, e[x].sum);
            ret = (ret + (ll)val * e[y].siz) % mod;
        } else {
            ret = e[x].sum;
            ret = (ret + (ll)val * e[x].siz) % mod;
        }
        rt = merge(x, y);
        return ret;
    }
    if (r <= p[u].mid) return query(u << 1, l, r, key, val, flag);
    else if (l > p[u].mid) return query(u << 1 | 1, l, r, key, val, flag);
    else return (query(u << 1, l, p[u].mid, key, val, flag) +
        query(u << 1 | 1, p[u].mid + 1, r, key, val, flag)) % mod;
}

void output(int u) {
    printf("%d[%d %d] ", u, p[u].l, p[u].r);
    dfs(p[u].rt), putchar('\n');
    if (p[u].l == p[u].r) return;
    output(u << 1), output(u << 1 | 1);
}

inline int query(int k, int val) {
    int ret = 0;
    if (1 <= k - 1) sumd(ret, query(1, 1, k - 1, key[k], val, true)); // 大于
    if (k + 1 <= n) sumd(ret, query(1, k + 1, n, key[k] - 1, val, false)); // 小于
    return ret;
}

void main() {
    srand(20040725);
    read(n), read(m);;
    for (int i = 1; i <= n; ++i)
        read(key[i]), read(val[i]);
    build(1, 1, n);
    // std::cerr << clock() / (double)CLOCKS_PER_SEC << std::endl;
    for (int i = 1; i < n; ++i)
        sumd(ans, query(1, i + 1, n, key[i] - 1, val[i], false));
    // std::cerr << clock() / (double)CLOCKS_PER_SEC << std::endl;
    for (int i = 1; i <= m; ++i) {
        read(l), read(r); if (l > r) std::swap(l, r);
		if (l != r) {
			decd(ans, query(l, val[l])); decd(ans, query(r, val[r]));
			std::swap(key[l], key[r]), std::swap(val[l], val[r]);
			modify(1, l, key[l], val[l], key[r], val[r]);
			modify(1, r, key[r], val[r], key[l], val[l]);
			sumd(ans, query(l, val[l])); sumd(ans, query(r, val[r]));
			if (key[l] > key[r]) decd(ans, val[l] + val[r]);
			else sumd(ans, (val[l] + val[r]) % mod);
		}
        print(ans), print('\n');
    }
    // std::cerr << clock() / (double)CLOCKS_PER_SEC << std::endl;
    // std::cerr << cnt << std::endl;
    flush();
}

} signed main() { return ringo::main(), 0; }

// %:pragma GCC optimize(3)
// %:pragma GCC optimize("Ofast")
// %:pragma GCC optimize("inline")
// %:pragma GCC optimize("-fgcse")
// %:pragma GCC optimize("-fgcse-lm")
// %:pragma GCC optimize("-fipa-sra")
// %:pragma GCC optimize("-ftree-pre")
// %:pragma GCC optimize("-ftree-vrp")
// %:pragma GCC optimize("-fpeephole2")
// %:pragma GCC optimize("-ffast-math")
// %:pragma GCC optimize("-fsched-spec")
// %:pragma GCC optimize("unroll-loops")
// %:pragma GCC optimize("-falign-jumps")
// %:pragma GCC optimize("-falign-loops")
// %:pragma GCC optimize("-falign-labels")
// %:pragma GCC optimize("-fdevirtualize")
// %:pragma GCC optimize("-fcaller-saves")
// %:pragma GCC optimize("-fcrossjumping")
// %:pragma GCC optimize("-fthread-jumps")
// %:pragma GCC optimize("-funroll-loops")
// %:pragma GCC optimize("-fwhole-program")
// %:pragma GCC optimize("-freorder-blocks")
// %:pragma GCC optimize("-fschedule-insns")
// %:pragma GCC optimize("inline-functions")
// %:pragma GCC optimize("-ftree-tail-merge")
// %:pragma GCC optimize("-fschedule-insns2")
// %:pragma GCC optimize("-fstrict-aliasing")
// %:pragma GCC optimize("-fstrict-overflow")
// %:pragma GCC optimize("-falign-functions")
// %:pragma GCC optimize("-fcse-skip-blocks")
// %:pragma GCC optimize("-fcse-follow-jumps")
// %:pragma GCC optimize("-fsched-interblock")
// %:pragma GCC optimize("-fpartial-inlining")
// %:pragma GCC optimize("no-stack-protector")
// %:pragma GCC optimize("-freorder-functions")
// %:pragma GCC optimize("-findirect-inlining")
// %:pragma GCC optimize("-fhoist-adjacent-loads")
// %:pragma GCC optimize("-frerun-cse-after-loop")
// %:pragma GCC optimize("inline-small-functions")
// %:pragma GCC optimize("-finline-small-functions")
// %:pragma GCC optimize("-ftree-switch-conversion")
// %:pragma GCC optimize("-foptimize-sibling-calls")
// %:pragma GCC optimize("-fexpensive-optimizations")
// %:pragma GCC optimize("-funsafe-loop-optimizations")
// %:pragma GCC optimize("inline-functions-called-once")
// %:pragma GCC optimize("-fdelete-null-pointer-checks")

// #include <bits/stdc++.h>
// namespace ringo {
// typedef long long ll;

// template < class T >
// inline void read(T &x) {
// 	x = 0; register char c = getchar(); register bool f = 0;
// 	while (!isdigit(c)) f ^= c == '-', c = getchar();
// 	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
// 	if (f) x = -x;
// }

// template < class T >
// inline void print(T x) {
// 	if (x < 0) putchar('-'), x = -x;
// 	if (x > 9) print(x / 10);
// 	putchar('0' + x % 10);
// }

// template < class T >
// inline void print(T x, char c) {
// 	print(x), putchar(c);
// }

// const int N = 5e4 + 10, p = 1e9 + 7;
// int n, m, i, l, r, f[N], g[N], x[N], y[N];
// ll sl, sr, ans;

// inline void add(int x, int y) {
//     while (x) {
//         f[x] += y, ++g[x];
//         x -= x & -x;
//     }
// }
// inline void ask(int x) {
//     sl = sr = 0;
//     while (x <= n) {
//         sl += f[x], sr += g[x];
//         x += x & -x;
//     }
// }

// void main() {
//     read(n), read(m);
//     for (i = 1; i <= n; ++i) {
//         read(x[i]), read(y[i]);
//         ask(x[i]), add(x[i], y[i]);
//         ans += sl + sr * y[i];
//     }
//     while(m--) {
//         read(l), read(r); if(l > r) std::swap(l, r);
//         i = l + 1;
//         while(i < r) {
//             if (x[i] > x[l]) ans += y[i] + y[l];
//             if (x[i] < x[r]) ans += y[i] + y[r];
//             if (x[i] < x[l]) ans -= y[i] + y[l];
//             if (x[i] > x[r]) ans -= y[i] + y[r];
//             ++i;
//         }
//         if (x[l] > x[r]) ans -= y[l] + y[r];
//         if (x[l] < x[r]) ans += y[l] + y[r];
//         std::swap(x[l],x[r]), std::swap(y[l],y[r]);
//         print(ans = (ans % p + p) % p, '\n');
//     }
// }

// } signed main() { return ringo::main(), 0; }
