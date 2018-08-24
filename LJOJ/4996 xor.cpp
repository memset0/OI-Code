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

const int maxn = 50010;
const int mod = 998244353;

int t, n, id, a[maxn];
int f[maxn][64];
ll ans;

vector < int > p[maxn * 32];

#define lowbit(x) ((x)&(-(x)))

void init() {
	ans = 0;
	for (int i = 0; i <= id; i++)
		p[i].clear();
	id = 0;
}

void dfs(int u, int q) {
	if (q == 31) return;
	int L = 0, R = 0;
	for (int i = 0; i < p[u].size(); i++)
		if (p[u][i] & (1 << q)) {
			if (!L) L = ++id;
			p[L].push_back(p[u][i]);
		}
		else {
			if (!R) R = ++id;
			p[R].push_back(p[u][i]);
		}
	if (L && R) {
		ll mul = 1 << q;
		mul = (mul * (ll)(p[L].size())) % mod;
		mul = (mul * (ll)(p[R].size())) % mod;
		ans = (ans + mul) % mod;
	}
	if (L) dfs(L, q + 1);
	if (R) dfs(R, q + 1);
}

int main() {
//	freopen("xor.in", "r", stdin);
//	freopen("xor.out", "w", stdout);
//	freopen("3.txt", "r", stdin);

	t = read();
	for (int I = 1; I <= t; I++) {
		init();
		
		n = read();
		for (int i = 1; i <= n; i++)
			a[i] = read();
		
		id = 1;
		for (int i = 1; i <= n; i++)
			p[1].push_back(a[i]);
		dfs(1, 0);
		
		printf("Case #%d: %lld\n", I, (ans << 1) % mod);
		
	}
	
	return 0;
}
