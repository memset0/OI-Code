// luogu-judger-enable-o2
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

const int N = 60, M = 1e4;
int n, m, u, v, w, s, e, ans, max, flow, flag;
int id[300], pre[N], dep[N], gap[N], cur[N];
int tot = 2, hed[N], nxt[M], to[M], val[M];

void main() {
	read(m);
	for (int i = 1; i <= 26; i++) id['A' + i - 1] = i;
	for (int i = 1; i <= 26; i++) id['a' + i - 1] = i + 26;
	for (int i = 1, u, v; i <= m; i++) {
		while (u = getchar(), !isalpha(u));
		while (v = getchar(), !isalpha(v));
		u = id[u], v = id[v], read(w), max = std::max(max, u);
		// printf("%d %d %d\n", u, v, w);
		nxt[tot] = hed[u], to[tot] = v, val[tot] = w, hed[u] = tot++;
		nxt[tot] = hed[v], to[tot] = u, val[tot] = 0, hed[v] = tot++;
	}
	s = 1, e = 26, u = s, n = 52, gap[0] = n;
	while (dep[s] < n) {
		// printf(">>> %d\n", u);
		if (u == e) {
			flow = max;
			for (int i = pre[e]; i; i = pre[to[i ^ 1]])
				flow = std::min(flow, val[i]);
			for (int i = pre[e]; i; i = pre[to[i ^ 1]])
				val[i] -= flow, val[i ^ 1] += flow;
			ans += flow, u = s;
		}
		flag = 0;
		for (int &i = cur[u], v = to[i]; i; i = nxt[i], v = to[i])
			if (val[i] && dep[u] == dep[v] + 1) {
				flag = 1, pre[v] = i, u = v;
				break;
			}
		if (!flag) {
			// printf("refresh %d\n", u);
			if (!--gap[dep[u]]) break;
			dep[u] = n;
			for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
				if (val[i] && dep[u] > dep[v] + 1)
					cur[u] = i, dep[u] = dep[v] + 1;
			++gap[dep[u]];
			if (u ^ s) u = to[pre[u] ^ 1];
		}
	}
	print(ans, '\n');
}

} signed main() { return ringo::main(), 0; }