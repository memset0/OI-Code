// luogu-judger-enable-o2
// luogu-judger-enable-o2
#include <bits/stdc++.h>
#define il inline
#define rg register
#define ll long long
using namespace std;

inline void read(int &x) {
    x = 0; rg char ch; rg bool fl = 0;
    while (ch = getchar(), ch < 48 || 57 < ch) fl ^= ch == '-'; x = (ch & 15);
    while (ch = getchar(), 47 < ch && ch < 58) x = (x << 1) + (x << 3) + (ch & 15);
    if (fl) x = -x;
}
inline void write(int x){
    if (x < 0) x = -x;
    if (x > 9) write(x / 10);
    putchar(x % 10 + 48);
}

const int maxn = 500010, maxm = 200010;
int n, sqn, m, tl, tr, a[maxn], bel[maxm], cnt[1000010];
int now, ans[maxm];
struct Query{
    int l, r, i;
} b[maxm];

il bool cmp(Query &a, Query &b) { return bel[a.l] ^ bel[b.l] ? a.l < b.l : bel[a.l] & 1 ? a.r < b.r : a.r > b.r; }

int main() {
//	freopen("INPUT", "r", stdin);
//	freopen("OUTPUT", "w", stdout);
	freopen("data.txt", "r", stdin);
    
    read(n);
    for (rg int i = 1; i <= n; i++)
        read(a[i]);
    read(m);
    sqn = n / sqrt(m * 2.0 / 3);
//    cout << sqn << endl;
    for (rg int i = 1; i <= n; i++)
        bel[i] = i / sqn;
    for (rg int i = 1; i <= m; i++)
        read(b[i].l), read(b[i].r), b[i].i = i;
    sort(b + 1, b + m + 1, cmp);
    tl = 1, tr = 0;
    for (rg int i = 1; i <= m; i++) {
        while (b[i].l < tl) if (++cnt[a[--tl]] == 1) ++now;
        while (b[i].l > tl) if (--cnt[a[tl++]] == 0) --now;
        while (b[i].r > tr) if (++cnt[a[++tr]] == 1) ++now;
        while (b[i].r < tr) if (--cnt[a[tr--]] == 0) --now;
		printf("%d %d %d %d %d\n", i, b[i].i, b[i].l, b[i].r, now);
        ans[b[i].i] = now;
    }	
    for (rg int i = 1; i <= m; i++)
        write(ans[i]), putchar('\n');
        
    return 0;
}
