#pragma GCC diagnostic error "-std=c++11"
#pragma GCC target("avx")
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

#include <bits/stdc++.h>
#define il inline
#define rg register
#define ll long long
#define getc getchar
#define putc putchar
#define rep(i, l, r) for (int i = l; i <= r; ++i)
namespace ringo {

template < class T > il void read(T &x) {
    x = 0; rg char c = getc(); rg bool f = 0;
    while (!isdigit(c)) f ^= c == '-', c = getc();
    while (isdigit(c)) x = x * 10 + c - '0', c = getc();
    if (f) x = -x;
}

template < class T > il void print(T x) {
    if (x < 0) putc('-'), x = -x;
    if (x > 9) print(x / 10);
    putc('0' + x % 10);
}

const int N = 1e5 + 5, sqn = 320, M = sqn + 5, P = N / sqn + 5;
int n, m, l, r, l1, l2, r1, r2, siz;
int a[N], rnk[N], srt[N], bln[N], lft[N], rit[N], s[M], q1[M], q2[M], fst[P], cnt[P][N];
ll ans, fur[P], sum[P][P], pre[P][N];
bool tag[M];

void modify(int k) { for (; k <= siz; k += k & -k) ++s[k]; }
int query(int k) { int x = 0; for (; k; k -= k & -k) x += s[k]; return x; }
ll get(int a, int b, int c, int d) { return pre[b][d] - pre[b][c - 1] - pre[a - 1][d] + pre[a - 1][c - 1]; }

int merge(int ll1, int rr1, int ll2, int rr2) {
    int l1 = 1, l2 = 1, r1 = 0, r2 = 0, ans = 0;
    memset(tag, 0, sizeof(tag));
    for (rg int i = ll1; i <= rr1; i++) tag[rnk[i]] = 1;
    for (rg int i = 1; i <= fst[bln[l] + 1] - fst[bln[l]]; ++i)
        if (tag[i]) q1[++r1] = srt[fst[bln[l]] + i - 1];
    memset(tag, 0, sizeof(tag));
    for (rg int i = ll2; i <= rr2; i++) tag[rnk[i]] = 1;
    for (rg int i = 1; i <= fst[bln[r] + 1] - fst[bln[r]]; ++i)
        if (tag[i]) q2[++r2] = srt[fst[bln[r]] + i - 1];
    while (l1 <= r1 && l2 <= r2)
        if (q1[l1] < q2[l2]) ++l1;
        else ++l2, ans += r1 - l1 + 1;
    return ans;
}

void main() {
    read(n), read(m);
    for (rg int i = 1; i <= n; ++i) read(a[i]), srt[i] = a[i];
    for (rg int i = 1; i <= n; ++i) bln[i] = (i - 1) / sqn + 1;
    for (rg int i = 1; i <= bln[n]; ++i) fst[i] = sqn * (i - 1) + 1;
    fst[bln[n] + 1] = n + 1;
    for (rg int i = 1; i <= n; i++) ++cnt[bln[i]][a[i]];
    for (rg int i = 1; i <= bln[n]; i++) for (int j = 1; j <= n; j++)
        cnt[i][j] += cnt[i - 1][j] + cnt[i][j - 1] - cnt[i - 1][j - 1];
    for (rg int i = 1; i <= bln[n]; i++) for (int j = 1; j <= n; j++)
        pre[i][j] = pre[i][j - 1] + cnt[i][a[j] - 1];
    for (rg int r = 1; r <= bln[n]; r++) for (int l = 1; l <= r; l++) {
        for (rg int j = fst[r]; j < fst[r + 1]; j++)
            sum[l][r] += fst[r] - fst[l] - cnt[r - 1][a[j] - 1] + cnt[l - 1][a[j] - 1];
        sum[l][r] += sum[l][r - 1];
    }
    for (rg int i = 1; i <= bln[n]; ++i) {
        siz = fst[i + 1] - fst[i], std::sort(srt + fst[i], srt + fst[i + 1]);
        for (rg int j = fst[i]; j < fst[i + 1]; j++) rnk[j] = std::lower_bound(srt + fst[i], srt + fst[i + 1], a[j]) - srt - fst[i] + 1;
		memset(s, 0, sizeof(s));
        for (rg int j = fst[i]; j < fst[i + 1]; j++) lft[j] = (j == fst[i] ? 0 : lft[j - 1]) + j - fst[i] - query(rnk[j]), modify(rnk[j]);
		memset(s, 0, sizeof(s));
        for (rg int j = fst[i + 1] - 1; j >= fst[i]; j--) rit[j] = (j == fst[i + 1] - 1 ? 0 : rit[j + 1]) + query(rnk[j]), modify(rnk[j]);
        fur[i] = fur[i - 1] + rit[fst[i]];
    }
//	for (int i = 1; i <= n; i++) print(a[i]), putc(i == n ? '\n' : ' '); putc('\n');
//	for (int i = 1; i <= bln[n]; i++) for (int j = 1; j <= n; j++) print(pre[i][j]), putc(j == n ? '\n' : ' '); putc('\n');
//	for (int i = 1; i <= bln[n]; i++) for (int j = 1; j <= n; j++) print(cnt[i][j]), putc(j == n ? '\n' : ' '); putc('\n');
    for (rg int i = 1, bl, br; i <= m; ++i) {
        read(l), read(r);
        l ^= ans, r ^= ans;
        if (l > r) std::swap(l, r);
//		printf("===== %d %d ====\n", l, r);
        if (bln[l] == bln[r]) {
            ans = lft[r] - (l == fst[bln[l]] ? 0 : lft[l - 1]);
            ans -= merge(fst[bln[l]], l - 1, l, r);
        } else {
			bl = bln[l] + 1, br = bln[r] - 1;
            ans = rit[l] + lft[r] + sum[bl][br] - sum[bl][bl - 1] + fur[br] - fur[bl - 1];
            ans += get(bl, br, l, fst[bl] - 1);
            ans -= get(bl, br, fst[br + 1], r);
            ans += (r - fst[br + 1] + 1) * (fst[br + 1] - fst[bl]);
            ans += merge(l, fst[bl] - 1, fst[br + 1], r);
        }
        print(ans), putc('\n');
    }
    std::cerr << clock() / (double)CLOCKS_PER_SEC << std::endl;
}

} signed main() { return ringo::main(), 0; }

//	for (int i = 1; i <= n; i++) print(a[i]), putc(i == n ? '\n' : ' ');
//	for (int i = 1; i <= n; i++) print(bln[i]), putc(i == n ? '\n' : ' ');
//	for (int i = 1; i <= n; i++) print(lft[i]), putc(i == n ? '\n' : ' ');
//	for (int i = 1; i <= n; i++) print(rit[i]), putc(i == n ? '\n' : ' ');
//	for (int i = 1; i <= bln[n]; i++) for (int j = 1; j <= bln[n]; j++)
//		print(sum[i][j]), putc(j == bln[n] ? '\n' : ' ');
