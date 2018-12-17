#include <iostream>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>

using namespace std;

namespace inout
{
    const int S = 1 << 20;
    char frd[S], *ihed = frd + S;
    const char *ital = ihed;

    inline char inChar()
    {
        if (ihed == ital)
            fread(frd, 1, S, stdin), ihed = frd;
        return *ihed++;
    }

    inline int get()
    {
        char ch; int res = 0; bool flag = false;
        while (!isdigit(ch = inChar()) && ch != '-');
        (ch == '-' ? flag = true : res = ch ^ 48);
        while (isdigit(ch = inChar()))
            res = res * 10 + ch - 48;
        return flag ? -res : res;
    }
};
using namespace inout;

const int Maxn = 0x3f3f3f3f;
const int L = 1e6 + 5;
int n, m, lx, ly, rx, ry;
int c[L], Ans[L];

inline void CkMax(int &x, int y) {if (x < y) x = y;}
inline void CkMin(int &x, int y) {if (x > y) x = y;}

inline void Clear(int x)
{
    for (; x <= ly; x += x & -x)
        if (c[x]) c[x] = 0; 
            else break;
}

inline int Query(int x)
{
    int res = 0;
    for (; x; x ^= x & -x)
        CkMax(res, c[x]);
    return res;
}

inline void Modify(int x, int y)
{
    for (; x <= ly; x += x & -x) 
        CkMax(c[x], y);
}

struct Ask
{
    int x, y, t; bool f;

    Ask() {}
    Ask(const int &X, const int &Y, const int &T, const bool &F):
        x(X), y(Y), t(T), f(F) {}

    inline bool operator < (const Ask &a) const
    {
        return x <= a.x;
    }
}q[L], p[L], a[L];

inline void CDQsolve(int l, int r)
{
    if (l == r) return ;
    int mid = l + r >> 1;
    CDQsolve(l, mid); CDQsolve(mid + 1, r);

    int j = l;
    for (int i = mid + 1; i <= r; ++i)
    if (!p[i].f)
    {
        for (; j <= mid && p[j].x <= p[i].x; ++j) 
            if (p[j].f) Modify(p[j].y, p[j].x + p[j].y);
        int tmp = Query(p[i].y);
        if (tmp) CkMin(Ans[p[i].t], p[i].x + p[i].y - tmp);
    }
    for (int i = l; i < j; ++i)
        if (p[i].f) Clear(p[i].y);

    merge(p + l, p + mid + 1, p + mid + 1, p + r + 1, q + l);
    for (int i = l; i <= r; ++i) p[i] = q[i];
}

inline void Delete()
{
    rx = ry = m = 0;
    for (int i = 1; i <= n; ++i)
        if (!p[i].f) CkMax(rx, p[i].x), CkMax(ry, p[i].y);
    for (int i = 1; i <= n; ++i)
        if (p[i].x <= rx && p[i].y <= ry) q[++m] = p[i];
    for (int i = 1; i <= m; ++i) p[i] = q[i];
}

int main()
{
	freopen("3.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
    n = get(); m = get(); int k, x, y;
    for (int i = 1; i <= n; ++i)
    {
        x = get() + 1; y = get() + 1;
        p[i] = Ask(x, y, i, true);
        CkMax(lx, x); CkMax(ly, y);
    }

    while (m--)
    {
        k = get(); x = get() + 1; y = get() + 1;
        ++n; p[n] = Ask(x, y, n, k & 1);
        CkMax(lx, x); CkMax(ly, y);
    }
    for (int i = 1; i <= n; ++i) a[i] = p[i];

    memset(Ans, Maxn, sizeof(Ans)); ++lx; ++ly;
    Delete(); CDQsolve(1, m);

    for (int i = 1; i <= n; ++i) 
        p[i] = a[i], p[i].x = lx - p[i].x;
    Delete(); CDQsolve(1, m); 

    for (int i = 1; i <= n; ++i)
        p[i] = a[i], p[i].y = ly - p[i].y;
    Delete(); CDQsolve(1, m);

    for (int i = 1; i <= n; ++i) 
        p[i] = a[i], p[i].x = lx - p[i].x, p[i].y = ly - p[i].y;
    Delete(); CDQsolve(1, m); 

    for (int i = 1; i <= n; ++i)
        if (!a[i].f) printf("%d\n", Ans[i]);
    return 0; 
} 
