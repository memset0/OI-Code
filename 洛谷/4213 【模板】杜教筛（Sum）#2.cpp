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

const int N = 10000000;

int t, n;

int miu[N], sum[N], pri[N];
bool vis[N];

map < int, ll > mp;

void init() {

	miu[1] = 1;
	for (int i = 2; i < N; i++) {
		if (!vis[i]) {
			pri[++pri[0]] = i;
			miu[i] = -1;
		}
		for (int j = 1; j <= pri[0] && i * pri[j] <= N; j++) {
			vis[i * pri[j]] = 1;
			if (i % pri[j] == 0) break;
			miu[i * pri[j]] = -miu[i];
		}
	}

	for (int i = 1; i < N; i++)
		sum[i] = sum[i - 1] + miu[i];

}

ll calc_miu(int x) {
	if (x < N)
		return sum[x];
	if (mp.find(x) != mp.end())
		return mp[x];

	ll ans = 1;
	for (int l = 2, r; l <= x; l = r + 1) {
		r = x / (x / l);
		ans -= 1LL * (r - l + 1) * calc_miu(x / l);
	}

	mp[x] = ans;
	return ans;

}

ll calc_phi(int x) {

	ll ans = 0;
	for (int l = 1, r; l <= x; l = r + 1) {
		r = x / (x / l);
		ans += 1LL * (x / l) * (x / l) * (calc_miu(r) - calc_miu(l - 1));
	}
	return (ans + 1) >> 1;

}

int main() {
	// freopen("INPUT", "r", stdin);
	// freopen("OUTPUT", "w", stdout);

	init();

	t = read();
	while (t--) {

		n = read();
		printf("%lld %lld\n", calc_phi(n), calc_miu(n));

	}

	return 0;
}