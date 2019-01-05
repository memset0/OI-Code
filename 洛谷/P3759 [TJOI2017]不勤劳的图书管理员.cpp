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

#include <bits/stdc++.h>
namespace ringo {
typedef long long ll;

template < class T >
inline void read(T &x) {
	x = 0; register char c = getchar(); register bool f = 0;
	while (!isdigit(c)) f ^= c == '-', c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (f) x = -x;
}

template < class T >
inline void print(T x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) print(x / 10);
	putchar('0' + x % 10);
}

template < class T >
inline void print(T x, char c) {
	print(x), putchar(c);
}

const int N = 5e4 + 10, p = 1e9 + 7;
int n, m, i, l, r, f[N], g[N], x[N], y[N];
ll sl, sr, ans;

inline void add(int x, int y) {
    while (x) {
        f[x] += y, ++g[x];
        x -= x & -x;
    }
}
inline void ask(int x) {
    sl = sr = 0;
    while (x <= n) {
        sl += f[x], sr += g[x];
        x += x & -x;
    }
}

void main() {
    read(n), read(m);
    for (i = 1; i <= n; ++i) {
        read(x[i]), read(y[i]);
        ask(x[i]), add(x[i], y[i]);
        ans += sl + sr * y[i];
    }
    while(m--) {
        read(l), read(r); if(l > r) std::swap(l, r);
        i = l + 1;
        while(i < r) {
            if (x[i] > x[l]) ans += y[i] + y[l];
            if (x[i] < x[r]) ans += y[i] + y[r];
            if (x[i] < x[l]) ans -= y[i] + y[l];
            if (x[i] > x[r]) ans -= y[i] + y[r];
            ++i;
        }
        if (x[l] > x[r]) ans -= y[l] + y[r];
        if (x[l] < x[r]) ans += y[l] + y[r];
        std::swap(x[l],x[r]), std::swap(y[l],y[r]);
        print(ans = (ans % p + p) % p, '\n');
    }
}

} signed main() { return ringo::main(), 0; }