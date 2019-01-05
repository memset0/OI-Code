// luogu-judger-enable-o2
// =================================
//   author: memset0
//   date: 2019.01.04 17:58:59
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

const int N = 8e5 + 10;
int n, m, top, siz, len, val;
ll ans, sum;
int sa[N], rnk[N], tmp[N], tag[N], log[N], tax[N], height[N], st[N][20];
char a[N], b[N], s[N];

struct status {
    int height, val;
    inline ll calc() { return (ll)val * height; }
} stk[N];

inline int ask(int l, int r) {
    int t = log[r - l + 1];
    return std::min(st[l][t], st[r - (1 << t) + 1][t]);
}

void get_sa_sort() {
    for (int i = 1; i <= siz; i++) tax[i] = 0;
    for (int i = 1; i <= len; i++) tax[rnk[i]]++;
    for (int i = 1; i <= siz; i++) tax[i] += tax[i - 1];
    for (int i = len; i >= 1; i--) sa[tax[rnk[tmp[i]]]--] = tmp[i];
}

void get_sa() {
    siz = 300;
    for (int i = 1; i <= len; i++) rnk[i] = s[i], tmp[i] = i;
    get_sa_sort();
    for (int now = 1, cnt = 0; cnt < len; now <<= 1, siz = cnt) {
        cnt = 0;
        for (int i = len; i >= len - now + 1; i--) tmp[++cnt] = i;
        for (int i = 1; i <= len; i++) if (sa[i] > now) tmp[++cnt] = sa[i] - now;
        get_sa_sort(), std::swap(tmp, rnk), rnk[sa[1]] = cnt = 1;
        for (int i = 2; i <= len; i++) rnk[sa[i]] = (tmp[sa[i]] == tmp[sa[i - 1]] && tmp[sa[i] + now] == tmp[sa[i - 1] + now]) ? cnt : ++cnt;
    }
}

void get_height() {
    for (int i = 1, j, ans = 0; i <= len; i++) {
        j = sa[rnk[i] - 1]; if (ans) --ans;
        while (s[i + ans] == s[j + ans]) ++ans;
        height[rnk[i]] = ans;
    }
    for (int i = 1; i <= len; i++) st[i][0] = height[i];
    for (int i = 1; i < 20; i++)	
        for (int j = 1; j + (1 << i) - 1 <= len; j++)
            st[j][i] = std::min(st[j][i - 1], st[j + (1 << (i - 1))][i - 1]);
}

void solve() {
    top = sum = 0;
    for (int i = 2; i <= len; i++) {
        if (!tag[i]) {
            ans += sum;
            // printf(">>> %d : %d\n", i - 1, sum);
        }
        val = tag[i];
        while (top && height[i + 1] <= stk[top].height) {
            val += stk[top].val;
            sum -= stk[top--].calc();
        }
        if (val) sum += (stk[++top] = (status){height[i + 1], val}).calc();
    }
}

void main() {
    scanf("%s%s", a + 1, b + 1), n = strlen(a + 1), m = strlen(b + 1);
    log[0] = -1;
    for (int i = 1; i <= n; i++) s[++len] = a[i];
    s[++len] = 1;
    for (int i = 1; i <= m; i++) s[++len] = b[i];
    get_sa(), get_height();
    for (int i = 1; i <= n; i++) tag[rnk[i]] = 0;
    tag[rnk[n + 1]] = -1;
    for (int i = 1; i <= m; i++) tag[rnk[n + 1 + i]] = 1;
    for (int i = 1; i <= len; i++) log[i] = log[i >> 1] + 1;
    solve();
    // print(ans, '\n');
    for (int i = 1; i <= len; i++) if (~tag[i]) tag[i] ^= 1;
    solve();
    print(ans, '\n');
}

} signed main() { return ringo::main(), 0; }