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

const int maxn = 1000010;

int n, max;
int sa[maxn << 1], rnk[maxn << 1], tep[maxn << 1], cnt[maxn << 1];
char s[maxn];

void SuffixSort() {
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= n; i++)
        ++cnt[rnk[i]];
    for (int i = 1; i <= max; i++)
        cnt[i] += cnt[i - 1];
    for (int i = n; i >= 1; i--)
        sa[cnt[rnk[tep[i]]]--] = tep[i];
}

int main() {
//	freopen("INPUT", "r", stdin);
    
    scanf("%s", s + 1), n = strlen(s + 1);
    
    for (int i = 1; i <= n; i++) {
        rnk[i] = s[i];
        tep[i] = i;
    }
    max = 1024;
    SuffixSort();
    for (int len = 1, p = 0; p < n; max = p, len <<= 1) {
        p = 0;
        for (int i = 1; i <= len; i++)
            tep[++p] = n - len + i;
        for (int i = 1; i <= n; i++)
            if (sa[i] > len)
                tep[++p] = sa[i] - len;
//		printf(">>> %d\n", p);
//		for (int i = 1; i <= p; i++) print(tep[i]); putc('\n');
        SuffixSort();
        std::swap(tep, rnk);
        rnk[sa[1]] = p = 1;
        for (int i = 2; i <= n; i++)
            rnk[sa[i]] = (tep[sa[i - 1]] == tep[sa[i]] && tep[sa[i - 1] + len] == tep[sa[i] + len]) ? p : ++p;
// 		for (int i = 1; i <= n; i++) print(sa[i]); putc('\n');
// 		for (int i = 1; i <= n; i++) print(rnk[i]); putc('\n');
// 		for (int i = 1; i <= n; i++) print(tep[i]); putc('\n');
    }
    for (int i = 1; i <= n; i++)
        print(sa[i]);
    putc('\n');

    return 0;
}
