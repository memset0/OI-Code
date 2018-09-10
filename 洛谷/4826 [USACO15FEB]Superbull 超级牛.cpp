// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll read() {
    ll x = 0; bool m = 0; char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') m = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (m) return -x; else return x;
}

const int maxn = 2010;

ll n, cnt, ans;
ll a[maxn], fa[maxn];

struct edge {
	ll u, v, w;
	edge () {}
	edge (ll a, ll b, ll c) { u = a, v = b, w = c; }
} e[2000010];

bool operator < (edge a, edge b) {
	return a.w > b.w;
}

ll find(ll x) {
	if (fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}

int main() {

	n = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();

	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			e[++cnt] = edge(i, j, a[i] ^ a[j]);
	
	sort(e + 1, e + cnt + 1);
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	
	for (int i = 1; i <= cnt; i++)
		if (find(e[i].u) != find(e[i].v)) {
			fa[find(e[i].u)] = find(e[i].v);
			ans += e[i].w;
		}
	printf("%lld\n", ans);
	
	return 0;
}

