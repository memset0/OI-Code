// luogu-judger-enable-o2
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

const int maxn = 25;
int n, m, n1, n2, ans;
int p[maxn], a[maxn], b[maxn];
bool vis[1 << 20];

struct status {
    int sum, cho;
};
bool operator < (const status &a, const status &b) {
    return a.sum < b.sum;
}

typedef std::vector < status > vetArray;
typedef vetArray ::iterator vetIterator;
vetArray vet;

void plusAns(int sum, int cho) {
    vetIterator l = std::lower_bound(vet.begin(), vet.end(), status{sum, cho});
    vetIterator r = std::upper_bound(vet.begin(), vet.end(), status{sum, cho});
    if (l == r) return;
    for (vetIterator i = l; i != r; i++) {
        int mix = (cho << n1) | (i->cho);
        if (!vis[mix]) {
//			printf(">>> %d %d %d %d %d\n", mix, cho, i->cho, sum, i->sum);
//			for (int i = 1; i <= n; i++)
//				putc(mix & (1 << (i - 1)) ? '1' : '0');
//			putc('\n');
            ans++;
            vis[mix] = 1;
        }
    }
}

void dfs1(int u, int sum, int cho) {
    if (u > n1) {
//		printf("dfs1 %d %d\n", sum, cho);
        vet.push_back(status{sum, cho});
        return;
    }
    dfs1(u + 1, sum + a[u], cho | (1 << (u - 1)));
    dfs1(u + 1, sum - a[u], cho | (1 << (u - 1)));
    dfs1(u + 1, sum, cho);
}

void dfs2(int u, int sum, int cho) {
    if (u > n2) {
//		printf("dfs2 %d %d\n", sum, cho);
        plusAns(-sum, cho);
        return;
    }
    dfs2(u + 1, sum + b[u], cho | (1 << (u - 1)));
    dfs2(u + 1, sum - b[u], cho | (1 << (u - 1)));
    dfs2(u + 1, sum, cho);
}

int main() {
//	freopen("input", "r", stdin);
    read(n);
    for (int i = 1; i <= n; i++)
        read(p[i]);
    n1 = n >> 1, n2 = n - n1;
    for (int i = 1; i <= n1; i++)
        a[i] = p[i];
    for (int i = 1; i <= n2; i++)
        b[i] = p[n1 + i];
    dfs1(1, 0, 0);
    std::sort(vet.begin(), vet.end());
    dfs2(1, 0, 0);
    print(ans - 1, '\n');
    return 0;
}