// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r) for (int i = l; i <= r; i++)

int read() {
	int x = 0; bool m = 0; char c = getchar();
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') m = 1, c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (m) return -x; else return x;
}

const int maxn = 200010, maxm = 500010;

int n, m, u, t, pn, max, sqn;
int a[maxn], b[maxn], miu[maxm], pri[maxn], spl[maxn][10], cnt[maxm];
bool use[maxn], vis[maxm];
ll ans;

void init() {
	
	miu[1] = 1;
	for (int i = 2; i <= max; i++) {
		if (!vis[i]) {
			pri[++pri[0]] = i;
			if (i <= sqn) pn = pri[0];
			miu[i] = -1;
		}
		for (int j = 1; j <= pri[0] && i * pri[j] <= max; j++) {
			vis[i * pri[j]] = 1;
			if (i % pri[j] == 0) break;
			miu[i * pri[j]] = -miu[i];
		}
	}
	
}

void add(int x) {
	printf("add => %d\n", x);
	ans += miu[1] * cnt[1], cnt[1]++;
	for (int i = 1; i <= spl[x][0]; i++) {
		u = spl[x][i];
		printf("add %d %d %d\n", u, miu[u], cnt[u]);
		ans += miu[u] * cnt[u];
		printf(">>> %lld\n", ans);
		cnt[u]++;
	}
}

void del(int x) {
	printf("del => %d\n", x);
	cnt[1]--, ans -= miu[1] * cnt[1];
	for (int i = 1; i <= spl[x][0]; i++) {
		u = spl[x][i];
		printf("del %d %d %d\n", u, miu[u], cnt[u]);
		cnt[u]--;
		ans -= miu[u] * cnt[u];
	}
}

int main() {
//	freopen("gcd.in", "r", stdin);
//	freopen("gcd.out", "w", stdout);
	freopen("3.txt", "r", stdin);
//	freopen("1.txt", "w", stdout);
	
	n = read(), m = read();
	for (int i = 1; i <= n; i++) {
		b[i] = a[i] = read();
		max = std::max(a[i], max);
	}
	sqn = sqrt(max) + 1;
	
	init();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= pn; j++)
			if (b[i] % pri[j] == 0) {
				spl[i][++spl[i][0]] = pri[j];
				while (b[i] % pri[j] == 0)
					b[i] /= pri[j];
			}
		if (b[i] ^ 1) spl[i][++spl[i][0]] = b[i];
	}
	
	for (int i = 1; i <= m; i++) {
		t = read(), use[t] ^= 1;
		if (use[t]) add(t);
		else del(t);
		printf("%lld\n", ans);
	}
	
	return 0;
}
