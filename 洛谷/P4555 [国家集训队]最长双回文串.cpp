// luogu-judger-enable-o2
// =================================
//   author: memset0
//   date: 2018.12.12 10:09:56
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
namespace ringo {
typedef long long ll;

template < class T > inline void read(T &x) {
  x = 0; register char c = getchar(); register bool f = 0;
  while (!isdigit(c)) f ^= c == '-', c = getchar();
  while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
  if (f) x = -x;
}
template < class T > inline void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) print(x / 10);
  putchar('0' + x % 10);
}
template < class T > inline void print(T x, char c) {
  print(x), putchar(c);
}
template < class T > inline void maxd(T &a, T b) { if (b > a) a = b; }
template < class T > inline void mind(T &a, T b) { if (b < a) a = b; }

const int N = 2e5 + 10;
int n, mid, max, ans;
int f[N], l[N], r[N];
char s[N];

void main() {
  memset(l, 63, sizeof(l));
  memset(r, -63, sizeof(r));
  scanf("%s", s + 1), n = strlen(s + 1);
  for (int i = n; i; i--) s[i << 1] = s[i];
  for (int i = 1; i <= n + 1; i++) s[(i << 1) - 1] = '#';
  n = (n << 1) + 1;
  max = 0;
  for (int i = 1; i <= n; i++) {
    f[i] = i <= max ? std::min(f[mid * 2 - i], max - i + 1) : 1;
    while (i + f[i] <= n && i - f[i] >= 1 && s[i + f[i]] == s[i - f[i]]) ++f[i];
    if (i + f[i] - 1 > max) max = i + f[i] - 1, mid = i;
  }
  for (int i = 1; i <= n; i++) mind(l[i + f[i] - 2], i);
  for (int i = 1; i <= n; i++) maxd(r[i - f[i] + 2], i);
  for (int i = n - 3; i >= 2; i -= 2) mind(l[i], l[i + 2]);
  for (int i = 4; i <= n - 1; i += 2) maxd(r[i], r[i - 2]);
  l[0] = l[n + 1] = l[N - 1], r[0] = r[n + 1] = r[N - 1];
  for (int i = 1; i <= n; i += 2) maxd(ans, r[i + 1] - l[i - 1] + 1);
  print(ans - 1, '\n');
}

} signed main() { return ringo::main(), 0; }