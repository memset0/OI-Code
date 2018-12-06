// =================================
//   author: memset0
//   date: 2018.12.06 08:36:27
//   website: https://memset0.cn/
// =================================
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

const int N = 3e5 + 10;
int n, m, cnt;
char a[N], b[N];
std::bitset < N > ans, f[26];

void main() {
    scanf("%d%d%s%s", &m, &n, b + 1, a + 1);
    for (int i = 1; i <= n; i++)
        if (a[i] == '*') {
            for (int j = 0; j < 26; j++)
                f[j].set(i);
        } else {
            f[a[i] - 'a'].set(i);
        }
    ans.set();
    for (int i = 1; i <= m; i++)
        if(b[i] != '*') ans &= (f[b[i] - 'a'] >> (i - 1));
    for (int i = 1; i <= n - m + 1; i++)
        if(ans[i] == 1) cnt++;
    print(cnt, '\n');
    for (int i = 1; i <= n - m + 1; i++)
        if (ans[i] == 1) print(i, ' ');
}

} signed main() { return ringo::main(), 0; }
