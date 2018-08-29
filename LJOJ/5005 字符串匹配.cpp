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

const int maxn = 1e6 + 10;
ll n, m, p, q, t, tim;
int f[maxn][26];
char a[maxn], b[maxn];

ll ans;

ll gcd(ll a, ll b) {
	while (a ^= b ^= a ^= b %= a, a);
	return b;
}

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);

	n = read(), m = read();
	scanf("%s%s", a + 1, b + 1);
	p = strlen(a + 1), q = strlen(b + 1);

	tim = gcd(n, m);
	n /= tim, m /= tim;

	t = gcd(p, q);
	for (int i = 1; i <= p; i++)
		f[i % t][a[i] - 'a']++;
	for (int i = 1; i <= q; i++)
		ans += f[i % t][b[i] - 'a'];

	printf("%lld\n", ans * tim);

	return 0;
}