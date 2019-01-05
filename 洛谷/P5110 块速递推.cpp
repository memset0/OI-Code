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

// =================================
//   author: memset0
//   date: 2018.12.22 07:49:07
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
namespace ringo {
typedef long long ll;
typedef unsigned long long ull;
template <class T> inline void read(T &x) {
    x = 0; register char c = getchar(); register bool f = 0;
    while (!isdigit(c)) f ^= c == '-', c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (f) x = -x;
}
template <class T> inline void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) print(x / 10);
    putchar('0' + x % 10);
}
template <class T> inline void maxd(T &a, T b) { if (b > a) a = b; }
template <class T> inline void mind(T &a, T b) { if (b < a) a = b; }
template <class T> inline void print(T x, char c) { print(x), putchar(c); }
template <class T> inline T abs(const T &a) { if (a < 0) return -a; return a; }

namespace Mker {
    unsigned long long SA, SB, SC;
    void init() { scanf("%llu%llu%llu", &SA, &SB, &SC); }
    unsigned long long rand() {
        SA ^= SA << 32, SA ^= SA >> 13, SA ^= SA << 1;
        unsigned long long t = SA;
        SA = SB, SB = SC, SC ^= t ^ SA; return SC;
    }
}

const int K = 65536, P = 4, p = 1e9 + 7;
int T, sum;
unsigned long long x;

struct vector {
	int a, b;
} ans, temp;

struct matrix {
	int a, b, c, d;
} base, f[P][K];

inline matrix operator * (const matrix &a, const matrix &b) {
    matrix c;
	c.a = ((ll)a.a * b.a + (ll)a.b * b.c) % p;
	c.b = ((ll)a.a * b.b + (ll)a.b * b.d) % p;
	c.c = ((ll)a.c * b.a + (ll)a.d * b.c) % p;
	c.d = ((ll)a.c * b.b + (ll)a.d * b.d) % p;
    return c;
}

void main() {
	read(T), Mker::init();
	base.a = 233, base.c = 666, base.b = 1;
    for (register int p = 0; p < P; p++) {
		f[p][0].a = f[p][0].d = 1;
        for (int k = 1; k < K; k++) f[p][k] = f[p][k - 1] * base;
        base = base * f[p][K - 1];
    }
	vector temp, ans;
    for (register int i = 1; i <= T; i++) {
        x = Mker::rand() % (p - 1); if (!x) continue;
		--x;
		if (x) {
			matrix g = f[0][x % K];
			ans.a = g.a;
			ans.b = g.b;
			x >>= 16;
		}
		if (x) {
			matrix g = f[1][x % K]; temp = ans;
			ans.a = ((ll)temp.a * g.a + (ll)temp.b * g.c) % p;
			ans.b = ((ll)temp.a * g.b + (ll)temp.b * g.d) % p;
			x >>= 16;
		}
		if (x) {
			matrix g = f[2][x % K]; temp = ans;
			ans.a = ((ll)temp.a * g.a + (ll)temp.b * g.c) % p;
			ans.b = ((ll)temp.a * g.b + (ll)temp.b * g.d) % p;
			x >>= 16;
		}
		if (x) {
			matrix g = f[3][x % K]; temp = ans;
			ans.a = ((ll)temp.a * g.a + (ll)temp.b * g.c) % p;
			ans.b = ((ll)temp.a * g.b + (ll)temp.b * g.d) % p;
			x >>= 16;
		}
		sum ^= ans.a;
    }
    print(sum, '\n');
}

} signed main() { return ringo::main(), 0; }
// 18446744073709551615