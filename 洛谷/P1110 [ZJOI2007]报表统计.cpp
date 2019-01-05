// luogu-judger-enable-o2
// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int read() {
    int x = 0; bool m = 0; char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') m = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (m) return -x; else return x;
}

int read_opt() {
    char c = getchar();
    while (c != 'I' && c != 'M') c = getchar();
    if (c == 'I') return 1;
    while (c != 'G' && c != 'S') c = getchar();
    if (c == 'G') return 2;
    return 3;
}

const int maxn = 500010;
int n, m, x, y, k, opt, a[maxn];
vector < int > v[maxn];
multiset < int > f, g, t;
multiset < int > ::iterator p, q;

int main() {
//	freopen("INPUT", "r", stdin);
//	freopen("OUTPUT", "w", stdout);
    
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    for (int i = 1; i <= n; i++)
        v[i].push_back(a[i]);
    for (int i = 2; i <= n; i++)
        f.insert(abs(a[i] - a[i - 1]));
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
        t.insert(a[i]);
    for (int i = 2; i <= n; i++)
        g.insert(abs(a[i] - a[i - 1]));
//	for (int i = 1; i <= n; i++)
//		printf("%d ", a[i]);
//	puts("");

    for (int i = 1; i <= m; i++) {
        opt = read_opt();
//		printf(">>> %d\n", opt);
//		for (auto it = f.begin(); it != f.end(); it++)
//			printf("%d ", *it); puts("");
//		for (auto it = g.begin(); it != g.end(); it++)
//			printf("%d ", *it); puts("");
        if (opt == 1) {
            k = read(), x = read();
            y = *--v[k].end();
            v[k].push_back(x);
            f.insert(abs(x - y));
            if (k < n) {
                f.erase(f.find(abs(y - v[k + 1][0])));
                f.insert(abs(x - v[k + 1][0]));
            }
//			printf("%d %d %d\n", x, *t.begin(), *--t.end());
            if (x >= *--t.end()) g.insert(abs(*--t.end() - x));
            else if (x <= *t.begin()) g.insert(abs(*t.begin() - x));
            else {
                p = t.lower_bound(x);
                q = --t.upper_bound(x);
                if (p == q) q++;
//				printf(">> %d %d %d\n", x, *p, *q);
                g.erase(g.find(abs(*p - *q)));
                g.insert(abs(*p - x));
                g.insert(abs(*q - x));
            }
            t.insert(x);
        } else if (opt == 2) {
            printf("%d\n", *f.begin());
        } else {
            printf("%d\n", *g.begin());
        }
    }
    
    return 0;
}