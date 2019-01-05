// =================================
//   author: memset0
//   date: 2018.12.10 19:23:51
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

const int N = 1e5 + 10;
int n, m, u, v, cntn, cnte, flag, cnt[3], vis[N], col[N];
int tot = 2, hed[N], to[N << 1], nxt[N << 1], val[N << 1];
ll ans;

void dfs(int u) {
	vis[u] = 1, ++cntn, ++cnt[col[u]];
  for (int i = hed[u], v, c; i; i = nxt[i]) {
    v = to[i], c = (col[u] + val[i] + 3) % 3;
    ++cnte;
    if (vis[v]) {
      if (col[v] != c) flag = true;
      continue;
    }
    col[v] = c, dfs(v);
  }
}

void main() {
  read(n), read(m);
  for (int i = 1; i <= m; i++) {
    read(u), read(v);
    nxt[tot] = hed[u], to[tot] = v, val[tot] =  1, hed[u] = tot++;
    nxt[tot] = hed[v], to[tot] = u, val[tot] = -1, hed[v] = tot++;
  }
  for (int i = 1; i <= n; i++)
    if (!vis[i]) {
			cnt[0] = cnt[1] = cnt[2] = cntn = cnte = flag = 0;
      dfs(i);
			// printf("%d %d %d %d %d %d\n", cnt[0], cnt[1], cnt[2], cntn, cnte, flag);
      if (flag) ans += (ll)cntn * cntn;
			else {
        if (cnt[0] && cnt[1] && cnt[2]) {
          ans += (ll)cnt[0] * cnt[1];
          ans += (ll)cnt[0] * cnt[2];
          ans += (ll)cnt[1] * cnt[2];
        } else ans += cnte >> 1;
      } 
    }
		print(ans, '\n');
}

} signed main() { return ringo::main(), 0; }