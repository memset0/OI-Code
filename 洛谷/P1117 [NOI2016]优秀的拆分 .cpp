// luogu-judger-enable-o2
// =================================
//   author: memset0
//   date: 2019.01.03 12:54:07
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
#define ll long long
namespace ringo {
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
template <class T> inline void print(T x, char c) { print(x), putchar(c); }

const int N = 6e4 + 10;
int T, n;
ll ans;
int tax[N], tmp[N], log[N], a[N], b[N], sum_a[N], sum_b[N];
char s[N];

struct SA {
    int siz, len;
    int sa[N], rnk[N], height[N], st[N][20];
    int min(int l, int r) {
        if (l > r) std::swap(l, r); l++; int t = log[r - l + 1];
        // printf("min %d %d %d : %d %d\n", l, r, t, l, r - (1 << t) + 1);
        return std::min(st[l][t], st[r - (1 << t) + 1][t]);
    }
    void sort() {
        for (int i = 1; i <= siz; i++) tax[i] = 0;
        for (int i = 1; i <= len; i++) tax[rnk[i]]++;
        for (int i = 1; i <= siz; i++) tax[i] += tax[i - 1];
        for (int i = len; i >= 1; i--) sa[tax[rnk[tmp[i]]]--] = tmp[i];
    }
    void build(char *s, int _len) {
        len = _len;
        memset(sa, 0, sizeof(sa));
        memset(rnk, 0, sizeof(rnk));
        memset(tmp, 0, sizeof(tmp));
        memset(height, 0, sizeof(height));
        siz = 200;
        for (int i = 1; i <= len; i++) rnk[i] = s[i], tmp[i] = i;
        sort();
        for (int now = 1, cnt = 0; cnt < len; siz = cnt, now <<= 1) {
            cnt = 0;
            for (int i = len; i >= len - now + 1; i--) tmp[++cnt] = i;
            for (int i = 1; i <= len; i++) if (sa[i] > now) tmp[++cnt] = sa[i] - now;
            sort(), std::swap(rnk, tmp), rnk[sa[1]] = cnt = 1;
            for (int i = 2; i <= len; i++) rnk[sa[i]] = (tmp[sa[i]] == tmp[sa[i - 1]] && tmp[sa[i] + now] == tmp[sa[i - 1] + now]) ? cnt : ++cnt;
        }
        for (int i = 1, j, ans = 0; i <= len; i++) {
            j = sa[rnk[i] - 1]; if (ans) --ans;
            while (s[i + ans] == s[j + ans]) ++ans;
            height[rnk[i]] = ans;
        }
        height[1] = 0;
        for (int i = 1; i <= len; i++) st[i][0] = height[i];
        for (int i = 1; i < 20; i++)
            for (int j = 1; j + (1 << i) - 1 <= len; j++)
                st[j][i] =  std::min(st[j][i - 1], st[j + (1 << (i - 1))][i - 1]);
    }
} f[2];

void main() {
    log[0] = -1;
    for (int i = 1; i <= 30000; i++) log[i] = log[i >> 1] + 1;
    for (read(T); T--; ) {
        ans = 0;
        memset(s, 0, sizeof(s));
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(sum_a, 0, sizeof(sum_a));
        memset(sum_b, 0, sizeof(sum_b));
        scanf("%s", s + 1), n = strlen(s + 1);
        f[0].build(s, n), std::reverse(s + 1, s + n + 1);
        f[1].build(s, n), std::reverse(s + 1, s + n + 1);
        for (int len = 1, A, B, C, D, lcs, lcp; len <= (n >> 1); len++) {
            for (int l = 1, r = l + len; r <= n; l += len, r += len) {
                lcp = f[0].min(f[0].rnk[l], f[0].rnk[r]);
                lcs = f[1].min(f[1].rnk[n - r + 1], f[1].rnk[n - l + 1]);
                if (lcp + lcs < len) continue;
                // printf("[len %d] l %d r %d => lcs %d lcp %d\n", len, l, r, lcs, lcp);
                lcp = std::min(lcp, len), lcs = std::min(lcs, len);
                A = l - lcs + 1, B = r + lcp - (len << 1) + 1;
                C = r + lcp - 1, D = l - lcs + (len << 1) - 1;
                A = std::max(A, 1), B = std::min(B, n + 1);
                C = std::min(C, n), D = std::max(D, 1 - 1);
                sum_a[A]++, sum_a[B]--, sum_b[C]++, sum_b[D]--;
                // printf(">>> %d %d %d %d\n", A, B, C, D);
                // for (int i = 1; i <= n; i++) a[i] = a[i - 1] + sum_a[i];
                // for (int i = n; i >= 1; i--) b[i] = b[i + 1] + sum_b[i];
                // for (int i = 1; i <= n; i++) print(a[i], " \n"[i == n]);
                // for (int i = 1; i <= n; i++) print(b[i], " \n"[i == n]);
            }
        }
        for (int i = 1; i <= n; i++) a[i] = a[i - 1] + sum_a[i];
        for (int i = n; i >= 1; i--) b[i] = b[i + 1] + sum_b[i];
        for (int i = 1; i < n; i++) ans += (ll)b[i] * a[i + 1];
        print(ans, '\n');
        // break;
    }
}

} signed main() { return ringo::main(), 0; }