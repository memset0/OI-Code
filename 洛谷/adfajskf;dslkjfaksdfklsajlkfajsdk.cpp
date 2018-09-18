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

int ID;

namespace S1 {
	
const int maxn = 110;
int n, m, u, v, w, l, r;
int x1, x2, k1, k2;
int f[maxn][maxn];
typedef int int_arr[maxn];
int_arr a, b, q;
typedef bool bool_arr[maxn];
bool_arr tag, vis;
typedef vector < int > vt;
vt s1, s2;
int tot = 2, hed[maxn], nxt[maxn << 1], to[maxn << 1];

void full(int x, int k, int *a, vt &s) {
	s.clear();
	s.push_back(x);
	if (!~k) return;
	memset(tag, 0, sizeof(tag));
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= k; i++)
		tag[a[i]] = 1;
	l = r = 1, q[1] = x, vis[x] = 1;
	while (l <= r) {
		u = q[l++];
		for (int i = hed[u]; i; i = nxt[i]) {
			v = to[i];
			if (!vis[v] && !tag[v]) {
				s.push_back(v);
				q[++r] = v;
				vis[v] = 1;
			}
		}
	}
}

int main() {
	memset(f, -1, sizeof(f));
	n = read(), m = read();
	for (int i = 1; i < n; i++) {
		u = read(), v = read(), w = read();
		nxt[tot] = hed[u], to[tot] = v, hed[u] = tot++;
		nxt[tot] = hed[v], to[tot] = u, hed[v] = tot++;
		f[u][v] = f[v][u] = ~f[u][v] && f[u][v] < w ? f[u][v] : w;
	}
	for (int i = 1; i <= m; i++) {
		x1 = read(), k1 = read();
		for (int i = 1; i <= k1; i++) a[i] = read();
		x2 = read(), k2 = read();
		for (int i = 1; i <= k2; i++) b[i] = read();
		w = read();
		full(x1, k1, a, s1);
		full(x2, k2, b, s2);
		for (int i = 0; i < s1.size(); i++)
			for (int j = 0; j < s2.size(); j++) {
				u = s1[i], v = s2[j];
				f[u][v] = ~f[u][v] && f[u][v] < w ? f[u][v] : w;
			}
//		printf("S1 => ");
//		for (int i = 0; i < s1.size(); i++)
//			printf("%d ", s1[i]);
//		puts("");
//		printf("S2 => ");
//		for (int i = 0; i < s2.size(); i++)
//			printf("%d ", s2[i]);
//		puts("");
	}
	for (int i = 1; i <= n; i++)
		f[i][i] = 0;
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (~f[i][k] && ~f[k][j])
					f[i][j] = ~f[i][j] && f[i][j] < f[i][k] + f[k][j] ? f[i][j] : f[i][k] + f[k][j];
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++)
//			printf("%d ", f[i][j]);
//		puts("");
//	}
	for (int i = 1; i <= n; i++)
		printf("%d\n", f[1][i]);
	return 0;
}

}

int main() {
	freopen("../sample/monster/monster8.in", "r", stdin);
//	freopen("../sample/monster/monster1.out", "w", stdout);
//	freopen("monster.in", "r", stdin);
//	freopen("monster.out", "w", stdout);

	ID = read();
	return S1::main();
	
}
